/*
 * 题意：
 * 给六种货币的面值，每种货币无限数量
 * 问组成1~100每种情况的最少货币数的平均值（可加可减），并输出其中的最大值
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
const int inf = 522133297;

int dp[20000];
int a[20];
int MAX=1000;

int main()
{
    //FR;
    int t;
    scanf("%d",&t);

    while(t--)
    {
        memset(dp,0,sizeof dp);
        for(int i = 0 ; i < 6 ; i++)
            scanf("%d",&a[i]);

        //求最小值的初始化
        for(int i = 0 ; i < MAX ; i++)
            dp[i] = inf;
        dp[0]=0;

        //先计算不找钱的
        for(int i = 0 ; i < 6 ; i++)
            for(int j = a[i] ; j <= MAX ; j++)
                dp[j] = min(dp[j],dp[j-a[i]]+1);

        //找钱的，第二个循环逆序
        for(int i = 0 ; i < 6 ; i++)
            for(int j = MAX-a[i] ; j >= 0 ; j--)
                dp[j] = min(dp[j],dp[j+a[i]]+1);

        int maxc =-1 , sum=0;
        for(int i = 1 ; i <= 100 ; i++)
        {
            maxc = max(maxc,dp[i]);
            sum+=dp[i];
        }

        printf("%.2lf %d\n",1.0*sum/100 , maxc);
    }

    return 0;
}
