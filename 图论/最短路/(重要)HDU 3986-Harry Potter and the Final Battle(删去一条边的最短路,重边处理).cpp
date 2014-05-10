/********************************************************

    ���⣺
    ��һ������ͼ����ɾȥһ�����Ժ�����·�����ֵ

    ˼·��
    �����HDU 1595�����Ƶģ�ֻ�����������ر���Ҫ����
    ����ķ����ܼ򵥣���pre����ĳɶ�ά�ģ�
    pre[i][0]��ʾi����������·�е�ǰ��
    pre[i][1]��ʾpre[i][0] -> i����·�������·�е�Ȩֵ
    (�������رߵĻ������·��ѡ���Ӧ����Ȩֵ��С��)

    Ȼ��ö�����·�еıߵ�ʱ�򣬶�ÿһ���ڵ�s����s -> t�����·��
    ��Ȩֵ�������·�е�Ȩֵ����ô��ɾȥ�����ߺ�spfa

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

int n,m;
int head[1010];
int low[1010],vis[1010];
int cnt;
int pre[1010][2];

struct edge
{
    int s;
    int t;
    int next;
    int v;
}e[100100];

void add(int s , int t, int v)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].v=v;
    e[cnt].next = head[s];
    head[s] = cnt++;
}

void init()
{
    clr(pre,-1);
    clr(head,-1);
    cnt=0;
}

int spfa(int state)
{
    clr(low,0x1f);
    clr(vis,0);
    low[1]=0;
    vis[1]=1;
    queue<int> que;
    que.push(1);

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        vis[cur]=0;

        for(int i = head[cur];~i;i=e[i].next)
        {
            int next = e[i].t;
            if(low[next] > low[cur]+e[i].v)
            {
                low[next] = low[cur]+e[i].v;
                if(state)
                {
                    pre[next][0]=cur;
                    pre[next][1]=e[i].v;
                }

                if(!vis[next])
                {
                    vis[next]=1;
                    que.push(next);
                }
            }
        }
    }
    return low[n]==inf?-1:low[n];
}

int gao()
{
    int ans=spfa(1);

    if(ans==-1)
        return ans;

    int cur = n;
    while(pre[cur][0]!=-1)
    {
        int before = pre[cur][0];

        for(int i = head[before];~i;i=e[i].next)
        {
            if(e[i].t == cur && e[i].v == pre[cur][1])
            {
                e[i].v=e[i^1].v=inf;
                int tmp = spfa(0);
                if(tmp==-1)
                    return -1;
                ans = max(ans,tmp);
                e[i].v=e[i^1].v=pre[cur][1];
                break;
            }
        }
        cur=before;
    }
    return ans;
}

int t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i = 0 ; i < m ; i++)
        {
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            add(a,b,v);
            add(b,a,v);
        }
        printf("%d\n",gao());
    }
    return 0;
}
