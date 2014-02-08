/*
 * 题意：
 * 每个箱子有一个值x，表示他的上方最多能有x个箱子，若干个箱子叠成一列叫做"一堆"
 * 问最少可以摆几堆
 *
 * 思路：
 * 从小的开始拿，拿了的箱子压进一个vector中，如果当前vector的size小于等于现在判断的箱子的x，表明x可以放在现在的最底下，就加入
 * 直到不能加入为止，换新vector，重复操作直到所有箱子被用上
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
const int mod = 1000000007;

int a[110];
int cnt[110];
vector<int> cur;

int main()
{
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    sort(a,a+n);

    int ans=0;
    int ok=1;
    while(ok)
    {
        ok=0;
        cur.clear();
        for(int i = 0 ; i < n ; i++)
            if(a[i] != -1)
            {
                if(a[i] >= cur.size())
                    cur.push_back(a[i]),a[i]=-1;
                ok=1;
            }
        ans++;
    }
    cout << ans-1 << endl;
    return 0;
}
