/*
 * 题意：中文题略
 *
 * 思路：线段树写法
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
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;

int a[50000+100];
int n;

struct seg
{
    int l,r;
    int sum;
}tree[50000*5+100];

int build(int root ,int l,int r)
{
    int mid;

    tree[root].l=l;
    tree[root].r=r;

    if(l==r)
    {
        return tree[root].sum = a[l];
    }

    mid = (l+r)/2;

    return tree[root].sum = build(2*root,l,mid)+build(2*root+1,mid+1,r);
}

int getsum(int root , int l , int r)
{
    int mid;
    if(tree[root].l==l && tree[root].r==r)
    {
        return tree[root].sum;
    }

    mid = (tree[root].l+tree[root].r)/2;

    if(l > mid)                             //如果目标区间在当前mid值的右边，就往右子树找，反之往左子树找，不然就同时找
        return getsum(root*2+1,l,r);
    else if (r <= mid)                      //这个等号十分重要 ， 如果等号不在这或者在上一句，那么根据这棵线段树的build规则(兄弟区间，左区间内容>=右区间内容)，会在else if中出现mid>r的情况，导致崩溃
        return getsum(root*2,l,r);
    else
        return getsum(root*2,l,mid) + getsum(root*2+1,mid+1,r);
}

int update(int root , int pos , int delta)          //更新直接定位点即可
{
    if(tree[root].l==pos && tree[root].r == pos)
        return tree[root].sum += delta;

    if(tree[root].l > pos || tree[root].r < pos)
    {
        return tree[root].sum;
    }

    return tree[root].sum = update(root*2,pos,delta) + update(root*2+1,pos,delta);
}

int main()
{
    int t;
    scanf("%d",&t);

    for(int ka = 1 ; ka <= t ; ka++)
    {
        memset(tree,0,sizeof(tree));

        scanf("%d",&n);

        for(int i = 1 ; i <= n ; i++)
            scanf("%d",a+i);

        build(1,1,n);

        char cmd[10];
        printf("Case %d:\n",ka);

        while(~scanf("%s",cmd) && cmd[0] != 'E')
        {
            int x,y;
            scanf("%d%d",&x,&y);

            switch(cmd[0])
            {
                case 'Q':
                    printf("%d\n",getsum(1,x,y)); break;
                case 'A':
                    update(1,x,y); break;
                case 'S':
                    update(1,x,-y); break;
            }
        }


    }

    return 0;
}
