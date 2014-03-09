
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
    int s;
    int t;
    int c;
    int next;
}e[210*2];

int head[210],lv[210];
int cnt;

void add(int s , int t , int c)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].c=c;
    e[cnt].next = head[s];
    head[s] = cnt++;

    e[cnt].s=t;
    e[cnt].t=s;
    e[cnt].c=0;
    e[cnt].next = head[t];
    head[t] = cnt++;
}

int bfs(int src , int tar)
{
    queue<int> que;
    clr(lv,0);
    que.push(src);
    lv[src]=1;

    while(!que.empty())
    {
        int cur = que.front();que.pop();

        for(int i = head[cur] ; i+1 ; i = e[i].next)
        {
            if(e[i].c>0 && lv[e[i].t]==0)
            {
                lv[e[i].t]=lv[e[i].s]+1;
                if(e[i].t == tar)
                    return 1;
                que.push(e[i].t);
            }
        }
    }
    return 0;
}

int dfs(int cur , int tar , int totflow)
{
    int ret=0;
    if(cur == tar || !totflow) return totflow;

    for(int i = head[cur] ; i+1 ; i = e[i].next)
    {
        if(!totflow) break;
        if(e[i].c > 0 && lv[cur] == lv[e[i].t]-1)
        {
            int f = min(totflow,e[i].c);
            int totdown = dfs(e[i].t,tar,f);
            ret += totdown;
            totflow -= totdown;
            e[i].c -= totdown;
            e[i^1].c += totdown;
        }
    }
    return ret;
}

int dinic(int src , int tar)
{
    int ret=0;
    while(bfs(src,tar))
    {
        int tmp=dfs(src,tar,inf);
        if(!tmp) break;
        ret+=tmp;
    }
    return ret;
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        clr(head,-1);
        cnt=0;
        for(int i=1 ; i<=m ; i++)
        {
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            add(a,b,v);
        }
        printf("%d\n",dinic(1,n));
    }
    return 0;
}
