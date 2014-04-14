/*
 * 题意：
 * 给一副n个节点的完全图，要求对其m个节点的完全子图，找到这样一棵生成树：
 * ∑节点权值/∑边权值 最小，并输出这棵树的节点，按升序排列,如果有多种最小方案，输出字典序最小的组合
 *
 * 思路：
 * dfs枚举所有C(n,m)种情况，对每一种情况使用prim求最小生成树即可
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

vector<int> now,out;
int vis[20];
int n,m;
int low[20];
int point[20],g[20][20];

double solve()
{
    int sum=0;
    for(int i =0 ; i < m ; i++)
        sum += point[now[i]];

    clr(low,0x1f);
    clr(vis,0);
    low[now[0]]=0;
    vis[now[0]]=1;
    int res=0;
    for(int i = 1 ; i < m ; i++)
        low[now[i]] = g[now[i]][now[0]];

    for(int i = 1 ; i < m ; i++)
    {
        int minc = inf,pos;
        for(int j = 0 ; j < m ; j++)
            if(!vis[now[j]] && low[now[j]] < minc)
            {
                minc = low[now[j]];
                pos = now[j];
            }

        vis[pos]=1;
        res += minc;

        for(int j = 0 ; j < m ; j++)
            if(!vis[now[j]] && low[now[j]] > g[pos][now[j]])
                low[now[j]] = g[pos][now[j]];
    }

    return 1.0*res/sum;
}

double minn = inf;

void dfs(int cur)
{
    if(now.size() == m)
    {
        double tt = solve();
        if(tt < minn)
        {
            minn = tt;
            out = now;
        }
        return;
    }

    for(int i = cur+1 ; i <= n ; i++)
    {
        now.push_back(i);
        dfs(i);
        now.pop_back();
    }

}

int main()
{
    FR;
    while(~scanf("%d%d",&n,&m) && (n||m))
    {
        minn = inf;
        out.clear();
        now.clear();
        for(int i = 1 ; i <= n ; i++)
            scanf("%d",&point[i]);
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                scanf("%d",&g[i][j]);

        clr(vis,0);
        dfs(0);
        for(int i = 0 ; i < out.size() ; i++)
            i?printf(" %d",out[i]):printf("%d",out[i]);
        puts("");
    }

    return 0;
}
