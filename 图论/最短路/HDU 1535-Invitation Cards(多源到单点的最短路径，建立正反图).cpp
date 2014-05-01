/********************************************************

    题意：
    给定p个顶点和q条单向路径，求出从1到各个点的最短路径和+
    各个点到1的最短路径和

    思路：
    建立正反图+spfa
*********************************************************/

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

int p,q;

struct edge
{
    int s,t,v;
    int next;
}e[MAXN],re[MAXN];

int head[MAXN],rhead[MAXN];
int vis[MAXN],low[MAXN];
int cnt;

void add(int s , int t ,int v)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].v=v;
    e[cnt].next = head[s];
    re[cnt].s=t;
    re[cnt].t=s;
    re[cnt].v=v;
    re[cnt].next = rhead[t];
    head[s] = rhead[t] = cnt++;
}

int spfa()
{
    clr(vis,0);
    clr(low,0x1f);
    queue<int> que;
    que.push(1);
    low[1]=0;
    vis[1]=1;

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();

        vis[cur]=0;
        for(int i = head[cur] ; ~i ; i=e[i].next)
            if(low[e[i].t] > e[i].v+low[cur])
            {
                low[e[i].t] = e[i].v+low[cur];

                if(!vis[e[i].t])
                {
                    que.push(e[i].t);
                    vis[e[i].t]=1;
                }
            }
    }

    int res=0;
    for(int i = 1 ; i <= p ; i++)
        res += low[i];
    return res;
}

int rspfa()
{
    clr(vis,0);
    clr(low,0x1f);
    queue<int> que;
    que.push(1);
    low[1]=0;
    vis[1]=1;

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();

        vis[cur]=0;
        for(int i = rhead[cur] ; ~i ; i=re[i].next)
            if(low[re[i].t] > re[i].v+low[cur])
            {
                low[re[i].t] = re[i].v+low[cur];

                if(!vis[re[i].t])
                {
                    que.push(re[i].t);
                    vis[re[i].t]=1;
                }
            }
    }

    int res=0;
    for(int i = 1 ; i <= p ; i++)
        res += low[i];
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        clr(head,-1);
        clr(rhead,-1);
        cnt=0;
        scanf("%d%d",&p,&q);

        while(q--)
        {
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            add(a,b,v);
        }

        printf("%d\n",spfa()+rspfa());
    }
    return 0;
}
