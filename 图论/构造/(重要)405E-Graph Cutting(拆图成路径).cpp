/*
 * 题意：
 * 给定一副无向连通图，要求把这幅图分割成若干个长度为2的路径
 *
 * 思路：
 * 首先，如果这幅图是奇数条边的一定不可以，偶数条边的一定可以
 *
 * 函数dfs(v)处理未被访问的那些边，它能够分离那些连接着两条边的顶点v
 * 如果连接的边是奇数的，那么函数会首先匹配集合中的其余边,除了(u,v)
 * 这个函数就会返回u，表示父函数将会把(u,v)安排给另外的匹配
 *
 * 函数dfs(v)的工作方法：
 * 找到邻接当前顶点的所有未被访问过的边，把这些边压入adjacent集合,并标记访问
 * 对集合adjacent中的每个顶点u,调用dfs(u)
 * 假设dfs(u)返回一个顶点w，那么说明我们可以拆出(v u w)这条路径
 * 如果返回0，就要把u这个顶点加入到unpair集合中
 * 既然(v,u)目前不在任何路径中，我们可以匹配unpair和v构成的边集中的任意两条边
 * 此时的路径就是集合中任意两点u,w和v构成的路径(u,v,w)
 * 最后如果集合unpair中剩余一个顶点，那么这个函数就返回这个顶点，否则返回0
 *
 * 猜测的策略：
 * 贪心，能够找到(1→2→3)这样的就输出
 * 剩余不能的，比如就剩下(1→4)没被访问了 就把4压到集合里
 * 回溯到父函数的时候，就要把4这个点先给匹配了，否则很可能出现(1→4)被孤立的情况
 * 若剩余多条没被匹配的，当然就要先互相匹配了(1←2→3 类似的小二叉树情况)，因为dfs序靠前的顶点很有可能要"照顾"它们直接相连的其余边
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

struct edge
{
    int s;
    int t;
    int next;
    int vis;
}e[100100*2];

int n,m;
int cnt,head[100100];
int color[100100];

void add(int s , int t)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].next=head[s];
    e[cnt].vis=0;
    head[s] = cnt++;
}

int dfs(int cur)
{
    queue<int> adjacent;
    for(int i = head[cur] ; ~i ; i=e[i].next)
    {
        if(!e[i].vis)
        {
            adjacent.push(e[i].t);
            e[i].vis = e[i^1].vis = 1;
        }
    }

    queue<int> unpair;

    while(!adjacent.empty())
    {
        int u = adjacent.front();
        adjacent.pop();

        int w = dfs(u);

        if(w == 0)
            unpair.push(u);
        else
            printf("%d %d %d\n" , cur,u,w);
    }

    while(unpair.size() >= 2)
    {
        int u = unpair.front();
        unpair.pop();
        int v = unpair.front();
        unpair.pop();
        printf("%d %d %d\n",u,cur,v);
    }

    if(unpair.size())
        return unpair.front();
    return 0;
}

int main()
{
    scanf("%d%d",&n,&m);
    clr(head,-1);
    for(int i = 0 ; i < m ; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }

    if(m%2)
        puts("No solution");
    else
        dfs(1);

    return 0;
}
