/*
 * 题意：
 * 给n,l,r 问能否从l~r中取若干整数使得加和为n，每种整数可以无限取
 *
 * 思路：
 * 假设取k次就能满足条件
 * 那么应该有l*k <= n <= r*k
 * 即 n/l >= n/r ,注意这里的左右值都是实数
 * 整数的话，就只能取>
 * 等于的情况下，只能n被l或r整除
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
#define MID(x,y) ((x+y)>>1)
#define FR (freopen("in.txt","r",stdin))
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
//const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int x,a,b;
        cin >> x >> a >> b;
        int ok=0;
        if(x/a>x/b||x%b==0||x%a==0)ok=1;
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}
