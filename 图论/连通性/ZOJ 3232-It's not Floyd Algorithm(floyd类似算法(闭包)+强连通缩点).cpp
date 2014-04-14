/*
 * 题意：
 * 给一个传递闭包(一个n*n矩阵，g[i][j]=1表示i到j有直接路径，有向图)
 * 要求构造一副包含这个传递闭包的有向图，并且这幅图的边数最少，输出边数
 *
 * 思路：
 * 首先缩点是必须的，一个n元素缩点内的所有元素最少只需要n条边就可互相传递(1除外，1的时候是0)
 * 对于缩点间的边，有可能出现1->2 , 2->3 , 1->3的情况，这个时候1->3就是多余边，要去掉
 * 去边的方法就是用floyd类似算法，如果g[i][j],g[i][k],g[k][j]间有路径，那么就可以去掉g[i][j]
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

int n;
int g[210][210];
int dfn[210],low[210],clo;
int totpart,suo[210],part[210];
stack<int> st;
int inst[210];

void init()
{
    clr(dfn,0);
    clr(suo,0);
    clr(part,0);
    clo=totpart=0;
    clr(inst,0);
    while(!st.empty()) st.pop();
}

void tarjin(int cur)
{
    dfn[cur]=low[cur]=++clo;
    inst[cur]=1;
    st.push(cur);

    for(int i = 1 ; i <= n ; i++)
    {
        if(g[cur][i] && cur!=i)
        {
            if(!dfn[i])
            {
                tarjin(i);
                low[cur] = min(low[cur],low[i]);
            }
            else if(inst[i])
                low[cur] = min(low[cur],dfn[i]);
        }
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
            suo[totpart]++;
        }while(cur!=tmp);
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        init();
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                scanf("%d",&g[i][j]);

        for(int i = 1 ; i <= n ; i++)
            if(!dfn[i])
                tarjin(i);

        int ans=0;
        for(int i = 1 ; i <= totpart ; i++)
            ans += (suo[i]==1?0:suo[i]);

        for(int k = 1 ; k <= n ; k++)
            for(int i = 1 ; i <= n ; i++)
                for(int j = 1 ; j <= n ; j++)
                    if(i!=j&&i!=k&&j!=k&&g[i][j] && g[i][k] && g[k][j]) //注意ijk各不相同
                        g[i][j] = 0;

        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j<= n ; j++)
                if(g[i][j] && part[i]!=part[j])     //不同缩点之间必须要连的边就要计数了
                    ans++;
        printf("%d\n",ans);
    }
    return 0;
}
