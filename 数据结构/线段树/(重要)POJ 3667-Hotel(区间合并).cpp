/*
 * 题意：
 * 第一行两个数n，q，表示有连续n个房间和q个询问
 * 接下来q行询问，询问有两种形式
 * 1）：1 d ，把连续d个客人安排进客房，要求客房不能有人，并且从最左端开始安排，若能够安排，输出从哪个房间开始安排的，否则输出0
 * 2）：2 a b ， 把a~a+b-1房间中的客人清除
 *
 * 思路：
 * 经典的线段树区间合并
 * 对于一个区间[l,r]
 * lsum:从区间最左端开始能够连续安排客人的最大数量
 * rsum:从区间最右端开始(往左)能够连续安排客人的最大数量
 * msum:整个区间中能够连续安排客人的最大数量
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
const int MAX = 50000+10;
const int inf = 522133279;
const int mod = 1000000007;

int n,q;

struct seg  //区间中每一个点，若是1则当前房间是空的，是0表示当前房间有客
{
    int l,r;
    int lsum , rsum , msum;
    int has;    //延迟标记has:三种值(-1,0,1)，-1表示不需要操作区间，0表示需要把当前区间置空，1表示需要把当前区间安排满客人
}tree[8*MAX];

void build(int root , int l , int r)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].lsum = tree[root].rsum = tree[root].msum = r-l+1;    //初始时房间都是空的
    tree[root].has=-1;      //初始延迟标记

    if(l==r) return;

    int mid = MID(l,r);

    build(lson(root),l,mid);
    build(rson(root),mid+1,r);
}

void pushdown(int root)//向下更新
{
    if(tree[root].has!=-1)  //如果当前区间需要被更改
    {
        tree[lson(root)].has = tree[rson(root)].has=tree[root].has; //子区间也要做相同的更改，标记上延迟标记
        // 更改相应子区间，如果has为0，则需要把房间清空，也就是子区间表示的房间都能住人了，把子区间的三个sum全改成子区间长度，反之改为0
        tree[lson(root)].lsum = tree[lson(root)].msum = tree[lson(root)].rsum = tree[root].has? tree[lson(root)].r-tree[lson(root)].l+1:0;
        tree[rson(root)].lsum = tree[rson(root)].msum = tree[rson(root)].rsum = tree[root].has? tree[rson(root)].r-tree[rson(root)].l+1:0;
        tree[root].has=-1;  //将当前区间改为不可操作状态
    }
}

void pushup(int root)   //向上更新
{
    //首先让父区间的lsum=左子区间的lsum，父区间的rsum=右子区间的rsum，这显然一定成立
    tree[root].lsum = tree[lson(root)].lsum;
    tree[root].rsum = tree[rson(root)].rsum;

    //然后看看能不能扩展(增大)父区间的三个sum值
    //如果左区间房间全是空的，那么就可以接上右区间的lsum
    if(tree[root].lsum == tree[lson(root)].r-tree[lson(root)].l+1)
        tree[root].lsum += tree[rson(root)].lsum;
    //同理，如果右区间的房间全是空的，那么就可以接上左区间的rsum
    if(tree[root].rsum == tree[rson(root)].r-tree[rson(root)].l+1)
        tree[root].rsum += tree[lson(root)].rsum;
    //区间最大连续可安排房间msum的值就是max(左区间的rsum+右区间的lsum(这个是没被计算过的),左区间的msum，右区间的msum)
    tree[root].msum = max(tree[lson(root)].rsum+tree[rson(root)].lsum,max(tree[lson(root)].msum,tree[rson(root)].msum));
}

void modify(int root , int l , int r , int state)       //普通的更新操作
{
    if(tree[root].l >= l && tree[root].r <= r)
    {
        //目标区间包含当前区间，把当前区间按state清空或安排满客
        tree[root].lsum=tree[root].rsum=tree[root].msum = (state? tree[root].r-tree[root].l+1:0);
        //延迟标记，子区需做相同更改
        tree[root].has=state;
        return ;
    }

    //先向下更新一层，然后处理下一层，然后返回上来时更新父区间
    pushdown(root);
    int mid = MID(tree[root].l,tree[root].r);
    if(mid >= l)
        modify(lson(root),l,r,state);
    if(mid < r)
        modify(rson(root),l,r,state);
    pushup(root);
}

int query(int root , int d)     //寻找最左端的可安排位置
{
    if(tree[root].msum < d)     //如果当前区间的最大可安排连续房间数小于目标值，那么一定安排不了，返回题目要求的0值
        return 0;
    if(tree[root].l==tree[root].r)  //如果是叶子节点了，且可安排，那么就是这一个节点的位置
        return tree[root].l;

    //如果不是叶子节点，先利用pushdown向下更新一层
    pushdown(root);

    //寻找的顺序：当前区间的最左端，不行的话就找当前区间的中间段，再不行的话就寻找最右端
    if(tree[root].lsum >= d)        //最左端，可行的话就返回l
        return tree[root].l;
    if(tree[lson(root)].msum >= d)  //不行的话，就递归找"左区间中间区间的最左端"
        return query(lson(root),d);
    if(tree[lson(root)].rsum+tree[rson(root)].lsum >= d)    //左区间整段不行的话，就找两区间衔接段
        return tree[lson(root)].r-tree[lson(root)].rsum+1;
    return query(rson(root),d);             //都不行的话，对右区间进行同样的操作
}

int main()
{
    //FR;
    while(~scanf("%d%d",&n,&q))
    {
        clr(tree,0);
        build(1,1,n);
        while(q--)
        {
            int op;
            scanf("%d",&op);

            if(op == 1)
            {
                int d,res;
                scanf("%d",&d);
                printf("%d\n",res=query(1,d));
                if(res) modify(1,res,res+d-1,0);    //最后一个参数state，0表示本段区间被安排满客
            }
            else
            {
                int a,b;
                scanf("%d%d",&a,&b);
                modify(1,a,a+b-1,1);    //1表示本段区间全被清空
            }
        }
    }
    return 0;
}
