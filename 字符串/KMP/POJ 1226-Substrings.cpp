/*
 * 题意：
 * 求这样的最长子串s的长度：每个字符串中包含s或者s的反转
 *
 * 思路：
 * 仍旧暴力，只不过多加一个翻转的流程而已
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

int next[110];
string g[110];

void getnext(string pat)
{
    clr(next,0);
    for(int i = 1 ; i < pat.size() ; i++)
    {
        int j = i;
        while(j)
        {
            j = next[j];
            if(pat[j] == pat[i])
            {
                next[i+1]=j+1;
                break;
            }
        }
    }
}

bool kmp(string pat , string text)
{
    getnext(pat);

    for(int i = 0,j=0 ; i < text.size() ; i++)
    {
        if(j < pat.size() && pat[j] == text[i])
            j++;
        else
        {
            while(j)
            {
                j = next[j];
                if(pat[j] == text[i])
                {
                    j++;
                    break;
                }
            }
        }

        if(j == pat.size())
            return 1;
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int m;
        cin >> m;
        int out=0;
        for(int i = 0 ; i < m ; i++)
            cin >> g[i];
        for(int len = g[0].size() ; len >= 1 ; len--)
        {
            for(int i = 0 ; i+len <= g[0].size() ; i++)
            {
                string pat = g[0].substr(i,len);
                string repat = pat;
                reverse(repat.begin(),repat.end());
                int ok=1;
                for(int j = 1 ; j < m ; j++)
                {
                    if(g[j].size() < pat.size())
                    {
                        ok=0;
                        break;
                    }

                    ok = (kmp(pat,g[j]) || kmp(repat,g[j]));
                    if(!ok) break;
                }

                if(ok){ out = len;break;}
            }
            if(out)
                break;
        }

        cout << out << endl;
    }

    return 0;
}
