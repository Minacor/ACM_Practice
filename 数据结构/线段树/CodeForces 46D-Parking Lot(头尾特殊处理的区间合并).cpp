/*
 * 题意：
 * 有一个停车场，车停入的时候，和屁股后面的车相距>=b，和前面的车相距>=f，但是在停车场的边界(即前面没车或者后面没车时)并不需要空出距离
 * 现在给定停车场距离L和b,f
 * 然后n个询问
 * 询问有两种形式:
 * 1 len ：表示长度为len的车要停入停车场，能停就输出车屁股的位置，若停不了就输出-1(假设停车场是左到右的布局，那么停车时一律车头向右)
 * 2 id : 表示把第id个命令里停进去的车开掉(这里千万注意不是开走第id辆车！！题目已经保证了id第id个命令一定是2并且一定能停车，所以大大简化了)
 *
 * 思路：
 * 最经典的区间合并，只不过建树时按照(-b,L+f)来建以免对车停在边界的判断，query的时候找的就是最左边的符合连续b+L+f的可用区间，其余的就是区间合并模板
 */
#include "iostream"
#include "cstring"
#include "algorithm"
#include "cmath"
#include "cstdio"
#include "sstream"
#include "queue"
#include "vector"
#include "string"
#include "stack"
#include "cstdlib"
#include "deque"
#include "fstream"
#include "map"
#include "set"
#define lson(x) (x<<1)
#define rson(x) (x<<1|1)
#define MID(x,y) ((x+y)>>1)
#define FR (freopen("in.txt","r",stdin))
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int L,b,f,n;

struct ccar
{
    int pos;
    int len;
};

ccar car[110];

struct seg
{
    int l;
    int r;
    int lsum;
    int rsum;
    int msum;
    int lazy;       //1 清除 0 放置
}tree[3*MAX];

void pushdown(int root)
{
    if(tree[root].lazy!=-1)
    {
        tree[lson(root)].lazy= tree[rson(root)].lazy=tree[root].lazy;
        tree[lson(root)].lsum = tree[lson(root)].rsum = tree[lson(root)].msum = tree[root].lazy ? tree[lson(root)].r-tree[lson(root)].l+1 : 0;
        tree[rson(root)].lsum = tree[rson(root)].rsum = tree[rson(root)].msum = tree[root].lazy ? tree[rson(root)].r-tree[rson(root)].l+1 : 0;
        tree[root].lazy=-1;
    }
}

void pushup(int root)
{
    tree[root].lsum = tree[lson(root)].lsum;
    tree[root].rsum = tree[rson(root)].rsum;

    if(tree[root].lsum == tree[lson(root)].r-tree[lson(root)].l+1)
        tree[root].lsum += tree[rson(root)].lsum;
    if(tree[root].rsum == tree[rson(root)].r-tree[rson(root)].l+1)
        tree[root].rsum += tree[lson(root)].rsum;
    tree[root].msum = max(tree[lson(root)].rsum+tree[rson(root)].lsum , max(tree[lson(root)].msum , tree[rson(root)].msum));
}

void build(int root , int l , int r)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].lazy=-1;
    tree[root].lsum = tree[root].rsum = tree[root].msum=r-l+1;

    if(l==r) return;

    int mid(MID(l,r));
    build(lson(root),l,mid);
    build(rson(root),mid+1,r);
}

void modify(int root , int l , int r , int state)
{
    if(tree[root].l >= l && tree[root].r <= r)
    {
        tree[root].lsum = tree[root].rsum = tree[root].msum = state ? tree[root].r-tree[root].l+1 : 0;
        tree[root].lazy=state;
        return ;
    }

    if(tree[root].l==tree[root].r)
        return ;

    pushdown(root);
    int mid = MID(tree[root].l,tree[root].r);

    if(mid >= l)
        modify(lson(root),l,r,state);
    if(mid < r)
        modify(rson(root),l,r,state);
    pushup(root);
}

int query(int root , int v)
{
    if(tree[root].msum < v)
        return -inf;
    if(tree[root].l==tree[root].r)
        return tree[root].l;

    pushdown(root);
    if(tree[root].lsum >= v)
        return tree[root].l;
    if(tree[lson(root)].msum >= v)
        return query(lson(root),v);
    if(tree[lson(root)].rsum+tree[rson(root)].lsum >= v)
        return tree[lson(root)].r-tree[lson(root)].rsum+1;
    return query(rson(root),v);
}

int main()
{
    //FR;
    cin >> L >> b >> f;
    cin >> n;
    build(1,-b,L+f-1);
    for(int i = 1 ; i <= n ; i++)
    {
        int op,num;
        cin >> op >> num;

        if(op==1)
        {
            int res=query(1,num+b+f)+b;     //+b以输出实际位置
            if(res < -100000) res=-1;
            printf("%d\n",res);

            if(res!=-1)
            {
                ccar tmp;
                tmp.len = num,tmp.pos = res;
                car[i]=tmp;
                modify(1,res,res+num-1,0);
            }
        }
        else
            modify(1,car[num].pos,car[num].pos + car[num].len-1 , 1);
    }
    return 0;
}
