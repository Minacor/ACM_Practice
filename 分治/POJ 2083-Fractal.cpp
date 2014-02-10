/*
 * 题意：
 * 按图输出
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
const int MAX = 200000+100;
const int inf = 522133279;
const int mod = 1000000007;

char g[1000][1000];

void dfs(int n , int x , int y)
{
    if(n == 1)
    {
        g[x][y]='X';
        return ;
    }
    int s = (int)pow(3.0,n-2);

    dfs(n-1,x,y);         dfs(n-1,x,y+2*s);
            dfs(n-1,x+s,y+s);
    dfs(n-1,2*s+x,y);     dfs(n-1,x+2*s,y+2*s);
}

int main()
{
    int n;
    while(~scanf("%d",&n) && n != -1)
    {
        int s = (int)pow(3.0,n-1);
        for(int i = 1 ; i <= s ; i++)
            fill(g[i]+1,g[i]+1+s,' ');

        dfs(n,1,1);
        for(int i = 1 ; i <= s ; i++)
        {
            g[i][s+1]='\0';
            puts(g[i]+1);
        }
        printf("-\n");
    }
    return 0;
}
