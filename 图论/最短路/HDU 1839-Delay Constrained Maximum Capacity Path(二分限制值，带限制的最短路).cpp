/*******************************************************

    题意：
    样例：
    第一个数ka表示有几组case
    接下来每一大块：
    第一行三个数
    n,m,T
    表示n个节点，m条双向路，限制时间T
    接下来m行每行4个数st ed c t
    表示st ed之间的路的容量是c，耗时t

    现在定义路径容量：是组成这条路径中的最小的c值
    然后现在找一条路，使得从1到n容量最大的同时，总耗时<=T

    思路：
    由路径容量的定义很容易想到规定被选择的边的c值下限
    二分c，以t值作为最短路的权值即可

********************************************************/
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

int t;

struct EDGE
{
    int x,y;
    int c,t;
}g[50100];

struct edge
{
    int st;
    int ed;
    int c;
    int t;
    int next;
}e[50100*2];

int head[10010],vis[10010];
LL low[10010];
int cnt;
int n,m,T;

void add(int st , int ed , int c,int t)
{
    e[cnt].st=st;
    e[cnt].ed=ed;
    e[cnt].c=c;
    e[cnt].t=t;
    e[cnt].next = head[st];
    head[st]=cnt++;
}

void init()
{
    cnt=0;
    clr(head,-1);
}

vector<int> vv;
int lim;

int spfa()
{
    for(int i = 0 ; i <= n ; i++)
        low[i]=inf;
    clr(vis,0);

    low[1] = 0;
    vis[1] = 1;

    queue<int> que;
    que.push(1);

    int minc=inf;
    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        vis[cur]=0;

        for(int i =head[cur] ; ~i ; i=e[i].next)
        {
            int nt = e[i].ed;
            if(low[nt] > low[cur] + e[i].t && e[i].c >= lim)
            {
                low[nt] = low[cur]+e[i].t;
                minc = min(minc,e[i].c);

                if(!vis[nt])
                {
                    vis[nt]=1;
                    que.push(nt);
                }
            }
        }
    }

    return minc;
}

int gao()
{
    init();
    sort(vv.begin(),vv.end());
    for(int i = 0 ; i < m ; i++)
    {
        add(g[i].x,g[i].y,g[i].c,g[i].t);
        add(g[i].y,g[i].x,g[i].c,g[i].t);
    }

    int l=vv[0],r =vv[vv.size()-1];
    int tmp;

    int mid=0;
    do
    {
        mid =MID(l,r);
        lim = mid;

        spfa();

        if(low[n] <= T)
            l = mid+1,tmp=mid;
        else
        {
            r = mid-1;
        }
    }while(l<=r);

    return tmp;
}

int main()
{
    int ka;
    scanf("%d",&ka);

    while(ka--)
    {
        scanf("%d%d%d",&n,&m,&T);
        vv.clear();

        for(int i = 0 ; i < m ; i++)
        {
            scanf("%d%d%d%d",&g[i].x,&g[i].y,&g[i].c,&g[i].t);
            vv.push_back(g[i].c);
        }
        printf("%d\n",gao());
    }
    return 0;
}
