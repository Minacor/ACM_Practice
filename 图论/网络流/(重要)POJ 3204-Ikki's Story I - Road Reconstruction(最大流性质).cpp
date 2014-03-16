/*
 * ���⣺
 * ��Ŀ����һ��ͼ��������(0~n-1)�����ͼ�У��ı�ĳһ���߾���ʹ���������
 * ע��ÿ��ֻ����һ���ߣ�Ҳ����˵ 0 -> 1 -> 2 -> 3 -> 4 �⼸���߶�������ʱ����Ȼ��������4�����ܹ�ʹ���������
 * ���ǽ��ı�һ�����ǲ��еģ��Ͳ�����������
 * �������ı��м���
 *
 * ˼·��
 * ����������ʣ����������ı��������ģ�Ҳ����e[i].c == 0 , �䷴���(��������Ķ�Ӧ��)��e[i].c == e[i].oc , ocΪԭʼ����
 * Ȼ����ǰ��ıߺͺ���ı߶����������������߾��Ƿ�����������
 * ��������dinic������������󣬴�src��ʼ˳��dfs������tar��ʼ����dfs������ܵ���ĵ㣬���һ����������������s����˳��dfs�ı�ǣ�t������dfs��ǣ������߾��Ƿ��������ı�
 * ��Ȼ����һ�������ߣ�����������dfs�����������ȥ�ˣ����Բ�����ֱ���ص������
 * �������ý���һ��color�����¼��ǣ�1��˳��dfs�ı�ǣ�2������dfs�ı��
 * һ������һ�������߾�ִ�б�ǲ���
 * ע�͵��Ĵ���ı�Ƿ�Ҳ����
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
        if(!(i&1)&&!vis[e[i].t])        //��ʵ�����!(i&1)������һ��dfs��(i&1)������Ҫ
                                        //��Ϊ����һ���ڵ������ߺͷ��ߵ��������  0 <- 1 -> 2�����ȱ���2
                                        //�ģ�Ȼ�������ʱ������2���ȷ����ˣ�����ֻ�ܷ���0��
        {
            if(e[i].c == 0)     //���������߾�ִ�б��
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
                //return;       ǧ�򲻿�return����Ϊ��ǰ�ߴ��������һ���ߣ�����cur��β���ıߣ�һ��"��һ�����߲�ͨ��"����һ�����ǿ�����ͨ��
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
        for(int i = 0 ; i < cnt ; i += 2)   //ö�������
        {
            int s = e[i].s , t = e[i].t;
            if(e[i].c==0 && color[s]==1 && color[t]==2) //s�˱��1��t�˱��2��������
                out++;
        }
        printf("%d\n",out);
    }
    return 0;
}
