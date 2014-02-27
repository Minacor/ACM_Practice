/*
 * 题意：
 * 给定n组线段的左右端点，第一组是(a,b)
 * 求第一个线段中未被其余线段覆盖的长度
 *
 * 思路：
 * 直接暴力标记被覆盖的点为1
 * 由于求长度，注意线段两端点只能标记一个
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

int x[110];
int main()
{
    int n;
    cin >> n;
    int a,b;
    cin >> a >> b;
    for(int i = 0 ; i < n-1 ; i++)
    {
        int aa,bb;
        cin >> aa >> bb;
        for(int i = aa ; i < bb ; i++)
            x[i]=1;
    }
    int cnt=0;
    for(int i = a ; i < b ; i++)
        if(!x[i]) cnt++;

    cout << cnt << endl;
    return 0;

}
