/*
 * 题意:
 * 初始有n个排成一排的村庄，现有下列操作：
 * D pos ：破坏pos村庄
 * Q pos ：输出和pos村庄相连的未被破坏的村庄有几个（包括自己）
 * R 修复最近破坏的村庄
 *
 * 思路：
 * 将破坏的村庄记为0，未破坏的为1，这样每次询问就是问包含pos位置的最大连续1序列的长度，典型线段树区间合并
 * 每次破坏村庄就把村庄压入栈中，这样栈顶就是最近被破坏的村庄
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


int n,q;
struct seg
{
    int l,r;
    int lsum , rsum , msum;
    int has;
}tree[8*MAX];

void build(int root , int l , int r)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].lsum = tree[root].rsum = tree[root].msum = r-l+1;
    tree[root].has=-1;

    if(l==r) return;

    int mid = MID(l,r);

    build(lson(root),l,mid);
    build(rson(root),mid+1,r);
}

void pushdown(int root)//向下更新
{
    if(tree[root].has!=-1)
    {
        tree[lson(root)].has = tree[rson(root)].has=tree[root].has;
        tree[lson(root)].lsum = tree[lson(root)].msum = tree[lson(root)].rsum = tree[root].has? tree[lson(root)].r-tree[lson(root)].l+1:0;
        tree[rson(root)].lsum = tree[rson(root)].msum = tree[rson(root)].rsum = tree[root].has? tree[rson(root)].r-tree[rson(root)].l+1:0;
        tree[root].has=-1;
    }
}

void pushup(int root)   //向上更新
{
    tree[root].lsum = tree[lson(root)].lsum;
    tree[root].rsum = tree[rson(root)].rsum;

    if(tree[root].lsum == tree[lson(root)].r-tree[lson(root)].l+1)
        tree[root].lsum += tree[rson(root)].lsum;

    if(tree[root].rsum == tree[rson(root)].r-tree[rson(root)].l+1)
        tree[root].rsum += tree[lson(root)].rsum;

    tree[root].msum = max(tree[lson(root)].rsum+tree[rson(root)].lsum,max(tree[lson(root)].msum,tree[rson(root)].msum));
}

void modify(int root , int l , int r , int state)       //普通的更新操作
{
    if(tree[root].l >= l && tree[root].r <= r)
    {
        tree[root].lsum=tree[root].rsum=tree[root].msum = (state? tree[root].r-tree[root].l+1:0);
        tree[root].has=state;
        return ;
    }
    pushdown(root);
    int mid = MID(tree[root].l,tree[root].r);
    if(mid >= l)
        modify(lson(root),l,r,state);
    if(mid < r)
        modify(rson(root),l,r,state);
    pushup(root);
}

int query(int root , int pos)       //寻找包含pos的最大连续1的长度
{
    if(tree[root].l <= pos && tree[root].l+tree[root].lsum-1 >= pos)    //pos包含在当前区间的lsum内
        return tree[root].lsum;
    if(tree[root].r >= pos && tree[root].r-tree[root].rsum+1 <= pos)    //pos包含在当前区间的rsum内
        return tree[root].rsum;

    if(tree[root].l==tree[root].r) return 0;

    if(tree[lson(root)].r-tree[lson(root)].rsum+1 <= pos &&         //pos包含在当前区间的中间段，由于msum不好确定位置，故用左子区间rsum+右子区间lsum来确定
       tree[rson(root)].l+tree[rson(root)].lsum-1 >= pos)
       return tree[lson(root)].rsum+tree[rson(root)].lsum;

    int mid = MID(tree[root].l,tree[root].r);
    if(mid >= pos)
        return query(lson(root),pos);
    if(mid < pos)
        return query(rson(root),pos);
}

int main()
{
    //FR;
    while(~scanf("%d %d",&n,&q))
    {
        stack<int> huai;
        getchar();
        build(1,1,n);
        while(q--)
        {
            char op;int num;
            scanf("%c",&op);
            getchar();

            if(op == 'D')
            {
                scanf("%d",&num);getchar();
                modify(1,num,num,0),huai.push(num);
            }
            else if(op == 'Q')
            {
                scanf("%d",&num);getchar();
                cout << query(1,num) << endl;
            }
            else
            {
                int cur = huai.top();
                huai.pop();
                modify(1,cur,cur,1);
            }
        }
    }
    return 0;
}
