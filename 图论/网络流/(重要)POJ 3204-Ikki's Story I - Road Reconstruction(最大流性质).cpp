/*
 * 题意：
 * 题目给出一幅图，顶点编号(0~n-1)，这幅图中，改变某一条边就能使最大流增加
 * 注意每次只更改一条边，也就是说 0 -> 1 -> 2 -> 3 -> 4 这几条边都是满流时，虽然增大所有4条边能够使最大流增加
 * 但是仅改变一条边是不行的，就不满足题意了
 * 问这样的边有几条
 *
 * 思路：
 * 最大流的性质，首先这样的边是满流的，也就是e[i].c == 0 , 其反向边(残留网络的对应边)是e[i].c == e[i].oc , oc为原始容量
 * 然后它前面的边和后面的边都不是满流，这条边就是符合条件的了
 * 这样，在dinic构造完最大流后，从src开始顺着dfs，并从tar开始逆序dfs，标记能到达的点，如果一条边是满流，且其s端是顺序dfs的标记，t端是逆dfs标记，这条边就是符合条件的边
 * 显然遇到一条满流边，不论是哪种dfs都不会进行下去了，所以不会出现标记重叠的情况
 * 所以我用仅用一个color数组记录标记，1是顺序dfs的标记，2是逆序dfs的标记
 * 一旦遇到一条满流边就执行标记操作
 * 注释掉的代码的标记法也可以
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
#define FO (freopen("out.txt","w",stdout))
#define clr(a,b) memset(a,b,sizeof(a))
#define mkp make_pair
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 1000000;
const int inf = 522133279;
const int mod = 1000000007;

int n,m;
int tar,src;

struct edge
{
    int s;
    int t;
    int next;
    int c;
    int oc;
}e[5100*2];

int cnt,head[510];
int lv[510];
int color[510];

void add(int s , int t , int c)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].c = e[cnt].oc = c;
    e[cnt].next = head[s];
    head[s] = cnt++;

    e[cnt].s=t;
    e[cnt].t=s;
    e[cnt].c = 0;
    e[cnt].oc = c;
    e[cnt].next = head[t];
    head[t]=cnt++;
}

bool bfs()
{
    queue<int> que;
    clr(lv,0);
    lv[src]=1;
    que.push(src);

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();

        for(int i = head[cur] ; i+1 ; i = e[i].next)
        {
            if(lv[e[i].t]==0 && e[i].c > 0)
            {
                lv[e[i].t] = lv[cur]+1;
                if(tar == e[i].t) return 1;
                que.push(e[i].t);
            }
        }
    }
    return 0;
}

int dfs(int cur , int totflow)
{
    int ret = 0;
    if(cur == tar || totflow == 0)
        return totflow;

    for(int i = head[cur] ; i+1 ; i = e[i].next)
    {
        if(totflow == 0) break;
        if(lv[e[i].t] == lv[cur]+1 && e[i].c > 0)
        {
            int f = dfs(e[i].t , min(totflow,e[i].c));
            totflow -= f;
            e[i].c -= f;
            e[i^1].c += f;
            ret += f;
        }
    }
    return ret;
}

int vis[510];

void odfs(int cur)
{
    vis[cur]=1;
    for(int i = head[cur] ; i+1 ; i = e[i].next)
    {
        if(!(i&1)&&!vis[e[i].t])        //其实这里的!(i&1)和下面一个dfs的(i&1)都不需要
                                        //因为对于一个节点做正边和反边的情况，如  0 <- 1 -> 2，是先遍历2
                                        //的，然后逆序的时候，由于2被先访问了，所以只能访问0了
        {
            if(e[i].c == 0)     //遇到满流边就执行标记
            {
                color[cur]=1;
                //return;
            }
            else
                odfs(e[i].t);
        }
    }
}

void redfs(int cur)
{
    vis[cur]=1;
    for(int i = head[cur] ; i+1 ; i = e[i].next)
    {
        if((i&1)&&!vis[e[i].t])
        {
            if(e[i].c == e[i].oc)
            {
                color[cur]=2;
                //return;       千万不可return，因为当前边代表的是下一条边，而非cur做尾结点的边，一条"下一条边走不通了"，另一条还是可能走通的
            }
            else
                redfs(e[i].t);
        }
    }
}

//int visa[510];
//void dfsa(int u)
//{
//    visa[u]=1;
//    for(int i = head[u] ; i+1 ; i = e[i].next)
//    {
//        if(!visa[e[i].t] && e[i].c)
//            dfsa(e[i].t);
//    }
//}
//
//int visb[510];
//void dfsb(int u)
//{
//    visb[u]=1;
//    for(int i = head[u] ; i+1 ; i = e[i].next)
//    {
//        if(!visb[e[i].t] && e[i].c!=e[i].oc)
//            dfsb(e[i].t);
//    }
//}

int dinic()
{
    int ret=0;
    while(bfs())
    {
        int tmp = dfs(src,inf);
        if(tmp == 0)
            break;
        ret+=tmp;
    }
    return ret;
}

int main()
{
    //FR;
    while(~scanf("%d%d",&n,&m))
    {
        tar=n-1,src=0;
        clr(head,-1);
        cnt=0;
        clr(color,0);

        for(int i = 0 ; i < m ; i++)
        {
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            add(a,b,v);
        }

        //cout << dinic() << endl;
        dinic();
        clr(vis,0);
        odfs(src);
        clr(vis,0);
        redfs(tar);

        int out=0;
        for(int i = 0 ; i < cnt ; i += 2)   //枚举正向边
        {
            int s = e[i].s , t = e[i].t;
            if(e[i].c==0 && color[s]==1 && color[t]==2) //s端标记1，t端标记2的满流边
                out++;
        }
        printf("%d\n",out);
    }
    return 0;
}
