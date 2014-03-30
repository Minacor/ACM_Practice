/*
 * ����:
 * ��һ����ͨ������ͼ������Ҫ��һ����ʹ����ͼ�е��ŵ���������,������ٵ��ŵ�����
 * ע�����ر�
 *
 * ˼·:
 * �����˫��ͨ����:
 * ������tarjin����ţ���ȻҪע���ر�����
 * Ȼ��һ��dfs����:find_bg()�����ж���Ⱦɫ�����dfs�ǲ������ŵ�,����ŵ�Ŀ�ľ����ڴ�
 * find_bg()�����Ժ����е㶼��Ⱦɫ�ˣ�ͬһ��ɫ�ĵ�����ͬһ˫��ͨ����
 *
 * Ȼ��������ͼ,����ͼ�е����б߾�����
 * ����ͼ��һ����,����ѡ������������������ô�����������Ķ���(����)�ֹ�����һ���µ�˫��ͨ����
 * Ҳ����˵�������Ŷ���֮�����ȫ��û����
 * ��ôҪʹ�ŵ���������,��Ҫ��������·����Ķ��㣬Ҳ����˵������ת��Ϊ�������������
 *
 * ������ķ���:
 * ������ѡһ������dfs,�õ�ÿ��Ҷ�ӽڵ�����
 * Ȼ��ѡ����������Ǹ��ٴ�dfs,�õ����������Ҷ�ӽڵ����Ⱦ������������
 */

#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int n,m;

struct edge
{
    int s;
    int t;
    int chongbian;
    int isb;
    int next;
}e[1000100*2];

int head[200100],dfn[200100],low[200100];
int part[200100],totpart;
int cnt,clo;

void add(int s , int t)
{
    for(int i = head[s] ; i+1 ; i=e[i].next)
    {
        if(e[i].t == t)
        {
            e[i].chongbian=e[i^1].chongbian=1;
            return;
        }
    }

    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].chongbian=e[cnt].isb=0;
    e[cnt].next = head[s];
    head[s] = cnt++;

    e[cnt].s=t;
    e[cnt].t=s;
    e[cnt].chongbian=e[cnt].isb=0;
    e[cnt].next = head[t];
    head[t] = cnt++;
}

void init()
{
    clr(low,0);
    clr(dfn,0);
    clr(head,-1);
    cnt=clo=totpart=0;
    clr(part,0);
}


void tarjin(int cur , int fa)
{
    dfn[cur] = low[cur] = ++clo;

    for(int i = head[cur] ; i+1 ; i=e[i].next)
    {
        int next = e[i].t;
        if(!dfn[next])
        {
            tarjin(next,cur);
            low[cur] = min(low[cur],low[next]);

            if(low[next] > dfn[cur] && e[i].chongbian == 0)
                e[i].isb=e[i^1].isb=1;
        }
        else if(fa != next)
            low[cur] = min(low[cur],dfn[next]);
    }
}

void find_bg(int cur,int type)
{
    part[cur]=type;
    for(int i = head[cur] ; i+1 ; i=e[i].next)
    {
        int next = e[i].t;
        if(!part[next] && !e[i].isb)
            find_bg(next,type);
    }
}

vector<int> tree[200100];
int dep[200100];

void dfs(int cur)
{
    for(int i = 0 ; i < tree[cur].size() ; i++)
    {
        int next = tree[cur][i];
        if(dep[next]!=-1) continue;
        dep[next] = dep[cur]+1;
        dfs(next);
    }
}

int solve()
{
    for(int i = 1 ; i <= n ; i++)
    {
        if(!part[i])
            find_bg(i,++totpart);
        tree[i].clear();
    }
    for(int i = 0 ; i < cnt ; i+=2)         //��������ͼ,������ͬһ������ĵ������������һ����
        if(part[e[i].s] != part[e[i].t])
        {
            tree[part[e[i].s]].push_back(part[e[i].t]);
            tree[part[e[i].t]].push_back(part[e[i].s]);
        }

    //�����
    clr(dep,-1);
    dep[1]=0;
    dfs(1);
    int pos=1;
    for(int i = 1 ; i <= totpart ; i++)
        if(dep[pos] < dep[i])
            pos=i;
    clr(dep,-1);
    dep[pos]=0;
    dfs(pos);
    int ans=0;
    for(int i = 1 ; i <= totpart ; i++)
        ans = max(ans,dep[i]);

    return totpart-1-ans;
}

int main()
{
    //FR;
    while(~scanf("%d%d",&n,&m) && (n||m))
    {
        init();
        for(int i = 0 ; i < m ; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
        }
        tarjin(1,-1);
        printf("%d\n",solve());
    }
    return 0;
}
