/*
 * 题意：
 * 数据：
 * 第一行数据组数
 * 每组数据第一行：空储钱罐的重量，装了若干钱后的重量
 * 第二行钱币种数
 * 之后几行描述每一种钱币(数量无限)：钱币面值 钱币重量
 * 问是否能装入若干种钱币使得储钱罐恰好是给定重量，如果可能，输出最小面值总和
 *
 * 思路：
 * 完全背包不解释
 * 把重量看做空间消耗，目标重量看做背包容量，钱币面值看做价值，这就是一个判断背包可行性，并且求最小价值的简单问题
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
const int MAX = 40000;
const int inf = 522133279;

int t;
int dp[11000];

int main()
{
    //FR;
    scanf("%d",&t);
    while(t--)
    {
        int tx,ty;
        scanf("%d%d",&tx,&ty);
        int up = ty-tx;
        int n;
        scanf("%d",&n);

        //求最小价值的初始化方法
        memset(dp,0x1f,sizeof dp);
        dp[0]=0;

        for(int i = 0 ; i < n ; i++)
        {
            int c,w;
            scanf("%d%d",&w,&c);
            for(int j = c ; j <= up ; j++)
                dp[j] = min(dp[j],dp[j-c]+w);
        }

        //如果目标容量未被更新，当然表示此状态不可达
        if(dp[up] != inf)
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[up]);
        else
            puts("This is impossible.");
    }

    return 0;
}
