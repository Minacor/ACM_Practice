/*
 * 多权值最短路spfa写法,注意次权值的判断安排在哪
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
        low[i] = inf;
        cost[i] = inf;
        vis[i]=0;
    }
    vis[s]=1;
    low[s]=0;
    cost[s]=0;

     queue<int> que;
    while(!que.empty())
        que.pop();
    que.push(s);

    while(!que.empty())
    {
        int cur =que.front();
        que.pop();
        vis[cur]=0;

        for(int i = 1 ; i <= n ; i++)
        {
            if(low[i] > low[cur] + g[cur][i].len)
            {
                low[i] = low[cur]+g[cur][i].len;
                cost[i] = cost[cur]+g[cur][i].val;
                if(!vis[i])
                {
                    que.push(i);
                    vis[i]=1;
                }
            }
            else if(low[i] == low[cur] + g[cur][i].len)
            {
                if(cost[i] > cost[cur]+g[cur][i].val)
                    cost[i] = cost[cur]+g[cur][i].val;
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
