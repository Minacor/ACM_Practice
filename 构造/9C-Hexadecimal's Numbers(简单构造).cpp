/*
 * 题意：
 * 给一个十进制数n，求出比他小的仅包含01的十进制数的个数
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
const int MAX = 200000+100;
const int inf = 522133279;
const int mod = 1000000007;

int n,cnt;

void dfs(int x)
{
    if(x > n)
        return ;
    cnt++;
    dfs(10*x);dfs(10*x+1);
}

int main()
{
    cin >> n;
    dfs(1);
    cout << cnt << endl;
    return 0;
}
