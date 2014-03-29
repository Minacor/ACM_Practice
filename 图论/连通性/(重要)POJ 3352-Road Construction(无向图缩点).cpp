/*
 * 参考资料：http://blog.csdn.net/lyy289065406/article/details/6762370
 *
 * 题意：
 * 给一副无向图，施工队对其中任意一条路进行维修时，这条路不能走通，
 * 这样就导致了有时候不能从一个景点到达另外一个景点，这时候就需要修额外的路来连通这些景点
 * 为了保证在最后的网络中，当任意某一条路在维修时，剩下的道路能保证任何两个景点之间连通
 * 求最小需要修的额外路数
 *
 * 思路：
 * tarjin求low函数+缩点
 * 题目转化为至少添加几条边使得一副图变成双连通图
 * 首先利用tarjin得出low函数
 * 【没有重边的情况下，low值相同的点一定属于同一双连通分量】，有重边的low值不同也可能属于同一双连通分量
 * 本题没有重边，所以可以直接依据low值判定
 * 【所有属于同一双联通分量的点可以缩成一点，称为缩点】
 * 本题就转化为求至少添加几条边使得一副缩点图变成双连通图
 *
 * 然后有个定理：
 * 若要使得任意一棵树，在增加若干条边后，变成一个双连通图，那么
 * 至少增加的边数 =（ 这棵树总度数为1的结点数 + 1 ）/ 2
 *
 * 缩点图度数的计算法：
 * 两两枚举图G的直接连通的点，只要这两个点不在同一个【缩点】中，那么它们各自所在的【缩点】的度数都+1
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
int g[1010][1010];
int low[1010],dfn[1010],clo;

void tarjin(int cur,int fa)
{
    dfn[cur] = low[cur] = ++clo;

    for(int i = 1 ; i <= n ; i++)
    {
        if(g[cur][i])
        {
            if(!dfn[i])
            {
                tarjin(i,cur);
                low[cur] = min(low[i],low[cur]);
            }
            else if(fa != i)
                low[cur] = min(low[cur],dfn[i]);
        }
    }
}

int f[1010];

int solve()
{
    clr(f,0);

    for(int i = 1 ; i <= n ; i++)
        for(int j = i+1 ; j <= n ; j++)
        {
            if(g[i][j])
            {
                if(low[i] != low[j])            //缩点度数的计算法
                    f[low[i]]++,f[low[j]]++;
            }
        }

    int cnt=0;
    for(int i = 1 ; i <= n ; i++)
        if(f[i] == 1)
            cnt++;
    return cnt;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        clr(low,0);
        clr(dfn,0);

        for(int i = 0 ; i < m ; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a][b] = g[b][a]=1;
        }

        tarjin(1,-1);
        cout << (solve()+1)/2 << endl;
    }
    return 0;
}
