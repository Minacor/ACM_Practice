/*********************************************************

    题意：
    给一副无向图，找到其中的满足条件的最短回路(从一个景点游历完若干景点后再返回此景点的最短路)
    条件是除了起点之外必须游览另外至少两个不同的景点

    思路：
    floyd找环经典题

**********************************************************/
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include "iostream"
#include "cstring"
#include "algorithm"
#include "cmath"
#include "cstdio"
#include "sstream"
#include "queue"
#include "vector"
#include "list"
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
#define PI acos(-1.0)
#define mkp make_pair
using namespace std;
typedef long long LL;
const int MAXN = 100000+100;
const int inf = 522133279;
const int mod = 1000000007;

int n,m;
int g[110][110];
int step[110][110];

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i = 0 ; i < 110 ; i++)
            for(int j = 0 ; j < 110 ; j++)
                g[i][j]=inf;

        for(int i = 0 ; i < m ; i++)
        {
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            g[a][b]=g[b][a]=min(g[a][b],v);
        }

        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                step[i][j] = step[j][i]=g[i][j];

        int ans=inf;

        /**
            核心算法如下
            floyd中 g[i][j]指的是i与j之间的临时最短路
            那么要构成至少三元以上的环，就要额外加入一个顶点，
            这个顶点就是k：
            ans = min(ans,g[i][j]+step[i][k]+step[k][j]);
            这样就能保证存在解的话，这个环一定是三元以上的环
            要注意i,j,k各不相同，注意循环的范围
        */
        for(int k=1;k<=n;k++)
        {
            for(int i = 1 ; i < k ; i++)
                for(int j = 1 ; j < i ; j++)
                    ans = min(ans,g[i][j]+step[i][k]+step[k][j]);

            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(g[i][j]>g[i][k]+g[k][j])
                    {
                        g[i][j]=g[i][k]+g[k][j];
                    }
        }

        if(ans == inf)
            puts("It's impossible.");
        else
            printf("%d\n",ans);
    }
    return 0;
}
