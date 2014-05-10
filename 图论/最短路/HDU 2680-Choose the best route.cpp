/*******************************************************

    题意：
    给n个车站m条路线，目的地s
    每条路线p，q，t 表示p站到q站费时t(单向)
    再给一个数w，接下来的w个数表示能够作为起点的车站
    问到达s的最短时间

    思路：
    添加超级源点0，裸最短路
********************************************************/


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
const int MAXN = 1000000+100;
const int inf = 522133279;
const int mod = 1000000007;

int g[1010][1010];
int vis[1010],low[1010];
int n,m,s;

int spfa()
{
    clr(vis,0);
    clr(low,0x1f);
    low[0]=0;
    vis[0]=1;

    queue<int> que;
    que.push(0);

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        vis[cur]=0;

        for(int i = 0 ; i <= n ; i++)
        {
            if(low[i] > low[cur]+g[cur][i])
            {
                low[i] = low[cur]+g[cur][i];

                if(!vis[i])
                {
                    vis[i]=1;
                    que.push(i);
                }
            }
        }
    }
    return low[s]==inf ? -1 : low[s];
}

int main()
{
    while(~scanf("%d%d%d",&n,&m,&s))
    {
        clr(g,0x1f);
        for(int i = 0 ; i < m ; i++)
        {
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            g[a][b] = min(g[a][b],v);
        }
        int w;
        scanf("%d",&w);
        while(w--)
        {
            int tmp;
            scanf("%d",&tmp);
            g[0][tmp]=0;
        }

        printf("%d\n",spfa());
    }
    return 0;
}
