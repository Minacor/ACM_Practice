

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
        if(b.size()-i == ret[i] /*|| ret[i] == a.size()*/)
            return ret[i];
    return 0;
}

int dp[(1<<10)+100];

int main()
{
    //FR;
    int t;
    cin >> t;

    while(t--)
    {
        clr(g,-1);
        clr(dp,0);
        int sum=0;

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

        for(int i = 1 ; i < (1 << n) ; i++)
        {
            for(int k = 0 ; k < n ; k++)
            {
                if(i & (1 << k))
                {
                    int last = i - (1 << k);
                    for(int l = 0 ; l < n ; l++)
                    {
                        if((last&(1<<l)) && g[l][k] != -1)
                            dp[i] = max(dp[last]+g[l][k],dp[i]);
                    }
                }
            }
        }

        cout << sum-dp[(1<<n)-1] << endl;
    }

    return 0;
}
