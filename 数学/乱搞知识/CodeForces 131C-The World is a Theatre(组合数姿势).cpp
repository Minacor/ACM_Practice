/*
 * 题意：
 * 有n个男孩和m个女孩，要求选出t个人，其中男孩不少于4人，女孩不少于1人
 * 求选取的方法种数，两方法不同当且仅当人数分布不同
 *
 * 思路：
 * 组合数暴力模拟
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
const int MAX = (1<<15)+100;
const int inf = 522133279;

LL C(int n,int m)
{
    LL fenzi = 1;
    int fenmu=1;
    for(int i = n-m+1 ; i <= n ; i++)
    {
        fenzi *= i;
        fenzi /=fenmu++;
    }

    return fenzi;
}

int main()
{
    int m,n,t;
    cin >> m >> n >> t;

    LL ans=0;
    for(int i = 1 ; i <= t-4 ; i++)
    {
        if(i <= n && t-i <= m)
            ans += C(m,t-i)*C(n,i);
    }
    cout << ans << endl;
    return 0;
}
