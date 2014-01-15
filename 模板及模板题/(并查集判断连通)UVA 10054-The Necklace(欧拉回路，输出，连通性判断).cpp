/*题意：有一堆散落的项链的的珠子，珠子有可能重复的出现，问我们能否连接成一条项链，要求该项链的每一节的两个珠子要满足；

对无向图：
定义：给定无孤立结点图G，若存在一条路，经过图中每条边一次且仅仅一次，该条路称欧拉路，若存在一条回路，经过图中每边一次且仅仅一次，该回路称为欧拉回路。具有欧拉回路的图称为欧拉图，不是柏拉图。
定理：无向图G具有一条欧拉路，当且仅当G是连通的，且有0个或者是两个奇数度得结点。
推论：无向图G具有一条欧拉回路，当且仅当G是连通的，并且所有结点的度数均为偶数。

一笔画问题就是典型的这类问题：要判定一个图G是否可一笔画出，有两种情况， 从图中某一个结点出发，经过图G中每个边一次再回到该结点，或者是从G中某一个结点出发，经过G中每边一次且仅一次到达另一个结点，分别对应着欧拉回路和欧拉路的问题
 对有向图：
定义：给定有向图G，通过图中每边一次且仅一次的一条单向路（回路），称作单向欧拉路（回路）。
定理：有向图G具有 单向欧拉路，当且仅当它是连通的，而且除两个结点外，每个结点的入度等于出度，但这两个结点中，一个结点的入度比出度大1，另一个结点的入度比出度小1。
定理：有向图G具有一条单向欧拉回路，当且仅当是连通的，且每个结点入度等于出度。
以及Fleury算法：
　　　　（1）任取v0∈V(G)，令P0=v0；
　　　　（2）设Pi=v0e1v1e2...eivi已经行遍，按下面方法来从E(G)-{e1,e2,...,ei}中选
 　　　　    取ei+1：
  　　　　  （a）ei+1与vi想关联；
  　　　　  （b）除非无别的边可供行遍，否则ei+1不应该为Gi=G-{e1,e2,...,ei}中的桥.
　　　　（3）当（2）不能再进行时，算法停止。
例如数据：用电脑把每一步输出，大致理解就是随便找个点然后一它为起点开始遍历，到不能继续时，返回上一层，这是侯输出刚才无法继续遍历的那个店，也就是以他为起点，利用dfs的递归返回时的过程输出，这个算法比回溯快些*/

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
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;

int f[60];
int g[1010][1010];
int use[1010];
int n;

int find(int x)
{
    return (x == f[x]) ? x : f[x] = find(f[x]);
}

int merger(int x , int y)
{
    x = find(x);
    y = find(y);

    if(x!=y)
        f[x]=y;
}

int vis[100],in[100];
queue<int> out;

void oula(int cur)          //寻找其中一个欧拉回路顺序，模板
{
    for(int i = 0 ; i < 60 ; i++)
        if(g[cur][i])
        {
            g[cur][i] = g[i][cur] = g[i][cur]-1;
            oula(i);
            printf("%d %d\n" ,i,cur);
        }

}

int main()
{
    freopen("input.txt","r",stdin);

    int t;
    cin >> t;

    for(int ka = 1  ; ka <= t ; ka++)
    {
        int a,b;
        memset(vis,0,sizeof vis);
        memset(use,0,sizeof(use));
        memset(in,0,sizeof in);
        memset(g,0,sizeof g);

        for(int i = 0 ; i < 60 ; i++)
            f[i] = i;

        cin >>n;

        for(int i = 0 ; i < n ; i++)
        {
            cin >> a >> b;
            g[a][b] = g[b][a] = g[a][b]+1;
            vis[a]=vis[b]=1;
            in[a]++,in[b]++;
            merger(a,b);
        }

        int cnt=0;
        for(int i = 0 ; i < 60 ; i++)
            if(vis[i] && f[i] == i)
                cnt++;
        if(cnt > 1)         //连通的话，只有一个顶点的祖先是自己
            printf("Case #%d\nsome beads may be lost\n",ka);
        else
        {
            int ok = 1;
            for(int i = 0 ; i < 60 ; i++)
            {
                if(vis[i] && in[i]%2)           //欧拉图中所有顶点的度数都是偶数
                {
                    ok = 0;
                    break;
                }
            }

            if(!ok)
                printf("Case #%d\nsome beads may be lost\n",ka);
            else
            {
                printf("Case #%d\n",ka);

                for(int i = 0 ; i < 60 ; i++)
                    if(vis[i])
                        oula(i);
            }
        }

        if(ka < t)
            cout << endl;
    }

    return 0;
}
