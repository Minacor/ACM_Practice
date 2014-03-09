
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
const int MAX = 200000+10;
const int inf = 522133279;
const int mod = 1000000007;

int m,n;
struct edge
{
    int c;          //����
    int f;          //��ǰ����
}g[210][210];

int lv[210];        //������ڲ��
int vis[210];       //�����ʱ��

int bfs(int src , int tar)          //bfs����������磬srcΪԴ�㣬tarΪ��㣬һ��Ѱ�ҵ���������·
{
    clr(vis,0);
    clr(lv,0x1f);
    queue<int> que;
    que.push(src);
    vis[src]=1;
    lv[src]=1;

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();

        for(int i = 1 ; i <= n ; i++)
        {
            if(!vis[i] && g[cur][i].c > g[cur][i].f)        //ֻ�л��в���������ʱ�����������
            {
                vis[i]=1;
                lv[i]=lv[cur]+1;
                que.push(i);
            }
        }
    }

    return lv[tar] < inf;           //�����㲻�ڲ�������У�˵��û������·�ˣ��˳�dinic
}

int dfs(int cur , int tar , int totflow)    //���ò������������㣬ÿ��dfsѰ�ҵ��ǴӸýڵ�cur��������dfs���ӵ�������
                                            //totflowָ�����Ժ�������ܹ�������������������ǰ���������������
{
    int ret=0;
    if(cur == tar || !totflow) return totflow;  //�����������ߵ�ǰ�㲻�����ṩ�����ˣ����˳�

    for(int i = 1 ; i <= n ; i++)
    {
        if(!totflow) break;                     //�����ṩ������
        if(g[cur][i].c > g[cur][i].f && lv[cur]==lv[i]-1)   //�����ṩ��������ֻ����ͨ����һ��(ͬ�㲻�ܴ���)�ı�����ʣ���������ܼ���
        {
            int f = min(totflow , g[cur][i].c-g[cur][i].f); //�ܹ�ͨ��������
            int totdown = dfs(i,tar,f);                     //totdown��֮��������iΪ���ķ�֧�ܹ�ͨ���������ܺ�
            ret += totdown;                                 //�����ܹ�������������
            totflow -= totdown;                             //�ܿ�ͨ��������Ӧ��ȥ
            g[cur][i].f += totdown;                         //��cur�����i�����totdown
            g[i][cur].f -= totdown;                         //�������Ӧ��ȥtotdown
        }
    }
    return ret;
}

int dinic(int src , int tar)
{
    int ret=0;
    while(bfs(src,tar))         //������������㣬����Ȼ��������·
    {
        int tmp=dfs(src,tar,inf);   //��Դ�����ܹ����ӵ�������
        if(!tmp) break;
        ret+=tmp;
    }
    return ret;
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        clr(g,0);
        for(int i = 1 ; i <= m ; i++)
        {
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            g[a][b].c+=v;       //�ر��ۼ������Ϳ�����
        }
        printf("%d\n",dinic(1,n));
    }
    return 0;
}
