/*
 * ���⣺
 * ��һ��������n,m,l , ��ʾ���е�����n,��תվ������m,��l������
 * ���б��1~n,��תվ���1+n~n+m , CIA�ܻ��صı��Ϊ0
 * ÿ��������ͨ��������CIA���������������·������Ӱ��
 * ������l������ÿ��������a,b,c��ʾ���a�����b��һ������Ϊc�ĵ�����·
 * ������Ҫ����ı���һ����·���������������䵽CIA���ܿ����
 * �����Щ��·�ı�ţ����û�п���������·�����һ������
 *
 * ˼·��
 * ������ı���һ������ʹ���������0��Ϊ��㣬����m+n+1Ϊ����Դ��Ϳ�����
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
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
#define mkp make_pair
using namespace std;
typedef long long LL;
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int n,m,l;
int src , tar;

struct edge
{
    int s;
    int t;
    int next;
    int oc;
    int c;
}e[10010];

int head[150],lv[150];
int cnt;

void add(int s , int t , int c)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].oc = e[cnt].c = c;
    e[cnt].next = head[s];
    head[s] = cnt++;

    e[cnt].s=t;
    e[cnt].t=s;
    e[cnt].oc=c;
    e[cnt].c=0;
    e[cnt].next = head[t];
    head[t] = cnt++;
}

bool bfs()
{
    queue<int> que;
    que.push(src);
    clr(lv,0);
    lv[src]=1;

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();

        for(int i = head[cur] ; i+1 ; i=e[i].next)
        {
            int next = e[i].t;
            if(!lv[next] && e[i].c > 0)
            {
                lv[next] = lv[cur]+1;
                if(next == tar) return 1;
                que.push(next);
            }
        }
    }
    return false;
}

int dfs(int cur , int totf)
{
    int ret=0;

    if(cur == tar || totf == 0)
        return totf;

    for(int i = head[cur] ; i+1 ; i = e[i].next)
    {
        if(totf == 0) break;
        int next = e[i].t;
        if(lv[next] == lv[cur]+1 && e[i].c > 0)
        {
            int f = dfs(next,min(totf,e[i].c));
            ret += f;
            totf -= f;
            e[i].c -= f;
            e[i^1].c += f;
        }
    }

    return ret;
}

void dinic()
{
    while(bfs())
    {
        dfs(src,inf);
    }
}

int color[1010];
int vis[1010];

void odfs(int cur)
{
    vis[cur]=1;
    for(int i = head[cur] ; i+1 ; i = e[i].next)
    {
        int next = e[i].t;
        if(!vis[next])
        {
            if(e[i].c == 0)
                color[cur]=1;
            else
                odfs(next);
        }
    }
}

void rdfs(int cur)
{
    vis[cur] = 1;
    for(int i = head[cur] ; i+1 ; i=e[i].next)
    {
        int next = e[i].t;
        if(!vis[next])
        {
            if(e[i].c == e[i].oc)
                color[cur]=2;
            else
                rdfs(next);
        }
    }
}

int main()
{
    while(~scanf("%d%d%d",&n,&m,&l) && (n||m||l))
    {
        cnt=0;
        clr(color,0);
        clr(head,-1);
        src=n+m+1 , tar = 0;
        for(int i = 0 ; i < l ; i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
        }

        for(int i = 1 ; i <= n ; i++)
            add(src,i,inf);

        dinic();
        clr(vis,0);
        odfs(src);
        clr(vis,0);
        rdfs(tar);

        vector<int> out;
        for(int i = 0 ; i < cnt ; i+=2)
        {
            if(e[i].c == 0 && color[e[i].s] == 1 && color[e[i].t] == 2)
                out.push_back(i/2+1);
        }

        if(out.empty())
            puts("");
        else
        {
            printf("%d",out[0]);
            for(int i = 1 ; i < out.size() ; i++)
                printf(" %d",out[i]);
            puts("");
        }
    }
    return 0;
}
