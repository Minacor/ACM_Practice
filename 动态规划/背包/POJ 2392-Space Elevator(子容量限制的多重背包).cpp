/*
 * 题意：
 * 给一堆砖块砌墙，每一种砖块有高度h和数量num，其位置最高的砖块不能超过mh
 * 问能砌成最多多高的墙
 *
 * 思路：
 * 首先多重背包无疑
 * 每一种砖块都有其限制高度，所以对每一种砖，其背包容量就是其高度上限mh
 * 所以只要套用多重背包模板时动态改变背包容量就行了
 * 并且由于dp对前一状态的依赖性，砖块应该根据mh从小到大排列
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

struct node
{
    int h,mh,num;
    bool operator < (const node& b)const
    {
        return mh < b.mh;
    }

}block[410];

int dp[40100];

int main()
{
    FR;
    int k;
    while(~scanf("%d",&k))
    {
        memset(dp , 0 , sizeof dp);

        for(int i = 0 ; i < k ; i++)
        {
            scanf("%d%d%d",&block[i].h,&block[i].mh,&block[i].num);
        }
        sort(block,block+k);

        for(int i = 0  ;i < k ; i++)
        {
            if(block[i].num*block[i].h >= block[i].mh)
            {
                for(int j = block[i].h ; j <= block[i].mh ; j++)
                        dp[j] = max(dp[j],dp[j-block[i].h]+block[i].h);
            }
            else
            {
                int x = 1;
                while(x < block[i].num)
                {

                    for(int j = block[i].mh ; j >= x*block[i].h ; j--)
                            dp[j] = max(dp[j] , dp[j-x*block[i].h] + x*block[i].h);

                    block[i].num -= x;
                    x *= 2;
                }

                 for(int j = block[i].mh ; j >= block[i].num*block[i].h ; j--)
                        dp[j] = max(dp[j] , dp[j-block[i].num*block[i].h] + block[i].num*block[i].h);

            }

        }

        printf("%d\n",*max_element(dp,dp+MAX));     //注意是在整个数组中寻找最值
    }

    return 0;
}
