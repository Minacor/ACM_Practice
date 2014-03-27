/*
 * 题意：
 * 给一幅图，每条边按照输入编号，输出为桥的边的编号
 *
 * 思路：
 * tarjin求桥
 * (u,v)是桥，当且仅当(u,v)为生成树中的边，且dfn[u]<low[v]
 *
 * 注意：
 * 本题有重边，而重边一定不会是桥，输入加边的时候要判断一下
 * 输出边的序号的时候要从小到大输出！
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

int t;
int n,m;

struct edge
{
    int s,t;
    int next;
    int chongbian;
    int id;
}e[100000*2+100];

int head[10000+100],cnt;
int low[10100],dfn[10100],clo;
int vis[10100];                                 //0 未访问过，1 已访问过但还未访问完其子节点 ，2 已访问完其子节点,其实完全没必要设置vis

void add(int s , int t , int id)
{
    for(int i = head[s] ; i+1 ; i=e[i].next)            //判断重边，是的话就要标记,tarjin的时候自动略过
        if(t == e[i].t)
        {
            e[i].chongbian=e[i^1].chongbian=1;
            return ;
        }

    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].next = head[s];
    e[cnt].chongbian=0;
    e[cnt].id=id;
    head[s] = cnt++;

    e[cnt].s=t;
    e[cnt].t=s;
    e[cnt].next = head[t];
    e[cnt].chongbian=0;
    e[cnt].id=id;
    head[t] = cnt++;
}

vector<int> st;

void targin(int cur ,int fa)
{
    low[cur] = dfn[cur] = ++clo;
    vis[cur]=1;

    for(int i = head[cur] ; i+1 ; i = e[i].next)
    {
        int next = e[i].t;
        if(!vis[next])
        {
            targin(next,cur);

            low[cur] = min(low[next],low[cur]);

            if(low[next] > dfn[cur] && e[i].chongbian == 0)
                st.push_back(e[i].id);
        }
        else if(fa != next && vis[next] == 1)       //求桥的时候要判断next是不是祖先节点(防止访问重边，因为即使已经去重了，add时候加的是双向边)，而求割点的时候不用
            low[cur] = min(dfn[next],low[cur]);
    }
    vis[cur]=2;
}

int main()
{
    //FR;
    scanf("%d",&t);

    while(t--)
    {
        clo=0;
        clr(low,0);
        clr(dfn,0);
        clr(head,-1);
        clr(vis,0);
        st.clear();
        cnt=0;

        scanf("%d%d",&n,&m);
        for(int i = 0 ; i < m ; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b,i+1);
        }

        targin(1,-1);

        printf("%d",st.size());
        if(!st.empty())
        {
            sort(st.begin(),st.end());
            printf("\n%d",st[0]);
            for(int i = 1 ; i < st.size() ; i++)
                printf(" %d",st[i]);
        }
        puts("");

        if(t) puts("");
    }
    return 0;
}
