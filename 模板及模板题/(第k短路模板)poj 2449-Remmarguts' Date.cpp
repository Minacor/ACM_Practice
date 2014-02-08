/*
 * http://www.cnblogs.com/Missa/archive/2012/08/30/2664668.html
 *
 * ���⣺
 * ��һ������������n����㣬m����
 * ������m����ÿ���ߵ��������Ϊ����ߣ�������a b v��ʾ��a��b��ȨֵΪv
 * ���һ�������������st���ص�ed�����k��·
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
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 100000+100;
const int inf = 522133279;

struct edge
{
    int now;
    int next;
    int v;
} e[100005],re[100005]; //ԭͼ�ͷ���ͼ

int head[1010],rhead[1010];
int cnt;
int st,ed,K;
int n,m;
int low[1010];
int vis[1010];

struct node         //���ȶ����е�Ԫ��
{
    int id;         //ѹ����еĽ��
    int dis;        //��㵽���ľ���

    node() {}
    node(int _id , int _dis)
    {
        id = _id ;
        dis = _dis;
    }

    bool operator < (const node& b)const        //�ȽϺ�����д��
    {
        return dis+low[id] > b.dis+low[b.id];
        //return dis > b.dis;
    }
};

void add(int x , int y , int v)     //�ӱ�ʱ����ͼͬʱ����
{
    e[cnt].v = re[cnt].v = v;
    e[cnt].now = y;
    e[cnt].next = head[x];
    head[x] = cnt;

    re[cnt].now = x;
    re[cnt].next = rhead[y];
    rhead[y] = cnt++;


}

void init()
{
    cnt=0;
    clr(head,-1);
    clr(rhead,-1);
    clr(vis,0);
}

priority_queue<node> que;

void dij(int src)
{
    clr(vis,0);
    clr(low,0x1f);
    low[src]=0;

    while(!que.empty())
        que.pop();

    que.push(node(src,0));
    while(!que.empty())
    {
        node cur = que.top();
        que.pop();

        if(vis[cur.id])
            continue;

        vis[cur.id]=1;
        for(int i = rhead[cur.id] ; i != -1 ; i = re[i].next)
        {
            if(low[re[i].now] > low[cur.id] + re[i].v)
            {
                low[re[i].now] = low[cur.id] + re[i].v;
                que.push(node(re[i].now,low[re[i].now]));
            }
        }
    }
}

int zouqi(int src)          //���k��·
{
    while(!que.empty())
        que.pop();

    que.push(node(src,0));
    while(!que.empty())
    {
        node cur =  que.top();
        que.pop();

        if(cur.id == ed)
        {
            if(K > 1) K--;
            else return cur.dis;
        }

        for(int i = head[cur.id] ; i != -1 ; i = e[i].next)     //�����dis�й����Ķ���
            que.push(node(e[i].now,cur.dis+e[i].v));
    }

    return -1;
}

int main()
{
    FR;
    int a,b,v;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&v);
            add(a,b,v);
        }
        scanf("%d%d%d",&st,&ed,&K);
        dij(ed);                //����ͼ�Ĺ��ۺ���low
        if(st == ed)            //��ĿҪ�������һ��·������Ϊ0�����·�ǲ���ģ���ʱҪ����ǵ�k+1��·
            K++;
        printf("%d\n",zouqi(st));
    }

    return 0;
}
