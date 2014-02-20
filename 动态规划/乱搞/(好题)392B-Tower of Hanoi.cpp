/*
 * 题意：
 * 汉诺塔加强版，除了塔之间的移动有权值以外，其余的规则都与汉诺塔一样
 *
 * 思路：
 * dp[x][i][j] 表示i堆上前x个移动到j所花费的最小值
 * x=1的时候相当于folyd预处理
 */

#include "iostream"
#include "cstring"
const int inf = 522133279;
typedef long long LL;
using namespace std;

LL dp[50][3][3];
int g[3][3];

int main()
{
    int n;
    for(int i = 0 ; i < 3 ; i++)
        for(int j = 0 ; j < 3 ; j++)
            cin >> g[i][j];
    cin >> n;

    for(int x = 1 ; x <= n ; x++)
        for(int i = 0 ; i < 3 ; i++)
            for(int k = 0 ; k < 3 ; k++)
            {
                if(i==k) {dp[x][i][k]=0;continue;}
                int j = 3-i-k;

                //前x-1个塔组成的塔堆移动到另一个塔有两种移动方法
                LL fi = dp[x-1][i][j]+g[i][k]+dp[x-1][j][k];
                LL se = dp[x-1][i][k]+g[i][j]+dp[x-1][k][i]+g[j][k]+dp[x-1][i][k];

                dp[x][i][k] = min(fi,se);
            }

    cout << dp[n][0][2] << endl;
    return 0;

}
