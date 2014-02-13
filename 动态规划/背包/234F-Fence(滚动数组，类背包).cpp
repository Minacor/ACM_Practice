/*
 * 题意：
 * 给两种颜色能涂的面积数a,b和一群篱笆x1~xn，每个篱笆的宽为1,高为xi,每个篱笆涂一种颜色
 * 相邻篱笆间有一个值ans，若这两个篱笆颜色相同则为0，否则为min(xi,xj)
 * 输出使ans和最小的答案，不能涂则输出-1
 *
 * 思路：
 * dp[i][j][k] :前i个篱笆用了j面积a颜色，且当前颜色是k(0:a 1:b)颜色时的最小ans和
 * 由于i<=200,j<=40000,k<2 且递推方程只与前一状态有关，故使用滚动数组
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
#define MID(x,y) ((x+y)>>1)
#define FR (freopen("in.txt","r",stdin))
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int n;
int dp[2][40000][2];
int a,b;
int lis[210];
int sum;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n;
    cin >> a>>b;
    for(int i = 1 ; i <= n ; i++)
        cin >> lis[i],sum+=lis[i];

    clr(dp[0],-1);  //初始化为不可达状态-1
    dp[0][0][0] = dp[0][0][1]=0;    //0个篱笆0 a颜色用量时ans和就是0
                                    //且由于lis[0]=0,故min(lis[0],lis[1])=0,不需要初始化1个篱笆时的dp值
    int gun=0;
    for(int i = 1 ; i <= n ; i++)
    {
        gun=1-gun;
        clr(dp[gun],-1);        //注意每次使用都要初始化为不可达状态

        for(int j = 0 ; j <= a ; j++)       //类背包处理，要注意相同颜色时ans不需计算，不同颜色时才要算上min(xi,xj)
        {
            if(dp[1-gun][j][0] != -1)
            {
                if(dp[gun][j+lis[i]][0] == -1 || dp[gun][j+lis[i]][0]>dp[1-gun][j][0])
                    dp[gun][j+lis[i]][0] = dp[1-gun][j][0];
                if(dp[gun][j][1] == -1 || dp[gun][j][1]>dp[1-gun][j][0]+min(lis[i],lis[i-1]))
                    dp[gun][j][1]=dp[1-gun][j][0]+min(lis[i],lis[i-1]);
            }

            if(dp[1-gun][j][1] != -1)
            {
                if(dp[gun][j][1] == -1 || dp[gun][j][1]>dp[1-gun][j][1])
                    dp[gun][j][1] = dp[1-gun][j][1];
                if(dp[gun][j+lis[i]][0] == -1 || dp[gun][j+lis[i]][0]>dp[1-gun][j][1]+min(lis[i],lis[i-1]))
                    dp[gun][j+lis[i]][0]=dp[1-gun][j][1]+min(lis[i],lis[i-1]);
            }
        }
    }

    int ans=-1;
    //此时的gun为末状态
    for(int i = 0 ; i <=a ; i++)
        if(sum-i <= b)
        {
            if(dp[gun][i][0] != -1 && (ans==-1 || ans > dp[gun][i][0]))
                ans = dp[gun][i][0];
            if(dp[gun][i][1] != -1 && (ans==-1 || ans > dp[gun][i][1]))
                ans = dp[gun][i][1];
        }
    cout << ans << endl;
    return 0;
}
