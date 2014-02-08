/*
 * 题意：
 * 有一种巧克力包装上写着一个数字，收集齐一定数字可以换对应数字的奖品，换完奖品后只是简单地从总数字中减去奖品对应数字
 * 主人公很贪心，每吃一个巧克力，如果当前的数字和能够换奖品就立刻换，从价值高的开始换起，直到换不了为止，然后再吃下一块巧克力
 * 最后输出每种奖品对应的换得的数量和剩余数字
 *
 * 思路：
 * 由于兑换是从总数字中直接减，而不是拿走若干张糖纸使得拿走的数字和>=奖品数字，问题大大简化
 * 直接模拟就可以了
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

LL jiangpin[10],cnt[10],a[60];
LL v;
int n;

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    for(int i = 1 ; i <= 5 ; i++)
        cin >> jiangpin[i];

    for(int i = 0 ; i < n ; i++)
    {
        v += a[i];
        for(int j = 5 ; j >= 1 ; j--)       //从大的开始换起
        {
            int tmp = v/jiangpin[j];        //能换当前礼品tmp个
            v -= jiangpin[j]*tmp;
            cnt[j]+=tmp;
        }
    }

    for(int i=1;i<=5;i++)
        cout << cnt[i] << ' ';
    cout << '\n' << v << endl;;
    return 0;
}
