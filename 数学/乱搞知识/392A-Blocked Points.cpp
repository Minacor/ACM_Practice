/*
 * 题意：
 * 就是求一个半径为n的圆内的靠近最外层的点的个数
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
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int main()
{
    int n;
    cin >> n;

    if(!n)
    {
        cout << 1 << endl;
        return 0;
    }
    LL cnt=0,last=0;
    for(int i = n-1 ; i >= 1 ; i--) //枚举最外层点，这个点向右移动1单位就在圆外了
    {
       LL j = (LL)sqrt(1.0*n*n-1.0*i*i);       //最外层点
       cnt++;
       cnt += (j-last-1) > 0 ? j-last-1 : 0;    //last标记上一个最外层点的位置，last~j之间的点也是最外层点
                                                //这些点向上移动1单位就在圆外了
       last=j;
    }
    cout << 4*cnt+4 << endl;
    return 0;
}
