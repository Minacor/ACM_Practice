/*
 * ���⣺
 * ��һ��ͼ����һЩ·���ڻ���ģ�����һЩ������
 * �����s��t����̻������(����·�����ܺ�)���ܾ��룬ǰ���ж�����ͬʱҪ���ܾ�����С
 *
 * ˼·��
 * ��Ȩֵ���·�����������������Ȩֵ������ϵ�ģ����Բ���ֱ��ģ��Ӳ�ϣ���
 * �㷨�������ȶ���dijkstra ; spfa�ᳬʱ
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
    int id;         //��Ϊ�����еĶ���ʱ����ǰ����
    int in;         //��Ϊ�����еĶ���ʱ����ǰ���㵽����outdoor��̾���
    int out;        //��Ϊ�����еĶ���ʱ����ǰ���㵽��������̾���

    node(){}

    node(int _id , int _in , int _out)
    {
        id=_id ; in = _in ; out = _out;
    }

    bool operator < (const node &b)const        //���ȶ���Ĭ�ϴ󶥶ѣ�ע��
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
            if(g[cur.id][i].in != inf)      //����л����·��Ӧ����ѡ�����·
            {
                if(out[cur.id] < out[i] || out[i]==out[cur.id] && total[i] > total[cur.id]+g[cur.id][i].in)
                {
                    out[i]=out[cur.id];     //ע���������out��˵�������ڵ�·ȫ����������Ϊ0������g[cur.id][i].in=0
                    total[i] = total[cur.id]+g[cur.id][i].in;
                    que.push(node(i,out[i],total[i]));
                }
            }
            else if(g[cur.id][i].out != inf)    //����ֻ��ѡ�����
            {
                if(out[i] > out[cur.id]+g[cur.id][i].out || out[i]==out[cur.id]+g[cur.id][i].out && total[i] > total[cur.id]+g[cur.id][i].out)
                {
                    out[i]=out[cur.id]+g[cur.id][i].out;    //����ĳ����Ծ���Ҫ����
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

            if(op == 'I' && g[a][b].in > v)        //���������·�Ͳ�Ҫ�����·�ˣ����������·���µ����
            {
                g[a][b].in = g[b][a].in = v;
                //g[a][b].out = g[b][a].out = inf;
            }
            else if(op != 'I' && g[a][b].in == inf)    //ֻ�������·�Ļ���ѡ��̵�
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
