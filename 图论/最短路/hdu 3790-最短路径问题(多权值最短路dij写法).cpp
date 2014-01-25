/*
 * 多权值最短路dijkstra写法
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
#define FR (freopen("in.txt","r",stdin))
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;
const int inf = 50000000;

struct node
{
    int len;
    int val;
}g[1010][1010];

int n,m,p;

int low[1010],vis[1010],cost[1010];

void dij(int s,int t)
{
    for(int i = 1 ; i <= n ; i++)
    {
        low[i] = g[s][i].len;
        cost[i] = g[s][i].val;
        vis[i]=0;
    }
    vis[s]=1;
    low[s]=0;
    cost[s]=0;

    for(int i = 2 ; i <= n ; i++)
    {
        int minc = inf;
        int pos;
        for(int j = 1 ; j <= n ; j++)
        {
            if(!vis[j] && low[j] <minc)
            {
                minc = low[j];
                pos = j;
            }
        }
            vis[pos]=1;
            for(int j = 1 ; j <= n ; j++)
            {
                if(!vis[j] && g[pos][j].len < inf)
                {
                    if(low[j] > g[pos][j].len + low[pos])
                    {
                        low[j] = g[pos][j].len + low[pos];
                        cost[j] = g[pos][j].val + cost[pos];
                    }
                    else if(low[j] == g[pos][j].len + low[pos])
                    {
                        if(cost[j] > cost[pos] + g[pos][j].val)
                        {
                            cost[j] = cost[pos] + g[pos][j].val;
                        }
                    }
                }
            }

    }

    cout << low[t] << ' ' << cost[t] << endl;
}

int main()
{
    //FR;

    while(cin >> n >> m && (n||m))
    {
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
            {
                g[i][j].len=inf;
                g[i][j].val=inf;
            }

        for(int i = 0 ; i < m ; i++)
        {
            int a,b,v;
            int op;
            cin >> a >> b >> v >> op;
            
            if(g[a][b].len > v)
            {
                g[a][b].len=g[b][a].len= v;
                g[a][b].val=g[b][a].val=op;
            }
            else if(g[a][b].len == v)
            {
                g[a][b].val = g[b][a].val = min(g[a][b].val,op);
            }
        }

        int s,t;
        cin >> s >> t;
           
        dij(s,t);
    }
    return 0;

}