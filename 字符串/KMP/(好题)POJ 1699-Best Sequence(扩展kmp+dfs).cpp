/*
 * 题意：
 * 连接基因使得最后得到一个长度最短的基因
 * 如果基因a的某后缀 == b的相同长度的前缀，在a后面连接b时就能消除b的这个前缀
 *
 * 思路：
 * 最大消除用扩展kmp解决
 * 寻找最短基因可以用状压dp,dp[i][j]表示最后一个字符串是i且状态为j的最短基因
 * 但由于数据量较小，可以用dfs解决
 *
 * 注意：
 * 一个基因a是另一个基因b的非后缀子串，a不能直接匹配b，而只能以完整长度接在b的后面
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

int n;
int next[25],ret[25];
int g[15][15];
string s[15];

int extendKMP(string a , string b)
{
    clr(next,0);
    clr(ret,0);
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
        if(b.size()-i == ret[i] )       //注意点
            return ret[i];
    return 0;
}

int minc;
int vis[15];

void dfs(int cur , int v , int tot)
{
    if(tot == n-1)
    {
        minc = min(minc,v);
        return ;
    }
    if(v >= minc)
        return ;

    vis[cur]=1;
    for(int i = 0 ; i < n ; i++)
        if(!vis[i]) dfs(i,v+(int)s[i].size()-g[i][cur],tot+1);
    vis[cur]=0;
}

int main()
{
    //FR;
    int t;
    cin >> t;

    while(t--)
    {
        clr(g,-1);
        clr(vis,0);
        int sum=0;
        minc = inf;
        cin >> n;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> s[i];
            sum += s[i].size();
            for(int j = 0 ; j < i ; j++)
            {
                g[i][j] = extendKMP(s[i],s[j]);
                g[j][i] = extendKMP(s[j],s[i]);
            }
        }

        for(int i = 0 ; i < n ; i++)
            dfs(i,(int)s[i].size(),0);

        cout << minc << endl;
    }

    return 0;
}
