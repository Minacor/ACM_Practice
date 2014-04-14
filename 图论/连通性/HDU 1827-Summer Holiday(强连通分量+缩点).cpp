/*
 * 题意：
 * 中文题：
 * 听说lcy帮大家预定了新马泰7日游，Wiskey真是高兴的夜不能寐啊，他想着得快点把这消息告诉大家，
 * 虽然他手上有所有人的联系方式，但是一个一个联系过去实在太耗时间和电话费了。
 * 他知道其他人也有一些别人的联系方式，这样他可以通知其他人，再让其他人帮忙通知一下别人。
 * 你能帮Wiskey计算出至少要通知多少人，至少得花多少电话费就能让所有人都被通知到吗？
 * 注意A能联系到B不代表B能联系到A，即联系是单向的
 *
 * 思路：
 * 一个强连通分量里的所有人都是能互相联系的，通知到一个人就能通知到所有人
 * 对所有强连通分量缩点，这个缩点的权值自然就是所有分量中的点中权值最小的
 * 然后统计缩点图中入度为0的缩点，这些缩点中的其中一人就是必须被直接通知的
 * 自然要通知的最少人数就是入度为0的缩点个数，而最小花费就是这些缩点的权值和
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

int totpart;
int cnt;
int head[1100];
int n,m;

struct edge
{
    int s;
    int t;
    int next;
}e[4400];

int in[1100],v[1100];

void add(int s , int t)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].next = head[s];
    head[s] = cnt++;
}

int dfn[1100],low[1100],clo;
int inst[1100];
int part[1100];
int suov[1100];
stack<int> st;

void tarjin(int cur)
{
    dfn[cur] = low[cur] = ++clo;
    st.push(cur);
    inst[cur]=1;

    for(int i = head[cur] ; i+1 ; i=e[i].next)
    {
        int next = e[i].t;

        if(!dfn[next])
        {
            tarjin(next);
            low[cur] = min(low[next],low[cur]);
        }
        else if(inst[next])
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
            inst[tmp]=0;
            part[tmp] = totpart;
            suov[totpart] = min(suov[totpart],v[tmp]);
        }while(cur!=tmp);
    }
}

void init()
{
    clr(head,-1);
    clr(in,0);
    clr(suov,0x1f);
    clr(part,0);
    clr(dfn,0);
    clr(inst,0);
    totpart=clo=cnt=0;
    while(!st.empty())
        st.pop();
}

int main()
{
    //FR;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i = 1 ; i <= n ; i++)
            scanf("%d",v+i);
        for(int i = 0 ; i < m ; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
        }

        for(int i = 1 ; i <= n ; i++)
            if(!dfn[i])
                tarjin(i);

        for(int i = 0 ; i < cnt ; i++)
            if(part[e[i].s] != part[e[i].t])
                in[part[e[i].t]]++;

        int ans1=0,ans2=0;
        for(int i = 1 ; i <= totpart ; i++)
            if(in[i] == 0)
            {
                ans1++;
                ans2 += suov[i];
            }
        printf("%d %d\n",ans1,ans2);
    }

    return 0;
}
