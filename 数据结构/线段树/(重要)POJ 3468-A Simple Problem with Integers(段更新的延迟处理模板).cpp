/*
 * 题意：给定一个序列 ， Q a b表示求出[a,b]区间的和，C a b c表示将[a,b]内的所有数都加上c
 *
 * 思路：线段树做法，注意延迟处理
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
#define FR (freopen("in.txt","r",stdin))
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;

int num[100000+100];
int n,q;

struct seg
{
    int l,r;
    LL sum;
    LL delta;

    void ca(LL tmp)
    {
        delta += tmp;       //注意延迟记号是累加的
        sum += (r-l+1)*tmp;
    }

}tree[100000*3 + 100];

LL build(int root , int l , int r)
{
    tree[root].l=l;
    tree[root].r=r;

    if(l == r)
        return tree[root].sum = num[l];

    int mid = (l+r) >> 1;

    return tree[root].sum = build(root<<1 , l,mid) + build(root<<1|1 , mid+1,r);
}

void modify(int root , int l ,int r , LL delta)
{
    if(tree[root].r <= r && tree[root].l >= l)
    {
        tree[root].ca(delta);
        return;
    }

    if(tree[root].delta)                                  //延迟处理
    {
        tree[root<<1].ca(tree[root].delta);
        tree[root<<1|1].ca(tree[root].delta);
        tree[root].delta=0;
    }

    int mid = (tree[root].l + tree[root].r)>>1;

    if(mid >= l)
        modify(root << 1 , l , r , delta);
    if(mid < r)
        modify(root << 1|1 , l , r , delta);

    tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
}

LL getsum(int root , int l , int r)
{
    if(tree[root].l == l && tree[root].r == r)
        return tree[root].sum;

    if(tree[root].delta)
    {
        tree[root<<1].ca(tree[root].delta);
        tree[root<<1|1].ca(tree[root].delta);
        tree[root].delta=0;
    }

    int mid = (tree[root].l+tree[root].r) >> 1;

    if(mid < l)
        return getsum(root << 1|1 , l,r);
    else if(mid >= r)
        return getsum(root << 1 , l,r);
    else
        return getsum(root << 1 , l , mid) + getsum(root << 1|1 , mid+1,r);
}

int main()
{
    //FR;
   while( ~scanf("%d%d",&n,&q))
   {
        getchar();

        for(int i = 1 ; i <= n ; i++)
            scanf("%d",num+i);
        getchar();

        build(1,1,n);

        char qes;
        int a,b,c;

        while(q--)
        {
            scanf("%c",&qes);
            getchar();

            if(qes == 'Q')
            {
                scanf("%d%d",&a,&b);
                printf("%I64d\n",getsum(1,a,b));
            }
            else
            {
                scanf("%d%d%d",&a,&b,&c);
                modify(1,a,b,c);
            }
            getchar();
        }
    }
    return 0;
}
