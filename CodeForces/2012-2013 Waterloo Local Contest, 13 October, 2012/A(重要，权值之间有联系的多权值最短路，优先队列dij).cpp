/*
 * 题意：
 * 给一个图，有一些路是在户外的，另外一些在室内
 * 输出从s到t的最短户外距离(户外路长度总和)和总距离，前者有多条相同时要求总距离最小
 *
 * 思路：
 * 多权值最短路径，不过本题的两个权值是有联系的，所以不能直接模板硬上！！
 * 算法采用优先队列dijkstra ; spfa会超时
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
#define FR (freopen("in.txt","r",stdin))
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;
const int inf = 522133279;

struct node
{
    int id;         //作为队列中的顶点时：当前顶点
    int in;         //作为队列中的顶点时：当前顶点到起点的outdoor最短距离
    int out;        //作为队列中的顶点时：当前顶点到起点的总最短距离

    node(){}

    node(int _id , int _in , int _out)
    {
        id=_id ; in = _in ; out = _out;
    }

    bool operator < (const node &b)const        //优先队列默认大顶堆，注意
    {
        if(in == b.in)
            return out > b.out;
        return in > b.in;
    }
}g[4010][4010];

int n,m,p;
int out[4010],vis[4010],total[4010];

void dij(int s , int t)
{
    for(int i = 1 ; i <= n ; i++)
    {
        out[i]=total[i] = inf;
        vis[i]=0;
    }

    priority_queue<node> que;
    out[s]=total[s]=0;
    que.push(node(s,0,0));

    while(!que.empty())
    {
        node cur = que.top();
        que.pop();

        if(vis[cur.id])
            continue;
        vis[cur.id]=1;

        for(int i = 1 ; i <= n ; i++)
        {
            if(g[cur.id][i].in != inf)      //如果有户外的路，应优先选择户外的路
            {
                if(out[cur.id] < out[i] || out[i]==out[cur.id] && total[i] > total[cur.id]+g[cur.id][i].in)
                {
                    out[i]=out[cur.id];     //注意这里，对于out来说，把室内的路全部看做长度为0！！即g[cur.id][i].in=0
                    total[i] = total[cur.id]+g[cur.id][i].in;
                    que.push(node(i,out[i],total[i]));
                }
            }
            else if(g[cur.id][i].out != inf)    //否则只能选择户外的
            {
                if(out[i] > out[cur.id]+g[cur.id][i].out || out[i]==out[cur.id]+g[cur.id][i].out && total[i] > total[cur.id]+g[cur.id][i].out)
                {
                    out[i]=out[cur.id]+g[cur.id][i].out;    //户外的长度仍旧需要计算
                    total[i] = total[cur.id]+g[cur.id][i].out;
                    que.push(node(i,out[i],total[i]));
                }
            }
        }
    }

    printf("%d %d\n",out[t],total[t]);
}

int main()
{
    FR;

    while(~scanf("%d%d%d",&n,&m,&p))
    {
        getchar();
        memset(g,0x1f,sizeof g);

        for(int i = 0 ; i < m ; i++)
        {
            int a,b,v;
            char op;
            scanf("%d %d %d %c",&a,&b,&v,&op);
            getchar();
            a++,b++;

            if(op == 'I' && g[a][b].in > v)        //有了里面的路就不要外面的路了，并把里面的路更新到最短
            {
                g[a][b].in = g[b][a].in = v;
                //g[a][b].out = g[b][a].out = inf;
            }
            else if(op != 'I' && g[a][b].in == inf)    //只有外面的路的话就选最短的
            {
                g[a][b].out = g[b][a].out = min(g[a][b].out,v);
            }

        }

        for(int i = 0 ; i < p ; i++)
        {
            int s,t;
            scanf("%d%d",&s,&t);
            getchar();
            s++,t++;
            dij(s,t);
        }
    }
    return 0;

}
