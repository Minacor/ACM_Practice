/*
 * 题意：
 * 一副n*m的图上有若干个man和若干个house，数量相等，一个man只能住一个house
 * man每走一格花费1元钱，问所有man住进house的最小花费是多少
 *
 * 思路，一个man(x1,y1)到一个house(x2,y2)的距离为abs(x1-x2)+abs(y1-y2)
 * 建图，设立超级源点src和超级汇点tar
 * src与所有man建边，花费cost为0，容量c为1
 * 所有house与tar建边，花费为0，容量为1
 * 所有man与所有house之间建边，花费为他们之间的距离，容量为1
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

string g[110];
int n,m;
int man,house;
int src,tar;
int maxflow;
vector< pair<int,int> > manpos,housepos;

struct edge
{
    int s,t;
    int cost;
    int c;
    int next;
}e[110*110*2];

int head[10010],cnt;

void add(int s , int t , int c , int cost)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].c=c;
    e[cnt].cost=cost;
    e[cnt].next=head[s];
    head[s] = cnt++;

    e[cnt].s=t;
    e[cnt].t=s;
    e[cnt].c=0;
    e[cnt].cost=-cost;      //反向边花费为-cost
    e[cnt].next=head[t];
    head[t] = cnt++;
}

int dis(int x,int y)
{
    return abs(manpos[x].first-housepos[y].first)+abs(manpos[x].second-housepos[y].second);
}

int low[11000],vis[11000],pre[11000],path[11000];   //pre记录被选路径中的前驱结点，path记录哪些边被选取了
int ans;

bool spfa()             //寻找所有可行流中的花费最小者
{
    clr(low,0x1f);
    clr(vis,0);
    clr(pre,-1);

    low[src]=0;

    queue<int> que;
    que.push(src);
    vis[src] = 1;

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        vis[cur]=0;

        for(int i = head[cur] ; i+1 ; i = e[i].next)
        {
            int next = e[i].t;
            if(e[i].c > 0 && low[next] > low[cur]+e[i].cost)    //特别注意不要遗漏e[i].c > 0！！
            {
                low[next] = low[cur]+e[i].cost;

                //记录前驱结点和这条被选择的边
                pre[next]=cur;
                path[next]=i;

                if(!vis[next])
                {
                    que.push(next);
                    vis[next]=1;
                }
            }
        }
    }

//    if(low[tar] != inf)
//        ans += low[tar];
    return low[tar] != inf;         //若tar没被遍历到，自然就是不存在可行流了
}

int arg()           //沿着被选择的路径调整流量
{
    int c = inf,flow=0;

    //得出这条可行流被更新的流量
    for(int i = tar ; pre[i]+1 ; i = pre[i])
    {
        edge cur = e[path[i]];
        c = min(c,cur.c);
    }

    //调整流量
    for(int i = tar ; pre[i]+1 ; i = pre[i])
    {
        e[path[i]].c -= c;
        e[path[i]^1].c += c;
        flow += e[path[i]].cost*c;          //最小花费
    }
    maxflow += c;           //最大流
    return flow;
}

int maxCostFlow()
{
    int f=0;
    while(spfa())
        f += arg();
    return f;
}

int main()
{
    while(cin >> n >> m && (n||m))
    {
        clr(head,-1);
        cnt=0;
        man=house=0;
        ans = 0;
        maxflow=0;
        manpos.clear();
        housepos.clear();
        for(int i = 0 ; i < n ; i++)
        {
            cin >> g[i];
            for(int j = 0 ; j < g[i].size() ; j++)
            {
                if(g[i][j] == 'm')
                {
                    man++;
                    manpos.push_back(mkp(i,j));
                }
                if(g[i][j] == 'H')
                {
                    house++;
                    housepos.push_back(mkp(i,j));
                }

            }
        }
        src = 0 , tar = man+house+1;

        for(int i = 1 ; i <= man ; i++)
            add(src,i,1,0);
        for(int i = 1 ;i <= house ; i++)
            add(i+man,tar,1,0);
        for(int i = 1 ; i <= man ; i++)
            for(int j = 1+man ; j < tar; j++)
            {
                int tmp = dis(i-1,j-man-1);
                add(i,j,1,tmp);
            }

        cout << maxCostFlow() << endl;
        //cout << maxflow << endl;
    }
    return 0;
}
