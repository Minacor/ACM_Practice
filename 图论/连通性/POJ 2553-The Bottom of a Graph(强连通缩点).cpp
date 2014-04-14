/*
 * 题意：
 * 给一副n顶点m有向边的有向图，顶点从(1~n)编号
 * 从小到大输出这样的顶点v：
 * 假设v能到达w,那么w也必须能够到达v
 *
 * 思路:
 * 显然一个强连通分量里的点能够互相到达，满足这个条件
 * 但是如果这个分量里有某些顶点还能到达分量以外的顶点，那么这个分量里的所有点不满足条件
 * 这样的话，我们把强连通分量缩点构造缩点图，如果某个点的出度非0，那么不满足条件
 * 反之则这个缩点代表的分量里的所有顶点满足条件
 * 所以题目转化为统计缩点图中出度为0的所有顶点，找到一个就准备输出
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

int n,m;
int clo,cnt,totpart;
int head[5010],low[5010],dfn[5010],part[5010],instack[5010],out[5010];
stack<int> st;

void init()
{
    clr(head,-1);
    clr(dfn,0);
    clr(part,0);
    clr(out,0);
    clr(instack,0);
    clo=cnt=totpart=0;
    while(!st.empty())
        st.pop();
}

struct edge
{
    int s;
    int t;
    int next;
}e[5010*5010*2];

void add(int s , int t)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].next = head[s];
    head[s] = cnt++;
}

void tarjin(int cur)
{
    dfn[cur] = low[cur]=++clo;
    st.push(cur);
    instack[cur]=1;

    for(int i = head[cur] ; i+1 ; i=e[i].next)
    {
        int next = e[i].t;
        if(!dfn[next])
        {
            tarjin(next);
            low[cur] = min(low[next],low[cur]);
        }
        else if(instack[next])
            low[cur] = min(low[cur],dfn[next]);
    }

    if(dfn[cur] == low[cur])
    {
        int tmp;
        totpart++;
        do
        {
            tmp = st.top();
            st.pop();
            part[tmp] = totpart;
            instack[tmp]=0;
        }while(tmp!=cur);
    }
}

int solve()
{
    for(int i = 0 ; i < cnt ; i++)
        if(part[e[i].s] != part[e[i].t])
            out[part[e[i].s]]++;

    vector<int> ans;
    for(int i = 1 ; i <= totpart ; i++)
    {
        if(out[i] == 0)
        {
            for(int j = 1 ; j <= n ; j++)
                if(part[j] == i)
                    ans.push_back(j);
        }
    }

    sort(ans.begin(),ans.end());
    if(!ans.empty()) printf("%d",ans[0]);
    for(int i = 1 ; i < ans.size() ; i++)
        printf(" %d",ans[i]);
    puts("");

}

int main()
{
    //FR;
    while(~scanf("%d",&n) && n)
    {
        init();
        scanf("%d",&m);
        for(int i = 0 ; i < m ; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
        }

        for(int i = 1 ; i <= n ; i++)
            if(!dfn[i])
                tarjin(i);
        solve();
    }
    return 0;
}
