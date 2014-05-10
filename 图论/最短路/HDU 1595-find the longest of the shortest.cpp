/********************************************************

    题意：
    给一副无向图，对于每一条边，
    删掉它之后求出最短路，求这m种最短路的最大值

    思路：
    枚举最初最短路上的每一条边是显然的，
    本题题目似乎没说，但是确实有这样的情况：
    没有权值相同的重边，也没有权值不同的重边，
    这样就大大简化了题目，
    直接记录下最初最短路径然后一一枚举相邻顶点

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
const int MAXN = 100000+100;
const int inf = 522133279;
const int mod = 1000000007;

struct edge
{
    int s;
    int t;
    int v;
    int next;
}e[1000000*2];

int low[1010],vis[1010];
int pre[1010],tpre[1010];
int head[1010];
int cnt;
int n,m;

void add(int s , int t , int v)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].v=v;
    e[cnt].next = head[s];
    head[s] = cnt++;
}

void init()
{
    clr(head,-1);
    clr(pre,-1);
    cnt=0;
}

int spfa()
{
    clr(low,0x1f);
    clr(vis,0);
    clr(pre,-1);
    queue<int> que;
    que.push(1);
    vis[1]=1;
    low[1]=0;

    while(!que.empty())
    {
        int cur = que.front();
        vis[cur]=0;
        que.pop();

        for(int i = head[cur] ; ~i ; i=e[i].next)
        {
            int next = e[i].t;

            if(low[next] > low[cur]+e[i].v)
            {
                low[next] = low[cur]+e[i].v;
                pre[next]=cur;

                if(!vis[next])
                {
                    que.push(next);
                    vis[next]=1;
                }
            }
        }
    }

    return low[n];
}

int gao()
{
    int ans = 0;
    int cur=n;
    while(tpre[cur]!=-1)
    {
        int before = tpre[cur];
        int tmp;
        ans = max(ans,spfa());

        for(int i = head[before] ; ~i ; i=e[i].next)
        {
            if(e[i].t == cur)
            {
                tmp = e[i].v;
                e[i].v=e[i^1].v=inf;
            }
        }
        ans = max(ans,spfa());
        for(int i = head[before] ; ~i ; i=e[i].next)
        {
            if(e[i].t == cur)
            {
                e[i].v=e[i^1].v=tmp;
            }
        }

        cur = before;
    }
    return ans;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i = 0 ; i < m ; i++)
        {
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            add(a,b,v);
            add(b,a,v);
        }
        spfa();
        for(int i = 0 ; i <= 1005 ; i++)
            tpre[i]=pre[i];
        printf("%d\n",gao());
    }
    return 0;
}
