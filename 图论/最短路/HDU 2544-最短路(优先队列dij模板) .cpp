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
const int inf = /*522133279*/2147483640;
const int mod = 1000000007;

int n,m;
int g[300][300];
int vis[300],low[300];

struct node             //优先队列中的点
{
    int id;             //当前顶点
    int dis;            //起点到这个顶点的最短路

    bool operator < (const node& b)const        //优先队列默认大顶堆，所以得改变排序方式
    {
        return dis > b.dis;
    }
};

struct edge
{
    int s;
    int t;
    int v;
    int next;
}e[20200];
int head[110],cnt;

void init()
{
    clr(g,0x1f);
    clr(vis,0);
    clr(low,0x1f);
    clr(head,-1);
    cnt=0;
}

void add(int s,int t,int v)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].v=v;
    e[cnt].next=head[s];
    head[s]=cnt++;
}

int dij(int src)
{
    low[src]=0;
    node tmp;
    tmp.id=src;
    tmp.dis=low[src];
    priority_queue<node> que;
    que.push(tmp);

    while(!que.empty())
    {
        node cur = que.top();
        que.pop();

        if(vis[cur.id])
            continue;
        vis[cur.id]=1;

        for(int i = head[cur.id]; ~i ; i=e[i].next)
        {
            int next = e[i].t;
            if(low[next] > low[cur.id]+e[i].v)
            {
                low[next] = low[cur.id]+e[i].v;
                tmp.id = next;
                tmp.dis = low[next];
                que.push(tmp);
            }
        }
    }
    return low[n];
}

int main()
{
    while(~scanf("%d%d",&n,&m),(n+m))
    {
        init();

        for(int i = 1 ; i <= m ; i++)
        {
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            add(a,b,v);
            add(b,a,v);
        }

        int res = dij(1);

        printf("%d\n",res);
    }
    return 0;
}
