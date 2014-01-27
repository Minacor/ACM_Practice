/*
 * 题意：
 * 主人公要在m天内修若干门课，这些课花不同天数有不同的收益
 * 最后要求收益最大
 *
 * 思路：
 * 同一门课只能上一次，也就是说在这门课的不同时间中最多只能选一个时间
 * 分组背包
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

int n,m;
int v[110][110];
int dp[110];

int main()
{
    //FR;
    while(~scanf("%d%d",&n,&m) && (n||m))
    {
        memset(dp,0,sizeof dp);

        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= m ; j++)
                scanf("%d",&v[i][j]);

        for(int k = 1 ; k <= n ; k++)           //分成的组数
            for(int i = m ; i >= 0 ; i--)       //背包容量 逆序注意
                for(int j = i ; j >= 1; j--)        //当前组中的每一个元素，这里注意会超过总天数的就不要列入循环内了，所以j从i开始
                    dp[i] = max(dp[i],dp[i-j]+v[k][j]);

        printf("%d\n",dp[m]);
    }

    return 0;
}
