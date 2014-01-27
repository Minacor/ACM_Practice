/*
 * 题意：
 * 数据：
 * 第一行数据组数
 * 第二行三个数：光碟数n 店主要求必须买到的光碟数m(不能多也不能少) 规定不能超过的总时间l
 * 接下来n行，每行两个数：
 * 本光碟的时长 本光碟的价值
 *
 * 要求输出恰好买m张碟时，总时间不超过l下的价值最多的方案的价值数
 *
 * 思路：
 * 典型的01二维背包，买的碟数和时间作为两个背包容量
 * 本题要注意的是初始化方法
 *
 * 背包九讲里提到过：要求恰好装满背包，那么在初始化时除了F[0] 为0，其它
 * F[1::V ] 均设为负无穷，这样就可以保证最终得到的F[V] 是一种恰好装满背包的最优解。
 * 如果并没有要求必须把背包装满，而是只希望价格尽量大，初始化时应该将F[0...V]
 * 全部设为0。
 *
 * 本题要求碟数一定是m，也就是说恰好装满背包，所以代表碟数的数组，除头初始化为0以外其余初始化为负无穷
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

int dp[1100][110];

int main()
{
    //FR;
    int t;
    scanf("%d",&t);

    while(t--)
    {
        for(int i = 0 ; i < 1100 ; i++)
        {
            for(int j = 0 ; j < 110 ; j++)
                dp[i][j]= -inf;
            dp[i][0]=0;
        }

        int n,m,l;
        scanf("%d%d%d",&n,&m,&l);

        for(int i = 0 ; i < n ; i++)
        {
            int time,val;
            scanf("%d%d",&time,&val);

            for(int j = l ; j >= time ; j--)
                for(int k = m ; k >= 1 ; k--)
                    dp[j][k] = max(dp[j][k],dp[j-time][k-1]+val);
        }

        printf("%d\n",dp[l][m] > 0 ? dp[l][m] : 0);
    }

    return 0;
}
