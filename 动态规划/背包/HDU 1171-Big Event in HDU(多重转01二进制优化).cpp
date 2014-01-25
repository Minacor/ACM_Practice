/*
 * 题意：
 * 有一堆东西有各自的值和数量，要求把这些东西分成两堆，使得他们的总值尽可能接近
 *
 * 思路:
 * 多种数量规定的物品，完全背包，本题价值W == 耗费空间C
 * 二进制优化，复杂度O(V∑logMi)
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
const int inf = 50000000;

int n;
int a[5100],w[5100];            //a保存权值，w保存物品的数量
int dp[25000*20+1000];

int main()
{
    int v,m;
    //FR;
    while(~scanf("%d",&n) && n >= 0)
    {
        int sum=0;
        memset(dp , 0  ,sizeof dp);

        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d%d",&a[i],&w[i]);
            sum += a[i]*w[i];
        }

        for(int i = 0 ; i < n ; i++)
        {
            if(a[i]*w[i] >= sum/2)
                for(int j = a[i] ; j <= sum/2 ; j++)        //完全背包
                    dp[j] = max(dp[j],dp[j-a[i]]+a[i]);
            else
            {
                int k=1;
                while(k < w[i])
                {
                    for(int j = sum/2 ; j>= k*a[i];j--)     //01背包
                        dp[j] = max(dp[j],dp[j-k*a[i]]+k*a[i]);
                    w[i] -= k;
                    k *= 2;
                }
                for(int j = sum/2 ; j>= w[i]*a[i];j--)      //01背包
                        dp[j] = max(dp[j],dp[j-w[i]*a[i]]+w[i]*a[i]);
            }
        }

        printf("%d %d\n" , sum - dp[sum/2] , dp[sum/2]);

    }

    return 0;
}
