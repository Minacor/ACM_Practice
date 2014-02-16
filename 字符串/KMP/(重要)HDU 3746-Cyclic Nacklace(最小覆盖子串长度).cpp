/*
 * 题意：
 * 给一个串,只能从头部和尾部加字母，问至少要加多少字母才能使这个串变成循环次数>1的循环串？
 * 如abcabcabc是一个循环串，循环节是abc,循环次数为3
 *
 * 思路：
 * 首先了解一个特别重要的性质:
 * 对于一个长度为len的字符串a,其len-next[len]是其最小覆盖子串的长度
 * 最小覆盖子串就是经过若干次复制后能够包含原串的"原串的子串"
 * 那么本题就是这个性质的应用了。设最小覆盖子串s的长度为l，如果len%l==0，说明这就是个以s为循环节的循环串
 * 如果不整除，说明有不完整的后缀，这时只要补全后缀就能形成循环串了
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

int next[100000+100];
char a[100000+100];
int len;

int getnext()
{
    clr(next,0);
    for(int i = 1 ; i < len ; i++)
    {
        int j = i;
        while(j)
        {
            j=next[j];
            if(a[i] == a[j])
            {
                next[i+1]=j+1;
                break;
            }
        }
    }

    return len-next[len];
}

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(a);
        len = strlen(a);
        int x = getnext();
        int out=0,l=len%x;
        if(l||len==x)
            out=x-l;    //补全后缀
        printf("%d\n",out);
    }
    return 0;
}
