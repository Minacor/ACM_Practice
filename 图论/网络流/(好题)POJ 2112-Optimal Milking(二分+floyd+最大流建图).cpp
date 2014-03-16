/*
 * 题意：
 * 有k个挤奶器，c头牛，每个挤奶器最多挤m头牛的奶
 * 然后给(k+c)*(k+c)的一个矩阵，矩阵的1~k个元素代表挤奶器编号，剩余的是奶牛编号
 * g[i][j]表示i到j的直接路线的距离，不连通则是0，g[i][i]=0
 * 求每头牛都能挤到奶的前提下，走的最长的那头牛的走的路程的最小值，牛走的都是最短距离
 *
 * 思路：
 * 最大值中求最小，二分
 * 首先floyd处理出每头牛到挤奶器之间的最小距离
 * 二分枚举某种走法下走的最长的那头牛的路程x，根据这个x值建图(x的范围就是g中的最小值和最大值)：
 * src-牛之间建边，权值为1，挤奶器-tar之间建边，权值为m，牛i-挤奶器j之间仅当g[i][j]<=x时建边，权值为1
 * 如果这种种情况下最大流值为c，则向左区间寻找更小的解，不是的话就向右区间寻找可行解
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
#define MID(x,y) ((x+y)>>1)
#define FR (freopen("in.txt","r",stdin))
#define FO (freopen("out.txt","w",stdout))
#define clr(a,b) memset(a,b,sizeof(a))
#define mkp make_pair
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 1000000;
const int inf = 522133279;
const int mod = 1000000007;

int k,c,m;
int g[300][300];
int lv[300];

struct edge
{
    int s;
    int t;
    int c;
    int next;
}e[300*300*2];

int src , tar;
int head[300],cnt;

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

void floyd()
{
    for(int x = 1 ; x <= k+c ; x++)
        for(int i = 1 ; i <= k+c ; i++)
         if(g[x][i] != inf)
            for(int j = 1 ; j <= k+c ; j++)
                if(g[i][j] > g[i][x]+g[x][j])
                    g[i][j] = g[i][x]+g[x][j];
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

int dinic()
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

int gao(int x)
{
    cnt=0;
    clr(head,-1);
    clr(e,0);

    for(int i = 1 ; i <= c ; i++)
        add(src , i , 1);
    for(int i = c+1 ; i < tar ; i++)
        add(i , tar , m);
    for(int i = 1 ; i <= c ; i++)
        for(int j = 1 ; j <= k ; j++)
            if(g[k+i][j] <= x)
                add(i,j+c,1);

    int ok = dinic();
    if(ok == c)
        return 1;
    return 0;
}

int maxc,minc;

int bs()
{
    int l = minc , r = maxc;

    do
    {
        int mid = MID(l,r);

        int ok = gao(mid);

        if(ok == 0)
            l = mid+1;
        else r = mid-1;

    }while(l <= r);

    return l;
}

int main()
{
    //FR;
    while(~scanf("%d%d%d",&k,&c,&m))
    {
        src = 0 ; tar = k+c+1;
        for(int i = 1 ; i <= k+c ; i++)
            for(int j = 1 ; j <= k+c ; j++)
            {
                scanf("%d",&g[i][j]);
                if(g[i][j] == 0) g[i][j] = inf;
            }

        floyd();
        maxc = -1,minc=inf;
        for(int i = 1 ; i <= k+c ; i++)
            for(int j = 1 ; j <= k+c ; j++)
            {
                if(g[i][j] == inf) continue;
                maxc = max(maxc,g[i][j]);
                minc = min(minc,g[i][j]);
            }

        cout << bs() << endl;
    }
    return 0;
}
