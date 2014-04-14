/*
 * 题意：
 * 给定一些人的投票，表示他喜欢哪些人。求满足条件的集合中最多有多少人。
 * 要求：对于集合里的每个人，1:他必须投过票，2:他喜欢的人必须在集合里，3:集合里有人喜欢他
 *
 * 思路：
 * 本题要建立正反两图，利用反图搜索效率特别高,而且第二轮标记用反图大大方便了处理
 * 拓扑排序把所有入度为0的人标记为不考虑(删除)，意味着没人喜欢他或者删掉一些人以后没人喜欢他了
 * 然后dfs反向图，把出度为0的人标记，意味着他没有投票
 * 也同时把投了这些人的人标记掉，因为他喜欢的人不可能在集合里了，把这些人记为A
 * 然后再把投了A的人干掉，以此类推
 * 剩下来的工作就是在剩余子图中寻找最大连通块了，找的是有向图的弱连通分量
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

vector<int> g[MAXN],rg[MAXN];
int del[MAXN];
int in[MAXN],out[MAXN];
int n,m;

void init()
{
    clr(in,0);
    clr(out,0);
    clr(del,0);
    for(int i = 0 ; i <= n ; i++)
        g[i].clear(),rg[i].clear();
}

void topo()
{
    queue<int> que;

    for(int i = 1 ; i <= n ; i++)
        if(!in[i])
            que.push(i),del[i]=1;

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();

        for(int i = 0 ; i < g[cur].size() ; i++)
            if(--in[g[cur][i]] == 0)
            {
                que.push(g[cur][i]);
                del[g[cur][i]]=1;
            }
    }
}

void dfs(int cur)
{
    del[cur]=1;

    for(int i = 0 ; i < rg[cur].size() ; i++)
        if(!del[rg[cur][i]])
            dfs(rg[cur][i]);
}

int num=0;
int vis[MAXN];
void find_max(int cur)
{
    if(del[cur])
        return ;
    num++;
    del[cur]=1;

    for(int i = 0 ; i < g[cur].size() ; i++)      //注意是有向图！而且找的不是强连通而是弱连通,所以找了后继还得找前驱！
        if(!del[g[cur][i]])
           find_max(g[cur][i]);

    for(int i = 0 ; i < rg[cur].size() ; i++)
        if(!del[rg[cur][i]])
           find_max(rg[cur][i]);
}

int main()
{
    //FR;
    int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i = 0 ; i < m ; i++)
        {
            int from,to,num;
            scanf("%d%d",&from,&num);

            while(num--)
            {
                scanf("%d",&to);
                g[from].push_back(to);
                rg[to].push_back(from);
                in[to]++,out[from]++;
            }
        }
        topo();

        for(int i = 1 ; i <= n ; i++)
            if(out[i] == 0)
                dfs(i);

        int ans=-1;
        for(int i = 1 ; i <= n ; i++)
        {
            num=0;
            find_max(i);
            ans = max(ans,num);
        }
        printf("%d\n",ans);
    }
    return 0;
}

