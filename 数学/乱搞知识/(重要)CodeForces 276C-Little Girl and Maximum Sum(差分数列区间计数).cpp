/*
 * 题意：
 * 给一个数列a和一群询问，每一次询问(l,r)就求出此区间内的元素和
 * 问怎样重排这个数列使得所有询问的结果之和最大
 *
 * 思路：
 * 当然是询问得越多的点放置越大的数咯~
 * 所以要做的就是算出1~n内所有位置的被询问次数，用b[i]记录
 * 然后从小到大排列a和b，答案就是∑(a[i]*b[i])
 * 然后为了卡进限制时间内，用差分数列计数
 *
 * 差分数列能够高效令区间[l,r]内的点+delta，然后通过累加得到每个点的被计数次数
 * 区间计数，差分数列是个很好的工具
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

LL a[MAX],cnt[MAX];
int main()
{
    int n,q;
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    for(int i = 0 ; i < q ; i++)
    {
        int x,y;
        cin >> x >> y;
        cnt[x]++;cnt[y+1]--;    //这样在累加的时候，区间外的数就+1 -1抵消了，达到计数目的
    }
    for(int i = 1 ; i <= n ; i++)
        cnt[i] += cnt[i-1];
    sort(a+1,a+n+1);
    sort(cnt+1,cnt+1+n);
    LL ans=0;
    for(int i = 1 ; i<= n ; i++)
        ans += cnt[i]*a[i];
    cout << ans << endl;
    return 0;
}
