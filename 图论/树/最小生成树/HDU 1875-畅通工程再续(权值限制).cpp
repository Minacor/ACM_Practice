/*
 * 题意：
 * 给定所有村庄的坐标，只有距离[10,1000]的村庄才造路，100元一单位路
 * 求连通所有村庄最少的花费
 */

//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define mkp make_pair
using namespace std;
typedef long long LL;
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int n;

struct edge
{
    int s;
    int t;
    double v;
    int next;
}e[110*110*2];

int head[110],vis[110],cnt;
double low[110];

void init()
{
    clr(head,-1);
    clr(vis,0);
    for(int i = 0 ; i <= n ; i++)
        low[i]=inf;
    cnt=0;
}

void add(int s , int t , double v)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].v=v;
    e[cnt].next = head[s];
    head[s] = cnt++;
}

double prim()
{
    double res=0;
    low[1]=0;
    vis[1]=1;
    for(int i = head[1] ; ~i ; i=e[i].next)
        low[e[i].t] = e[i].v;

    for(int i = 1 ; i < n ; i++)
    {
        double minc = inf;
        int pos=-1;
        for(int j = 1 ; j <= n ; j++)
            if(!vis[j] && low[j] < minc)
                minc = low[j],pos=j;

        if(minc == inf)
            return -1;
        vis[pos]=1;
        res += minc;

        for(int j = head[pos] ; ~j ; j=e[j].next)
            if(!vis[e[j].t] && low[e[j].t] > e[j].v)
                low[e[j].t] = e[j].v;
    }
    return res;
}

struct node
{
    int x;
    int y;
}p[110];

double dis(node a,node b)
{
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d",&n);
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            for(int j = 1 ; j < i ; j++)
            {
                double d = dis(p[i],p[j]);
                if(d >= 10 && d <= 1000)
                {
                    add(i,j,d);
                    add(j,i,d);
                }
            }
        }

        double ok = prim();

        if(ok==-1)
            puts("oh!");
        else
            printf("%.1lf\n",ok*100);
    }
    return 0;
}
