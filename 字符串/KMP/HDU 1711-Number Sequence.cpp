/*
 * 题意：
 * 从第一个数列中找出第二个数列
 *
 * 思路：
 * 裸kmp，只不过把比较字符变成了比较数字
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

int next[1000000+100];
int pat[10000+100],text[1000000+100];
int m,n;

void getnext()
{
    clr(next,0);
    for(int i = 1 ; i < m ;  i++)
    {
        int j = i;
        while(j)
        {
            j=next[j];
            if(pat[i]==pat[j])
            {
                next[i+1]=j+1;
                break;
            }
        }
    }
}

int kmp()
{
    getnext();
    for(int j=0,i = 0 ; i < n ; i++)
    {
        if(j < m && pat[j]==text[i])
            j++;
        else
        {
            while(j)
            {
                j=next[j];
                if(pat[j]==text[i])
                {
                    j++;
                    break;
                }
            }
        }

        if(j == m) return i-j+1;
    }
    return -2;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 0 ; i < n ; i++)
            scanf("%d",text+i);
        for(int j= 0 ; j < m ; j++)
            scanf("%d",pat+j);
        printf("%d\n",kmp()+1);
    }
    return 0;
}
