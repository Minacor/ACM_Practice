/*
 * 题意：
 * 给一个药水序列，牛只能按顺序喝，但可以跳过某些药水不喝
 * 从1开始计数，奇数次喝的时候增加其跳跃能力，偶数次减少
 * 初始跳跃能力0，求最大能得到的跳跃能力
 *
 * 思路：
 * 设两个数组
 * odd[i]表示前i瓶药水中选择奇数次能达到的最大值
 * eve[i]表示前i瓶药水中选择偶数次能达到的最大值
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

int a[150000+100];
int odd[150000+100],eve[150000+100];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++ )
        scanf("%d",a+i);

    for(int i = 1 ; i <= n ; i++)
    {
        odd[i] = max(odd[i-1] , eve[i-1]+a[i]); //前i-1次也选了奇数瓶药水，这次不选 或 前i-1次选了偶数瓶药水，这次选了，跳跃能力增加
        eve[i] = max(eve[i-1] , odd[i-1]-a[i]); //前i-1次也选了偶数瓶药水，这次不选 或 前i-1次选了奇数瓶药水，这次选了，跳跃能力减弱
    }

    printf("%d\n",max(odd[n],eve[n]));

    return 0;
}
