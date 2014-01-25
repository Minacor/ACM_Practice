/*
 * 题意：
 * 有一个w*h的矩阵里面有一些树，用一个s*t的框去框这个矩阵
 * 求所有框出的子矩阵的树的数量的最大值
 *
 * 思路：
 * 二维树状数组直接暴力解决
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
const int inf = 1e15;

int n;
int tree[110][110];
int w,h;

int lowbit(int t)
{
    return t&-t;
}

void modify(int x,int y)
{
    for(int i = x ; i <= w ; i+=lowbit(i))
        for(int j = y ; j <= h ; j += lowbit(j))
        {
            tree[i][j]++;
        }
}

int getsum(int x,int y)
{
    int t=0;
    for(int i = x ; i > 0 ; i-=lowbit(i))
        for(int j = y ; j > 0 ; j -= lowbit(j))
        {
            t += tree[i][j];
        }
    return t;
}

int main()
{
    FR;
    while(~scanf("%d",&n) && n)
    {
        memset(tree,0,sizeof tree);
        scanf("%d%d",&w,&h);
        for(int i = 0 ; i < n ; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            modify(x,y);
        }

        int sx,sy;
        scanf("%d%d",&sx,&sy);
        int maxc = -1;
        for(int i = 0 ; i + sx<= w ; i++)
            for(int j = 0 ; j + sy <= h ; j++)
                maxc = max(maxc , getsum(i+sx,j+sy) - getsum(i+sx,j)-getsum(i,j+sy)+getsum(i,j));
        printf("%d\n",maxc);
    }

    return 0;
}
