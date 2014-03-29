/*
 * 题意：
 * 第一行两个数:有n头牛m条有向边
 * 接下来m行每行两个数a b，表示a认为b很出名,这个认定具有传递性
 * 问有几头牛被所有牛认为是出名的
 *
 * 思路:
 * 一个强联通分量里的牛一定是认为大家都出名的
 * 两个相邻强连通分量AB，A中的一头牛认为B中的一头牛出名，那么A中的这头牛一定认可B中的所有牛
 * 那么对每一个强连通分量缩点，构造缩点图
 * 统计缩点图中出度为0的顶点，如果恰好只有一个，那么这个强连通分量里的牛就被所有牛认可，这个网络的答案就是这个分量中的牛的头数
 * 否则，这个网络中没有被认可的牛，这里已经包括了图不连通的情况
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

int totpart;
int cnt;
int part[100010];       //part[x] : x属于part[x]个强连通分量
int n,m;

struct edge
{
    int s;
    int t;
    int next;
}e[500100*2];

int head[100010];

void add(int s , int t)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].next = head[s];
    head[s] = cnt++;
}

int dfn[100100],low[100100],clo;
int instack[100010];
stack<int> st;

void targin(int cur)
{
    dfn[cur]=low[cur] = ++clo;
    st.push(cur);
    instack[cur]=1;

    for(int i = head[cur] ; i+1 ; i=e[i].next)
    {
        int next = e[i].t;

        if(!dfn[next])
        {
            targin(next);
            low[cur] = min(low[cur],low[next]);
        }
        else if(instack[cur])
            low[cur] = min(low[cur],dfn[next]);
    }

    if(low[cur] == dfn[cur])
    {
        totpart++;
        int tmp;

        do
        {
            tmp = st.top();
            st.pop();
            instack[tmp]=0;
            part[tmp]=totpart;
        }while(cur!=tmp);
    }
}

int out[100010];

void init()
{
    clr(head,-1);
    clr(out,0);
    clr(part,0);
    totpart=clo=cnt=0;
    clr(dfn,0);
    clr(low,0);
    clr(instack,0);
    while(!st.empty()) st.pop();
}

int main()
{
    //FR;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i = 0 ; i < m ; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
        }

        for(int i = 1 ; i <= n ; i++)       //有向图和无向图的处理方法不一样了！必须以所有顶点为起点做dfs
            if(!dfn[i])
                targin(i);

        for(int i = 0 ; i < cnt ; i++)
            if(part[e[i].s] != part[e[i].t])
                out[part[e[i].s]]++;

        int tt=0,pos=-1;
        for(int i = 1 ; i<= totpart ; i++)
            if(out[i] == 0)
            {
                tt++;
                pos=i;
            }

        if(tt==1)
        {
            int fi=0;
            for(int i = 1 ; i <= n ; i++)
                fi += (part[i]==pos);
            printf("%d\n",fi);
        }
        else
            cout << 0 << endl;
    }
    return 0;
}
