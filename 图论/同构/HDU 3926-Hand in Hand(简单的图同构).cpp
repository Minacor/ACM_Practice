/*
 * 题意：
 * 给两副无向图，图中的顶点最大度为2，判断是否是同构图
 *
 * 思路：
 * 顶点最大度为2，这意味着一幅图中有多个连通分量的话，每个连通分量除了链(包括单独点)就是环
 *
 * 这样的话，只要并查集合并同一链和同一环上的点，然后排序比较一下
 * 如果两幅图的环数链数相同，且不同顶点数量的链数相同，不同顶点数量的环数相同，那么这两幅图就同构
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
    int nodenum;                            //这个分量的顶点数
    int isloop;                             //这个分量是否为环

    bool operator<(const edge &b)const      //排序顺序无所谓，只要两幅图的排序规则相同就行了
    {
        if(nodenum == b.nodenum)
            return isloop < b.isloop;
        return nodenum < b.nodenum;
    }
}g[2][10100];

int f[2][10100];

int find(int id,int x)
{
    return (x!=f[id][x]) ? f[id][x] = find(id,f[id][x]) : x;
}

void merger(int id , int x , int y)
{
    x = find(id,x);
    y = find(id,y);

    if(x == y)          //如果是环就标记
        g[id][x].isloop = 1;
    else                //大树合并小树，这里必须规定一个合并规则，防止操作混乱使得最后比较出错
    {
        if(g[id][y].nodenum >= g[id][x].nodenum)
        {
            f[id][x]=y;
            g[id][y].nodenum += g[id][x].nodenum;
        }
        else
        {
            f[id][y]=x;
            g[id][x].nodenum += g[id][y].nodenum;
        }
    }
}

int main()
{
    int n1,n2,m1,m2;
    int st,ed;
    int t;
    scanf("%d",&t);

    for(int ka = 1 ; ka <= t ; ka++)
    {
        for(int i = 0 ; i < 2 ; i++)
            for(int j = 1 ; j <= 10010 ; j++)
            {
                g[i][j].isloop=0;
                g[i][j].nodenum=1;
                f[i][j]=j;
            }

        scanf("%d%d",&n1,&m1);
        for(int i = 0 ; i < m1 ; i++)
        {
            scanf("%d%d",&st,&ed);
            merger(0,st,ed);
        }
        scanf("%d%d",&n2,&m2);
        int ok = (n2==n1)&&(m2==m1);            //顶点或边数不同的一定不是同构图

        for(int i = 0 ; i < m2 ; i++)
        {
            scanf("%d%d",&st,&ed);
            if(!ok) continue;
            merger(1,st,ed);
        }

        if(ok)
        {
            sort(g[0]+1,g[0]+1+n1);
            sort(g[1]+1,g[1]+1+n2);

            for(int i = 1 ; i <= n1 ; i++)
                //  比较，同构情况下g[0]和g[1]应该是一模一样的
                if((g[0][i].nodenum != g[1][i].nodenum) || (g[0][i].isloop!=g[1][i].isloop))
                {
                    ok=0;
                    break;
                }
        }

        printf("Case #%d: %s\n",ka,(ok?"YES":"NO"));
    }

    return 0;
}
