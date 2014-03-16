/*
 * 题意：
 * 有N头牛，F种食物可以制作，D种饮料可以制作
 * 然后每行代表一头牛的喜好，开头两个数fi,di表示这头牛喜欢fi种食物，di种饮料，接下来fi个数表示喜欢的食物编号，di个数表示喜欢的饮料的编号
 * 现在主人使用最优决策制作出F种食物和D种饮料，问怎么喂才能使尽可能多的牛喂饱(喂饱=一份食物一份饮料，且一头牛最多消耗一份食物和一份饮料)
 * 输出最多喂饱的牛数
 *
 * 思路：
 * 本题关键是建图，图建完以后就是裸dinic
 * 建图方法，设1+F+D+2*N+1个结点，1表示源点，1+F+D+2*N+1表示汇点
 * 1+1 ~ 1+F表示食物结点，1+F+1 ~ 1+F+N表示牛的编号，1+F+N+1 ~ 1+F+2*N也表示牛的编号，为什么这样后面说明
 * 1+F+2*N+1 ~ 1+F+2*N+D表示饮料编号
 *
 * 然后被喜欢的食物指向喜欢它的牛的所有边，牛i指向牛i的所有边，牛指向它喜欢的饮料的所有边，源点到所有食物，饮料到所有汇点的边，权值全设为1
 *
 * 建图解释：
 * 首先，这幅图被分为几个模块，从左到右依次为：食物制作模块(src-F边集)，喂食物模块(F-N1边集)，牛吃食物模块(N1-N2边集)，喂饮料模块(N2-D边集)和牛喝饮料模块(D-tar边集)
 * 然后解释为什么设权值为1，第一：人做的食物和水都是一份；第二：牛最多吃一份食物(水)，就算有多份食物指向牛，由于下一条边(牛指出的边，即牛吃食物(喝饮料)模块)为1，意味着最后只能流出1的流量，即吃掉其中一份食物，水的指出同理
 * 这样就能想到为什么要设两次牛了，就是要通过牛-牛边控制流量为1，即通过食物选择模块后，保证一头牛只吃了一份食物
 * 然后吃完食物流量为1了，就只能选一条路喝饮料，最后饮料流出的也是唯一一条边，表示这种饮料最终只能被一头牛选择
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
using namespace std;
typedef long long LL;
const int MAX = 100+100+2*100+100;
const int inf = 522133279;
const int mod = 1000000007;

int F,D,N;
int g[MAX][MAX];
int lv[MAX];

bool bfs(int src , int tar)
{
    clr(lv,0);
    queue<int> que;
    que.push(src);
    lv[src]=1;

    while(!que.empty())
    {
        int cur = que.front(); que.pop();

        for(int i = src ; i <= tar ; i++)
            if(!lv[i] && g[cur][i])
            {
                lv[i]=lv[cur]+1;
                if(i == tar) return 1;
                que.push(i);
            }
    }
    return 0;
}

int dfs(int cur , int src , int tar , int totflow)
{
    int ret=0;
    if(cur==tar||!totflow)
        return totflow;

    for(int i = src ; i <= tar ; i++)
    {
        if(totflow==0) break;
        if(g[cur][i]&&lv[cur]+1==lv[i])
        {
            int f = min(totflow,g[cur][i]);
            int flowdown = dfs(i,src,tar,f);
            ret+=flowdown;
            totflow-=flowdown;
            g[cur][i]-=flowdown;
            g[i][cur]+=flowdown;
        }
    }
    return ret;
}

int dinic(int src , int tar)
{
    int ret=0;
    while(bfs(src,tar))
    {
        int tmp = dfs(src,src,tar,D+F);
        if(!tmp) break;
        ret += tmp;
    }
    return ret;
}

int main()
{
    while(~scanf("%d%d%d",&N,&F,&D))
    {
        int src=1,tar=1+F+D+2*N+1;

        for(int i = 1 ; i <= F ; i++)   //src-F边集
            g[src][src+i]=1;
        for(int i = 1+2*N+F+1; i < tar ; i++)   //D-tar边集
            g[i][tar]=1;
        for(int i = 1 ; i <= N ; i++)
        {
            g[src+F+i][src+F+i+N]=1;        //N1-N2边集
            int fi,di;
            scanf("%d%d",&fi,&di);

            int tmp;
            while(fi--)     //F-N1边集
                scanf("%d",&tmp),g[src+tmp][src+F+i]=1;
            while(di--)     //N2-D边集
                scanf("%d",&tmp),g[src+F+i+N][src+F+2*N+tmp]=1;
        }

        printf("%d\n",dinic(src,tar));
    }
    return 0;
}

