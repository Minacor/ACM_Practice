/*
 * 题意：
 * 给一个网络(实质是一副无向图)，每一个节点为一台计算机，
 * 输出：哪一台计算机是割点 ， 移去它以及与其相关联的边之后网络被分成了几块
 *
 * 思路：
 * targin模板
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
using namespace std;
typedef long long LL;
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int n;

struct edge
{
    int s,t;
    int next;
}e[1000*1000*2+100];

int head[1010],cnt;
int subnet[1010];               //subnet[i]表示移去i之后增加了几个连通分量
int vis[1010];

//dfn是深度优先遍历的遍历顺序值，low[i]是从i或i的子孙出发通过回边可以到达的最小优先遍历次序
int low[1010],dfn[1010],clock;

void add(int s,int t)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].next=head[s];
    head[s] = cnt++;

    e[cnt].s=t;
    e[cnt].t=s;
    e[cnt].next=head[t];
    head[t] = cnt++;
}

void init()
{
    clr(head,-1);
    clr(vis,0);
    cnt=0,clock=0;
    clr(low,0);
    clr(dfn,0);
    clr(subnet,0);
    subnet[1]=-1;
    n=0;
}

void tarjin(int cur)
{
    dfn[cur] = low[cur] = ++clock;
    vis[cur] = 1;

    //cur和now邻接，在dfs生成树中就是两种情况
    //1: now是cur的祖先结点，这样(now,cur)就是一条回边
    //2: now是cur的儿子结点
    for(int i = head[cur] ; i+1 ; i = e[i].next)
    {
        int now = e[i].t;
        if(!vis[now])       //now还未被访问，是第二种情形
        {
            tarjin(now);    //tarjin(now) 执行之后，low[now]已经求出

            low[cur] = min(low[now],low[cur]);  //如果有回边的话，low[now] < low[cur]

            if(low[now] >= dfn[cur])        //如果儿子结点不能回溯到cur的祖先，那么移去cur之后
                                            //以now为根的整棵子树都断裂出来，也就是说多了个连通分量
                                            //这里要注意根节点：根节点子女个数>2才是关节点，
                                            //所以之前初始化时令subnet[1]=-1，要比普通点少1
                subnet[cur]++;
        }
        else        //now已被访问，第一种情形，那么now反而是cur的祖先节点，是一条回边
            low[cur] = min(dfn[now],low[cur]);
    }
}

int main()
{
    string line;
    int s,t;
    int tot=0;

    while(getline(cin,line) && line != "0")
    {
        init();
        istringstream iss(line);
        iss >> s >> t;
        n = max(n,max(s,t));
        add(s,t);

        while(getline(cin,line) && line != "0")
        {
            istringstream iss(line);
            iss >> s >> t;
            n = max(n,max(s,t));
            add(s,t);
        }
        cin.ignore();

        tarjin(1);

        int ok=0;
        printf("Network #%d\n",++tot);

        for(int i = 1 ; i <= n ; i++)
            if(subnet[i]>0)
                ok=1,printf("  SPF node %d leaves %d subnets\n",i,subnet[i]+1);
        if(!ok)
            printf("  No SPF nodes\n");
        puts("");
    }
    return 0;
}
