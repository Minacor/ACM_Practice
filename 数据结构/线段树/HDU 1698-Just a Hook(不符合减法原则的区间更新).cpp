/*
 * 题意：
 * 给一串初始值全为1的数字串，X Y Z表示把下标X—Y的值全改为Z，求所有操作之后的所有数字之和
 *
 * 思路：
 * 线段树的区间更新，不符合减法原则的更新只能使用线段树
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
const int MAX = 100000+100;
const int inf = 522133279;
const int mod = 1000000007;

int t;
int n;

struct seg
{
    int l;
    int r;
    int v;
    int sum;

    void ca(int tmp)
    {
        v = tmp;
        sum = (r-l+1)*v;
    }
}tree[3*100000+100];

void build(int root , int l , int r)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].ca(1);

    if(l==r)
        return;

    int mid =MID(l,r);

    build(lson(root) , l , mid);
    build(rson(root),mid+1,r);
}

void modify(int root , int l , int r , int v)
{
    if(l <= tree[root].l && r >= tree[root].r)
    {
        tree[root].ca(v);
        return ;
    }

    if(tree[root].r < l || tree[root].l > r)
        return ;

    if(tree[root].v)
    {
        tree[lson(root)].ca(tree[root].v);
        tree[rson(root)].ca(tree[root].v);
        tree[root].v=0;
    }

    int mid = MID(tree[root].l,tree[root].r);
    if(l <= mid)
        modify(lson(root),l,r,v);
    if(r > mid)
        modify(rson(root),l,r,v);
    tree[root].sum = tree[lson(root)].sum + tree[rson(root)].sum;
}

int main()
{
    scanf("%d",&t);

    for(int ka = 1 ; ka <= t ; ka++)
    {
        clr(tree,0);
        int m;
        scanf("%d%d",&n,&m);
        build(1,1,n);

        while(m--)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            modify(1,a,b,c);
        }

        printf("Case %d: The total value of the hook is %d.\n",ka,tree[1].sum);
    }
    return 0;
}
