/*
 * 题意：
 * 输入：
 * 第一行一个数表示有n个学校
 * 接下来n行,第i行表示i这个学校列表里能联系到的学校,以0结束，联系是单向的
 * 问题有两个：
 * 1：至少选择几个学校发送信息，能使所有学校能够接收到消息
 * 2：至少在某些学校添加多少个联系使得任意选择一个学校能够使其通知到所有学校
 *
 * 思路：
 * 首先强连通缩点构造缩点图,缩点图一共totpart个点
 * 统计图中入度为0的点的个数ans1和出度为0的个数ans2
 * 答案1就是ans1，答案2，如果有多个强连通分量，那么就是max(ans1,ans2),只有1个的话就是0
 * 答案2的得出证明可以看：
 * http://www.cnblogs.com/kuangbin/archive/2011/08/07/2130277.html
 * 简单地说，得保证添加边以后没有入度=0出度=0的点，然后一个出度=0的点可以向下一个连通分支的入度=0的点连一条边
 * 这样就同时抵消了一入一出两个点，最后哪个有剩余，就任意在其余连通分支中选点连到哪个就可以了
 * 当缩点图中只有一个点时，不能连边到下一个分量(因为下一个分量就是自己),而且无需连边，所以要特判为0
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
}e[20000];

int in[1100],out[1100];

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
        }while(cur!=tmp);
    }
}

void init()
{
    clr(head,-1);
    clr(in,0);
    clr(out,0);
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
    while(~scanf("%d",&n))
    {
        init();
        for(int i = 1 ; i <= n ; i++)
        {
            int a;
            while(scanf("%d",&a) && a)
                add(i,a);
        }

        for(int i = 1 ; i <= n ; i++)
            if(!dfn[i])
                tarjin(i);

        for(int i = 0 ; i < cnt ; i++)
            if(part[e[i].s] != part[e[i].t])
                in[part[e[i].t]]++,out[part[e[i].s]]++;

        int ans1=0,ans2=0;
        for(int i = 1 ; i <= totpart ; i++)
        {
            if(in[i] == 0)
                ans1++;
            if(out[i] == 0)
                ans2++;
        }

        printf("%d\n%d\n",ans1,(totpart==1?0:max(ans1,ans2)));
    }

    return 0;
}
