/*
 * 题意：
 * 输入：
 * 第一个数t组数据
 * 每组数据第一行三个数：能剪成的布的种类n 大布的长和宽X,Y
 * 接下来n行每行三个数： 能剪成的布的长和宽x，y，这块布的价值c
 * 求大布剪成小布能获得的最大价值
 *
 * 思路：
 * 一块大布能剪成不限数量的小布，故这是一个完全背包问题
 * dp方程表示要不不裁，要不就有两种裁法
 * 两种裁法的图示 http://www.2cto.com/kf/201303/198648.html
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
const int MAX = 1000;
const int inf = 522133279;

struct node
{
    int x,y,c;
}a[20];

int dp[1100][1100];
int n,X,Y;

int main()
{
    FR;
    int t;
    scanf("%d",&t);

    while(t--)
    {
        memset(dp,0,sizeof dp);
        scanf("%d%d%d",&n,&X,&Y);

        for(int i = 0 ; i < n ; i++)
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);

//        for(int i = 1 ; i <= n ; i++)       注意最朴素的完全背包外层循环和内层循环顺序可以调换，但这里不可以
//        {
            for(int tx = 0 ; tx <= X ; tx++)        //由于小布是可以旋转的，也即i*j可以当做j*i计算，所以这里索性从0开始，在内部详细判断
                for(int ty = 0 ; ty <= Y ; ty++)
                {
                    for(int i = 0 ; i < n ; i++)
                    {
                        if(tx >= a[i].x && ty >= a[i].y)    //如果当前枚举到的布能够裁出小布a[i]来
                            dp[tx][ty] = max(dp[tx][ty],max(dp[tx-a[i].x][ty]+dp[a[i].x][ty-a[i].y]+a[i].c , dp[tx-a[i].x][a[i].y]+dp[tx][ty-a[i].y]+a[i].c));
                        if(tx >= a[i].y && ty >= a[i].x)    //如果当前枚举到的布能够裁出a[i]旋转90°后的小布来
                            dp[tx][ty] = max(dp[tx][ty],max(dp[tx-a[i].y][ty]+dp[a[i].y][ty-a[i].x]+a[i].c , dp[tx-a[i].y][a[i].x]+dp[tx][ty-a[i].x]+a[i].c));
                    }
                }
//        }

        printf("%d\n",dp[X][Y]);
    }

    return 0;
}
