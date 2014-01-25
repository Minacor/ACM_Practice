/*
 * 题意：
 * 有1,2,3,4,5,6六种值的大理石，输入6个数是每种大理石的数量
 * 问能不能把大理石分成值相同的两堆
 *
 * 思路：
 * 多重背包二进制优化不解释
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

int rest[10];
int dp[120000];

int main()
{
    FR;
    int sum;
    int t=0;

    while(1)
    {
        sum=0;
        memset(dp,0,sizeof dp);

        for(int i = 1 ; i <= 6 ; i++)
        {
            int n;
            scanf("%d",&n);
            rest[i] = n;
            sum += n*i;
        }
        if(!sum)
            break;
        int ok=0;

        if(!(sum%2))
        {
            sum/=2;
            for(int i = 1 ; i <= 6 ; i++)
            {
                if(i*rest[i] >= sum)
                    for(int j = i ; j <= sum ; j++)
                        dp[j] = max(dp[j],dp[j-i]+i);
                else
                {
                    int k=1;
                    while(k < rest[i])
                    {
                        for(int j = sum ; j >= k*i ; j--)
                            dp[j] = max(dp[j],dp[j-k*i]+k*i);
                        rest[i]-=k;
                        k*=2;
                    }
                    for(int j = sum ; j >= rest[i]*i ; j--)
                        dp[j] = max(dp[j],dp[j-rest[i]*i]+rest[i]*i);

                }
            }

            ok = dp[sum] == sum;
        }

        if(!ok)
            printf("Collection #%d:\nCan't be divided.\n\n",++t);
        else
            printf("Collection #%d:\nCan be divided.\n\n",++t);
    }

    return 0;
}

