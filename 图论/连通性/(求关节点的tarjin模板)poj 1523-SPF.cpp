/*
 * ���⣺
 * ��һ������(ʵ����һ������ͼ)��ÿһ���ڵ�Ϊһ̨�������
 * �������һ̨������Ǹ�� �� ��ȥ���Լ�����������ı�֮�����类�ֳ��˼���
 *
 * ˼·��
 * targinģ��
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
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int n;

struct edge
{
    int s,t;
    int next;
}e[1000*1000*2+100];

int head[1010],cnt;
int subnet[1010];               //subnet[i]��ʾ��ȥi֮�������˼�����ͨ����
int vis[1010];

//dfn��������ȱ����ı���˳��ֵ��low[i]�Ǵ�i��i���������ͨ���ر߿��Ե������С���ȱ�������
int low[1010],dfn[1010],clock;

void add(int s,int t)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].next=head[s];
    head[s] = cnt++;

    e[cnt].s=t;
    e[cnt].t=s;
    e[cnt].next=head[t];
    head[t] = cnt++;
}

void init()
{
    clr(head,-1);
    clr(vis,0);
    cnt=0,clock=0;
    clr(low,0);
    clr(dfn,0);
    clr(subnet,0);
    subnet[1]=-1;
    n=0;
}

void tarjin(int cur)
{
    dfn[cur] = low[cur] = ++clock;
    vis[cur] = 1;

    //cur��now�ڽӣ���dfs�������о����������
    //1: now��cur�����Ƚ�㣬����(now,cur)����һ���ر�
    //2: now��cur�Ķ��ӽ��
    for(int i = head[cur] ; i+1 ; i = e[i].next)
    {
        int now = e[i].t;
        if(!vis[now])       //now��δ�����ʣ��ǵڶ�������
        {
            tarjin(now);    //tarjin(now) ִ��֮��low[now]�Ѿ����

            low[cur] = min(low[now],low[cur]);  //����лرߵĻ���low[now] < low[cur]

            if(low[now] >= dfn[cur])        //������ӽ�㲻�ܻ��ݵ�cur�����ȣ���ô��ȥcur֮��
                                            //��nowΪ�����������������ѳ�����Ҳ����˵���˸���ͨ����
                                            //����Ҫע����ڵ㣺���ڵ���Ů����>2���ǹؽڵ㣬
                                            //����֮ǰ��ʼ��ʱ��subnet[1]=-1��Ҫ����ͨ����1
                subnet[cur]++;
        }
        else        //now�ѱ����ʣ���һ�����Σ���ônow������cur�����Ƚڵ㣬��һ���ر�
            low[cur] = min(dfn[now],low[cur]);
    }
}

int main()
{
    string line;
    int s,t;
    int tot=0;

    while(getline(cin,line) && line != "0")
    {
        init();
        istringstream iss(line);
        iss >> s >> t;
        n = max(n,max(s,t));
        add(s,t);

        while(getline(cin,line) && line != "0")
        {
            istringstream iss(line);
            iss >> s >> t;
            n = max(n,max(s,t));
            add(s,t);
        }
        cin.ignore();

        tarjin(1);

        int ok=0;
        printf("Network #%d\n",++tot);

        for(int i = 1 ; i <= n ; i++)
            if(subnet[i]>0)
                ok=1,printf("  SPF node %d leaves %d subnets\n",i,subnet[i]+1);
        if(!ok)
            printf("  No SPF nodes\n");
        puts("");
    }
    return 0;
}
