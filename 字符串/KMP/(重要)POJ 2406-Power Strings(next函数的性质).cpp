/*
 * 给一个字符串s
 * 对于s的所有字串s[0],s[0,1],s[0...2],...,s[0...n](即所有前缀串)
 * 其中有些子串a满足a^n == s 比如s = ababab ，a = ab ， 则a^3 == s,n==3
 * 输出最大的n
 *
 * 思路：
 * next函数的性质：
 * 假设S的长度为len，则S存在循环子串，当且仅当，len可以被len - next[len]整除，最短循环子串为S[len - next[len]]
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

char s[1000000+100];
int next[1000000+100];
int len;

void getnext()
{
    clr(next,0);
    for(int i = 1 ; i <= len ; i++)
    {
        int j = i;
        while(j)
        {
            j = next[j];
            if(s[i] == s[j])
            {
                next[i+1]=j+1;
                break;
            }
        }
    }
}

int main()
{
    while(scanf("%s",s),s[0]!='.')
    {
        len = strlen(s);
        getnext();
        int o = len%(len-next[len]) ? 1 : len/(len-next[len]);
        printf("%d\n",o);
    }
    return 0;
}
