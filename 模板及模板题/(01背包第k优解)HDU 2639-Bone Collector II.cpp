/*
 * 01背包第k优解模板题
 *
 * 题意：
 * 第一行数据组数
 * 每组数据第一行三个数：物品总数n 背包总容量m 第k优的解
 * 第二行各物品的价值
 * 第三行各物品的大小
 *
 * 求第k优解，如果解的数量不足k则输出0，并且一样的解算同一情况
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

int t;
int dp[1100][35];           //dp[i][j]表示容量为i的背包中的第k优解
int que1[35],que2[35];      //合并用，其大小为k
int c[110],w[110];

int main()
{
    //FR;
    int n,m,k;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        memset(dp,0,sizeof dp);
        memset(que1,0,sizeof que1);
        memset(que2,0,sizeof que2);

        for(int i = 1 ; i <= n ; i++)
            scanf("%d",w+i);
        for(int j = 1 ;j <= n ; j++)
            scanf("%d",c+j);

        for(int i = 1 ; i <= n ; i++)       //外层两个循环和01背包一样
        {
            for(int j = m ; j >= c[i] ; j--)
            {
                for(int x = 1 ; x <= k ; x++)   //对"第x优解"
                {
                    que1[x] = dp[j][x];
                    que2[x] = dp[j-c[i]][x] + w[i];
                }
                que1[k+1]=que2[k+1]=-1;

                int pos1=1,pos2=1,x=1;
                while(x<=k && (que1[pos1]!=-1 || que2[pos2]!=-1))
                {
                    //用大的覆盖
                    dp[j][x] = que1[pos1] > que2[pos2] ? que1[pos1++] : que2[pos2++];

                    if(dp[j][x] != dp[j][x-1])  //题目要求严格第k优解，所以相同的不能算新的解
                        x++;
                }
            }
        }

        printf("%d\n",dp[m][k]);
    }

    return 0;
}
