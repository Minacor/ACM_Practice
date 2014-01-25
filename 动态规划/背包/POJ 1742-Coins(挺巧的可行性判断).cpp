/*
 * 题意：
 * 有若干面值的钱币，每种钱币一定数量
 * 求这些钱币能组合成的1~m之间的整数个数
 *
 * 思路：
 * 刚开始用多重背包可行性爆内存了，改用一种比较巧妙的dp
 * dp[i]表示i这种情况有没有被组合出来过
 * sum[i]表示在组合出i这种情况下，当前钱币被用了几次
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

int n,m;

struct node
{
    int v;
    int num;
}coin[110];

int dp[100000+10] , num[100000+10];

int can(int m)
{
    memset(dp,0,sizeof dp);

    dp[0] = 1;

    int cnt=0;
    for(int i = 1 ; i <= n ; i++)
    {
        memset(num,0,sizeof num);
        for(int j = coin[i].v ; j <= m ; j++)
        {
            //只有j-c.v这种情况已被组合出来才有可能加上当前的钱币得到j
            //且当前情况j没有被组合出来才能计数，避免重复
            //最后要判断一下这种钱币在当前情况下是否还有剩余
            if(!dp[j] && dp[j-coin[i].v] && num[j-coin[i].v] < coin[i].num)
            {
                num[j] = num[j-coin[i].v]+1;
                dp[j] = dp[j-coin[i].v] + coin[i].v;    //令dp[j]为正数就可以了
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    //FR;
    while(~scanf("%d%d",&n,&m) && (m||n))
    {
        for(int i = 1 ; i <= n ; i++)
            scanf("%d",&coin[i].v);
        for(int i = 1 ; i <= n ; i++)
            scanf("%d",&coin[i].num);

        printf("%d\n",can(m));
    }

    return 0;
}


