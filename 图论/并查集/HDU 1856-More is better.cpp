/*
 * 题意:
 * 一个房间有10000000个boy，有m对是直接朋友
 * 要求请出一些boy，使得留下来的是直接朋友或间接朋友
 * 求最多留下几个人
 */

//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define mkp make_pair
using namespace std;
typedef long long LL;
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

const int up = 10000000;

int f[up+100],cnt[up+100];

int find(int x)
{
    return x != f[x] ? f[x] = find(f[x]) : x;
}

void merger(int x,int y)
{
    x = find(x);
    y = find(y);

    if(x!=y)
        f[x]=y;
}

int main()
{
    int m;

    while(~scanf("%d",&m))
    {
        for(int i = 1 ; i <= up ; i++)
            f[i]=i;
        clr(cnt,0);

        for(int i = 0 ; i< m ; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            merger(x,y);
        }

        for(int i = 1 ; i <= up ; i++)
            cnt[find(i)]++;

        printf("%d\n",*max_element(cnt+1,cnt+1+up));

    }
    return 0;
}
