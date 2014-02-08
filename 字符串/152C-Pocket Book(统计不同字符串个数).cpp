/*
 * 题意：
 * 给n个字符串长度为m的字符串
 * 给一种操作：选定三个数i，j，k 交换第i个和第j个字符串的前k个字符
 * 问能够组合出多少个和第一个字符串不同的字符串
 *
 * 思路：
 * 由于操作可叠加，所以可以这么操作：
 * 选定i，j，第一次交换k，第二次交换k-1，这样就相当于交换了第k个字符
 * 由此可知能够组成的字符串数就是cnt1*cnt2*...*cntn，cnti表示第i位上有多少不同的字符
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

int n,m;
string g[110];
map<char , int> tongji;

int main()
{
    LL sum=1;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        cin >> g[i];
    for(int i = 0 ; i < m ; i++)
    {
        tongji.clear();
        for(int j = 0 ; j < n ; j++)
            tongji[g[j][i]]++;
        sum = (sum*tongji.size())%1000000007;
    }
    cout << sum%1000000007 << endl;
    return 0;
}
