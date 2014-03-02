/*
 * 题意：
 * 给一个高为h，宽为w的矩形，和n个高为1，宽为wi的小矩形
 * 现在要把这些矩形按给定顺序放置在大矩形内，优先选择最顶端的可放位置，然后优先选择这个可放位置的最左端的可放位置
 * 如果能放下这个小矩形，输出放置在哪一行，否则输出-1
 *
 * 思路：
 * 根据放置规则，用线段树维护高度(l,r)内的每一行可放长度的最大值，然后先找遍左子树，看看有没有可以安放的
 * 有的话则更新
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
const int MAX = 200000+100;
const int inf = 522133279;
const int mod = 1000000007;

int t;
int h,w;
int n;
int rr;
int ok;

struct seg      //v表示第l行到第r行的所有行的最大可放长度
{
    LL l;
    LL r;
    LL v;
}tree[3*MAX];

LL build(int root , int l , int r)
{
    tree[root].l=l;
    tree[root].r=r;

    if(l==r)
        return tree[root].v=w;

    int mid =MID(l,r);

    return tree[root].v = max(build(lson(root),l,mid),build(rson(root),mid+1,r));

}

void query(int root,LL v)
{
    if(tree[root].l == tree[root].r && tree[root].v >= v)
    {
        ok=1;
        printf("%I64d\n",tree[root].l);
        tree[root].v -= v;
        return ;
    }

    if(tree[root].v < v)
        return ;

    if(!ok) query(lson(root),v);
    if(!ok) query(rson(root),v);

    tree[root].v = max(tree[lson(root)].v,tree[rson(root)].v);  //别忘记更新最大值，否则就T了
}

int main()
{
    while(~scanf("%d%d%d",&h,&w,&n))
    {
        clr(tree,0);
        rr = min(h,n);
        build(1,1,rr);

        for(int i = 0 ; i < n ; i++)
        {
            int v;
            scanf("%d",&v);
            ok=0;
            query(1,v);
            if(!ok) puts("-1");
        }
    }

    return 0;
}
