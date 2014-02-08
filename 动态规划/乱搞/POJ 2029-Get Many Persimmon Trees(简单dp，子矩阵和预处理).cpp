/*
 * 题意：
 * 有一个w*h的矩阵里面有一些树，用一个s*t的框去框这个矩阵
 * 求所有框出的子矩阵的树的数量的最大值
 *
 * 思路：
 * 简单dp，预处理出矩阵(1,1,x,y)内的树的总数，然后利用子矩阵计数法求出，此题也有树状数组版本
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

int g[110][110];
int dp[110][110];       //表示矩阵(1,1,x,y)内树的总数
int n;
int w,h;

int main()
{
    //FR;
    while(~scanf("%d", &n) && n)
    {
        memset(g,0,sizeof g);
        memset(dp,0,sizeof dp);
        scanf("%d%d",&w,&h);
        for(int i = 0 ; i < n ; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a][b]=1;
        }
        for(int i = 1 ; i <= w ; i++)
            for(int j = 1 ; j <= h ; j++)       //转移方程画个图就明白了
                dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+g[i][j];
        int maxc=-1;
        int sx,sy;
        scanf("%d%d",&sx,&sy);
        for(int i = 0 ; i+sx<= w ; i++)
            for(int j = 0 ; j+sy <= h ; j++)    //子矩阵计数法，等同于二维树状数组的子矩阵计数
                maxc = max(maxc , dp[i+sx][j+sy]-dp[i][j+sy]-dp[i+sx][j]+dp[i][j]);
        printf("%d\n",maxc);
    }
    return 0;
}
