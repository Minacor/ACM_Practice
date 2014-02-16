/*
 * 题意：
 * 给两个字符串a,b，输出a中包含几个不重叠的b
 *
 * 思路：
 * kmp匹配，每次匹配记录下位置以便找到下一个匹配时判断是否重叠
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

string g[10010];
int r,c;
int next[10010];
string col;

int getnext(string pat)
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
    return pat.size()-next[pat.size()];
}

int kmp(string pat,string text)
{
    int last=-1,cnt=0;
    getnext(pat);
    for(int i = 0 , j = 0 ; i < text.size() ; i++)
    {
        if(j<pat.size() && pat[j] == text[i])
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

        //找到匹配
        if(j == pat.size())
        {
            //判断是否重叠
            if(last==-1)
            {
                last = i-j+1;
                cnt++;
            }
            else
            {
                if(i-j+1-last < j)
                    ;
                else
                {
                    last = i-j+1;
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

int main()
{
    string pat,text;

    while(cin >> text && text != "#" && cin >> pat)
        cout << kmp(pat,text) << endl;

    return 0;
}
