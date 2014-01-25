/*
 * 题意：
 * 多组数据，每组数据第一行输入初始资金money和投资年数year
 * 第二行可选的股票数n
 * n行，每股股票的购买资金c和一年能获得的利润w
 *
 * 问year年后能获得的最大利润，后一年的本金是前一年的本金+获得利润
 *
 * 思路：
 * 股票可以买无限股，明显一个完全背包问题，背包容量是每年年初的本金
 *
 * 特别注意的是股票价格是1000的倍数，所以可以将每年初始资金v和股票价格都除以1000再dp，否则会T
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

int dp[50000+100];
int t,n;

struct node
{
    int c;
    int w;
}pro[15];

int cptpack(int v)
{
    v/=1000;
    for(int i = 0 ; i < n ; i++)
        for(int j = pro[i].c/1000 ; j <= v ; j++)               //注意仅仅j+=1000是错的！！
            dp[j] = max(dp[j] , dp[j-pro[i].c/1000] + pro[i].w);
    return dp[v];
}

int main()
{
    int t;
    scanf("%d",&t);

    int money,year;
    while(t--)
    {
        memset(dp,0,sizeof dp);
        scanf("%d%d",&money,&year);
        scanf("%d",&n);

        for(int i = 0 ; i < n ; i++)
            scanf("%d%d",&pro[i].c,&pro[i].w);
        while(year--)
        {
            money += cptpack(money);
        }

        printf("%d\n",money);
    }

    return 0;
}
