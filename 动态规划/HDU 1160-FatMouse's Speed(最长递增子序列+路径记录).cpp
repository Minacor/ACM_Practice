/*
 * 题意：
 * 给一群老鼠，每一行表示老鼠的质量 速度
 * 找到最多的一组老鼠，使得体重严格递增，速度严格递减
 *
 * 思路：
 * 将体重优先从小到大排序(相等则速度从大到小排序)，找最大递减子序列，记录路径
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

struct node
{
    int id;
    int w;
    int s;

    bool operator < (const node& b)const
    {
        return w == b.w ? s > b.s : w < b.w;
    }
}mice[10000+100];

int dp[10000+100],pre[10000+100],order[10000+100];//pre记录最大递减子序列路径，由于最后要输出原id，故要再设一个映射order

int main()
{
    //FR;
    int n=1;
    while(~scanf("%d%d",&mice[n].w,&mice[n].s))
        mice[n].id = n,n++;
    sort(mice+1,mice+n);

    int maxc = 0,pos=0;
    fill(dp,dp+10000,1);

    for(int i = 1 ; i < n ; i++)        //最大递减子序列
    {
        for(int j = i ; j >= 1 ; j--)
        //要注意题目要求两者都是严格递增/递减的，所以判断速度时不要将体重相同的判断进去
            if(mice[j].w < mice[i].w && mice[j].s > mice[i].s && dp[j]+1 > dp[i])
                dp[i]=dp[j]+1 , pre[i]=j;   //当前子序列中，j是紧邻i的前面一个元素

        if(maxc < dp[i])
            maxc = dp[i] , pos=i;   //记录最后一个元素的位置
    }

    for(int i = 1 ; i <= maxc ; i++) //从最后一个元素开始回溯路径，压入输出队列
    {
        order[i] = pos;
        pos = pre[pos];
    }

    printf("%d\n",maxc);
    for(int i = maxc ; i >= 1 ; i--)    //输出排序前的这个元素的id
        printf("%d\n",mice[order[i]].id);

    return 0;
}

