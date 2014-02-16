/*
 * 题意：
 * 给两个字符串a,b ; a+b定义为：
 * 如果a的后缀与b的前缀有相同的，取最大覆盖度相接,也就是a前缀+a,b相同子串+b后缀
 * 无相同的话直接相加
 * 最后取的是长度最短的情况下最小的字典序
 *
 * 思路：
 * 扩展kmp,
 * ret[i]表示b的子串b[i...n](也就是i开始的后缀子串)和字符串a的最长公共前缀的长度
 * 如果这个长度恰好是n-i，表示b的此后缀就是a的前缀
 * 由于i是递增的，所以一旦找到一个i，此时匹配成的字符串一定是最短的
 *
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

int next[MAXN],ret[MAXN];

int extendKMP(string a , string b)
{
    int m = a.size() , n = b.size();
    int i,j,k;
    for(i = 0 ; i < m-1 && a[i] == a[i+1]; i++);
    next[1]=i;

    k = 1;

    for(i = 2 ; i < m ; i++)
    {
        int len = k+next[k] , L = next[i-k];
        if(L < len-i)
            next[i]=L;
        else
        {
            for(j = max(0,len-i) ; i+j < m && a[j] == a[i+j] ;j++);
            next[i]=j;
            k=i;
        }
    }

    for( j = 0 ; j < n && j < m && a[j] == b[j] ; j++) ;
    ret[0]=j;
    k=0;
    for( i = 1 ; i < n ; i++)
    {
        int len = k+ret[k],L = next[i-k];
        if(L<len-i)
            ret[i]=L;
        else
        {
            for( j = max(0,len-i) ; j < m && i+j<n && a[j] == b[i+j];j++);
            ret[i]=j;
            k=i;
        }
    }

    for(int i = 0 ; i < b.size() ; i++)
        if(ret[i] == b.size()-i)
            return i;
    return b.size();
}

int main()
{
    string a,b;
    while(cin >> a >> b)
    {
        clr(next,0);
        clr(ret,0);
        int pos1 = extendKMP(a,b),pos2 = extendKMP(b,a);
        string x = b.substr(0,pos1) + a;
        string y = a.substr(0,pos2) + b;

        if(x.size() == y.size())
            cout << min(x,y) << endl;
        else
            cout << (x.size() < y.size() ? x : y) << endl;
    }

    return 0;
}
