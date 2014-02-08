/*
 * 题意：
 * 给一个四面体，其顶点分别为A,B,C,D，一只蚂蚁从D出发要走n步(每次经过顶点)再回到D，问有几种走法
 *
 * 思路：
 * 将顶点A,B,C,D编号为0,1,2,3
 * 令dp[i][j] 表示走了i步以后，且当前所在顶点编号是j的走法种数
 * 则转移方程很容易想出来，即 dp[i][j] = ∑dp[i-1][k] , k!=j , 表示是从k顶点走到j的
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
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 200000+100;
const int inf = 522133279;
const int mod = 1000000007;

int dp[10000000+100][5];
int n;

int main()
{
    cin >> n;
    clr(dp,0);
    dp[0][0]=dp[1][1]=dp[1][2]=dp[1][3]=1;
    for(int i = 2 ; i <= n ; i++)
        for(int j = 0 ; j < 4 ; j++)
            for(int k = 0 ; k < 4 ; k++)
                dp[i][j] = (dp[i][j] +  (j==k ? 0 : dp[i-1][k])) % mod;
    printf("%d\n",dp[n][0] % mod);
    return 0;
}
