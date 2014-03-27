/*
 * ���⣺
 * һ��n*m��ͼ�������ɸ�man�����ɸ�house��������ȣ�һ��manֻ��סһ��house
 * manÿ��һ�񻨷�1ԪǮ��������manס��house����С�����Ƕ���
 *
 * ˼·��һ��man(x1,y1)��һ��house(x2,y2)�ľ���Ϊabs(x1-x2)+abs(y1-y2)
 * ��ͼ����������Դ��src�ͳ������tar
 * src������man���ߣ�����costΪ0������cΪ1
 * ����house��tar���ߣ�����Ϊ0������Ϊ1
 * ����man������house֮�佨�ߣ�����Ϊ����֮��ľ��룬����Ϊ1
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
    e[cnt].cost=-cost;      //����߻���Ϊ-cost
    e[cnt].next=head[t];
    head[t] = cnt++;
}

int dis(int x,int y)
{
    return abs(manpos[x].first-housepos[y].first)+abs(manpos[x].second-housepos[y].second);
}

int low[11000],vis[11000],pre[11000],path[11000];   //pre��¼��ѡ·���е�ǰ����㣬path��¼��Щ�߱�ѡȡ��
int ans;

bool spfa()             //Ѱ�����п������еĻ�����С��
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
            if(e[i].c > 0 && low[next] > low[cur]+e[i].cost)    //�ر�ע�ⲻҪ��©e[i].c > 0����
            {
                low[next] = low[cur]+e[i].cost;

                //��¼ǰ������������ѡ��ı�
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
    return low[tar] != inf;         //��tarû������������Ȼ���ǲ����ڿ�������
}

int arg()           //���ű�ѡ���·����������
{
    int c = inf,flow=0;

    //�ó����������������µ�����
    for(int i = tar ; pre[i]+1 ; i = pre[i])
    {
        edge cur = e[path[i]];
        c = min(c,cur.c);
    }

    //��������
    for(int i = tar ; pre[i]+1 ; i = pre[i])
    {
        e[path[i]].c -= c;
        e[path[i]^1].c += c;
        flow += e[path[i]].cost*c;          //��С����
    }
    maxflow += c;           //�����
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
