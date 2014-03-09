
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
const int MAX = 200000+10;
const int inf = 522133279;
const int mod = 1000000007;

int m,n;
struct edge
{
    int c;          //容量
    int f;          //当前流量
}g[210][210];

int lv[210];        //结点所在层次
int vis[210];       //结点访问标记

int bfs(int src , int tar)          //bfs构建层次网络，src为源点，tar为汇点，一次寻找到多条增广路
{
    clr(vis,0);
    clr(lv,0x1f);
    queue<int> que;
    que.push(src);
    vis[src]=1;
    lv[src]=1;

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();

        for(int i = 1 ; i <= n ; i++)
        {
            if(!vis[i] && g[cur][i].c > g[cur][i].f)        //只有还有残余容量的时候才能深入标号
            {
                vis[i]=1;
                lv[i]=lv[cur]+1;
                que.push(i);
            }
        }
    }

    return lv[tar] < inf;           //如果汇点不在层次网络中，说明没有增广路了，退出dinic
}

int dfs(int cur , int tar , int totflow)    //利用层次网络进行增广，每次dfs寻找的是从该节点cur出发进行dfs增加的总流量
                                            //totflow指的是以后的网络能够传输的最大流量，即当前点流出的最大流量
{
    int ret=0;
    if(cur == tar || !totflow) return totflow;  //如果到达汇点或者当前点不能再提供流量了，就退出

    for(int i = 1 ; i <= n ; i++)
    {
        if(!totflow) break;                     //不能提供流量了
        if(g[cur][i].c > g[cur][i].f && lv[cur]==lv[i]-1)   //若能提供流量，则只有在通往下一层(同层不能传递)的边上有剩余容量才能继续
        {
            int f = min(totflow , g[cur][i].c-g[cur][i].f); //能够通过的流量
            int totdown = dfs(i,tar,f);                     //totdown是之后所有以i为起点的分支能够通过的流量总和
            ret += totdown;                                 //加上能够流到汇点的流量
            totflow -= totdown;                             //总可通过流量相应减去
            g[cur][i].f += totdown;                         //从cur传输给i所需的totdown
            g[i][cur].f -= totdown;                         //反向边相应减去totdown
        }
    }
    return ret;
}

int dinic(int src , int tar)
{
    int ret=0;
    while(bfs(src,tar))         //层次网络包含汇点，即仍然存在增广路
    {
        int tmp=dfs(src,tar,inf);   //从源点起能够增加的总流量
        if(!tmp) break;
        ret+=tmp;
    }
    return ret;
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        clr(g,0);
        for(int i = 1 ; i <= m ; i++)
        {
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            g[a][b].c+=v;       //重边累加容量就可以了
        }
        printf("%d\n",dinic(1,n));
    }
    return 0;
}
