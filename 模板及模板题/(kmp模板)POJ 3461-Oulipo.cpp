/*
 * 题意：
 * 就是输出下面一个串能匹配上面一个串的位置有多少个，kmp模板
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

int next[500000+100];
string pat,text; //模式串，文本串
int cnt;

void getnext()
{
    clr(next , 0);
    for(int i = 1 ; i < pat.size() ; i++)
    {
        int j = i;
        while(j)
        {
            j = next[j];
            if(pat[i] == pat[j])
            {
                next[i+1]=j+1;
                break;
            }
        }
    }
}

void kmp()
{
    cnt=0;
    getnext();

    for(int i = 0 , j = 0 ; i < text.size() ; i++)
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

        if(j == pat.size()) cnt++;
        //cout << i-j+1 << endl;  这是输出匹配位置

    }
    cout << cnt << endl;
}

int main()
{
    FR;
    int t;
    cin >> t;

    while(t--)
    {
        cin >> pat >> text;
        kmp();
    }
    return 0;
}

