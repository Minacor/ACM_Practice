/*
 * 题意：
 * 已知一个圆上顺时针放着 n 个点，这 n 个点中有m对顶点之间有连线，
 * 连线要么在园外要么在圆内，每个点最多连接一条边，问是否存在一种连接情况满足所有的边都不相交。
 *
 * 思路：
 * 将每条边看成两个点 i , i+m 分别表示边在内部和在外部，
 * 如果两条边i, j的端点存在序号上的交叉，则这两对点之间的连线一个在外部一个在内部
 * 即如果存在 i，则必然存在 j+m ，如果存在 j ，则必然存在 i+m，如果存在 i+m，则必然存在 j ，如果存在 j+m ，则必然存在 i，
 * 建图的时候连的边为
 * i -> j+m
 * j -> i+m
 * i+m -> j
 * j+m -> i
 *
 * 属于类型：A[x] XOR A[y] ，即一条边在外，另一条边一定在内，反之亦然
 * 求出强连通分量并染色，判断是否存在冲突的情况即可
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
const int MAXN = 10000+10;
const int inf = 522133279;
const int mod = 1000000007;

struct node
{
    int s;
    int t;
}g[1000];

struct edge
{
    int s;
    int t;
    int next;
}e[1000000+10000];

int cnt,head[2000];

void add(int s , int t)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].next = head[s];
    head[s]= cnt++;
}

int dfn[2000],low[2000],totpart,part[2000],clo;
int inst[2000];
stack<int> st;

void tarjan(int cur)
{
    dfn[cur] = low[cur] = ++clo;
    st.push(cur);
    inst[cur]=1;

    for(int i = head[cur] ; ~i ; i=e[i].next)
    {
        int next = e[i].t;
        if(!dfn[next])
        {
            tarjan(next);
            low[cur] = min(low[cur],low[next]);
        }
        else if(inst[next])
            low[cur] = min(low[cur],dfn[next]);
    }

    if(dfn[cur] == low[cur])
    {
        totpart++;
        int tmp;

        do
        {
            tmp = st.top();
            st.pop();
            inst[tmp]=0;
            part[tmp] = totpart;
        }while(cur!=tmp);
    }
}

void init()
{
    clr(head,-1);
    clr(dfn,0);
    clr(part,0);
    clr(inst,0);
    clr(low,0);
    clo=totpart=cnt=0;
    while(!st.empty())
        st.pop();
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i = 0 ; i < m ; i++)
        {
            scanf("%d%d",&g[i].s,&g[i].t);
            if(g[i].s > g[i].t)
                swap(g[i].s,g[i].t);
        }

        for(int i = 0 ; i < m ; i++)
            for(int j = i+1 ; j < m ; j++)
            {
                //交叉边的两种情况
                if( (g[i].s<g[j].t && g[i].s>g[j].s && g[i].t>g[j].t) ||
                    (g[i].t>g[j].s && g[i].s<g[j].s && g[i].t<g[j].t))
                {
                    add(i,j+m);
                    add(j,i+m);
                    add(j+m,i);
                    add(i+m,j);
                }
            }

        for(int i = 0 ; i < 2*m ; i++)
            if(!dfn[i])
                tarjan(i);

        int ok=1;
        for(int i = 0 ; i < m ; i++)
            if(part[i] == part[i+m])
            {
                ok=0;
                break;
            }
        printf("%s\n",(ok?"panda is telling the truth...":"the evil panda is lying again"));
    }
    return 0;
}