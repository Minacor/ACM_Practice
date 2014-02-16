/*
 * 题意：
 * 求m个字符串的最长公共子串，如果有多个最长公共子串，输出字典序最小的
 *
 * 思路：
 * 数据量不大，直接暴枚第一个字符串的所有子串，每一个字串用kmp判断是否在其他串中包含此子串
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

int next[70];
string pat,text;
string g[15];

void getnext()
{
    clr(next,0);
    for(int i = 1 ; i < pat.size() ; i++)
    {
        int j = i;
        while(j)
        {
            j = next[j];
            if(pat[i] == pat[j])
            {
                next[i+1] = j+1;
                break;
            }
        }
    }
}

bool kmp()
{
    getnext();

    for(int i = 0 , j = 0 ; i<text.size() ; i++)
    {
        if(j < pat.size() && text[i] == pat[j])
            j++;
        else
        {
            while(j)
            {
                j = next[j];
                if(text[i] == pat[j])
                {
                    j++;
                    break;
                }
            }
        }

        if(j == pat.size()) return 1;
    }
    return 0;
}

int main()
{
    //FR;
    int t;
    cin >> t;
    string out("");

    while(t--)
    {
        out="";
        int m;
        cin >> m;

        for(int i = 0 ; i < m ; i++)
            cin >> g[i];
        for(int len = 0 ; len <= g[0].size() ; len++)
        {
            for(int i = 0 ; i+len <= g[0].size() ; i++)
            {
                pat = g[0].substr(i,len);
                int ok=1;
                for(int j= 1 ; j < m ; j++)
                {
                    text = g[j];
                    if(!(ok = kmp())) break;
                }
                if(ok)
                {
                    if(out.size() == pat.size())
                        out = min(out,pat);
                    else
                        out = out.size()>pat.size() ? out :pat;
                }
            }
        }

        if(out.size() < 3)
            cout << "no significant commonalities" << endl;
        else
            cout << out << endl;
    }

    return 0;
}
