/*
 题目大意：
有一个天平，天平左右两边各有若干个钩子，总共有C个钩子，有G个钩码，求将钩码全部挂到钩子上使天平平衡的方法的总数。
其中可以把天枰看做一个以x轴0点作为平衡点的横轴
输入：
2 4 //C 钩子数 与 G钩码数
-2 3 //负数：左边的钩子距离天平中央的距离；正数：右边的钩子距离天平中央的距离c[k]
3 4 5 8 //G个重物的质量w[i]


dp思路：
每向天平中方一个重物，天平的状态就会改变，而这个状态可以由若干前一状态获得。

首先定义一个平衡度j的概念
当平衡度j=0时，说明天枰达到平衡，j>0，说明天枰倾向右边（x轴右半轴），j<0则相反
那么此时可以把平衡度j看做为衡量当前天枰状态的一个值
因此可以定义一个 状态数组dp[i][j]，意为在挂满前i个钩码时，平衡度为j的挂法的数量。
由于距离c[i]的范围是-15~15，钩码重量的范围是1~25，钩码数量最大是20
因此最极端的平衡度是所有物体都挂在最远端，因此平衡度最大值为j=15*20*25=7500。原则上就应该有dp[ 1~20 ][-7500 ~ 7500 ]。
因此为了不让下标出现负数，做一个处理，使使得数组开为 dp[1~20][0~15000]，则当j=7500时天枰为平衡状态

那么每次挂上一个钩码后，对平衡状态的影响因素就是每个钩码的 力臂
力臂=重量 *臂长 = w[i]*c[k]
那么若在挂上第i个砝码之前，天枰的平衡度为j
   (换言之把前i-1个钩码全部挂上天枰后，天枰的平衡度为j)
则挂上第i个钩码后，即把前i个钩码全部挂上天枰后，天枰的平衡度 j=j+ w[i]*c[k]
   其中c[k]为天枰上钩子的位置，代表第i个钩码挂在不同位置会产生不同的平衡度

不难想到，假设 dp[i-1][j] 的值已知，设dp[i-1][j]=num
               （即已知把前i-1个钩码全部挂上天枰后得到状态j的方法有num次）
   那么dp[i][ j+ w[i]*c[k] ] = dp[i-1][j] = num
(即以此为前提，在第k个钩子挂上第i个钩码后，得到状态j+ w[i]*c[k]的方法也为num次)

想到这里，利用递归思想，不难得出 状态方程dp[i][ j+ w[i]*c[k] ]= ∑（dp[i-1][j]）

结论：
最终转化为01背包问题
状态方程dp[i][ j+ w[i]*c[k] ]= ∑（dp[i-1][j]）
初始化：dp[0][7500] = 1;   //不挂任何重物时天枰平衡，此为一个方法

复杂度O(C*G*15000)  完全可以接受
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

int dp[25][30000];  //dp[i][j]表示使用前i个砝码后平衡度为j的方法数
int c[25],g[25];

int main()
{
    //FR;
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        memset(dp,0,sizeof dp);
        dp[0][7500]=1;

        for(int i = 1 ; i <= n ; i++)
            scanf("%d",c+i);
        for(int j = 1 ; j <= m ; j++)
            scanf("%d",g+j);

        for(int i = 1; i <= m ; i++)
        {
            for(int j = 0 ; j <= 15000 ; j++)
            {
                if(dp[i-1][j])  //只有之前的被计算过，后面的计数才有意义
                    for(int k = 1 ; k <= n ; k++)
                        dp[i][j+c[k]*g[i]] +=dp[i-1][j];
            }
        }

        printf("%d\n",dp[m][7500]);
    }

    return 0;
}
