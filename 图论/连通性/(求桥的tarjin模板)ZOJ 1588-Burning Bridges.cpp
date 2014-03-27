/*
 * ���⣺
 * ��һ��ͼ��ÿ���߰��������ţ����Ϊ�ŵıߵı��
 *
 * ˼·��
 * tarjin����
 * (u,v)���ţ����ҽ���(u,v)Ϊ�������еıߣ���dfn[u]<low[v]
 *
 * ע�⣺
 * �������رߣ����ر�һ���������ţ�����ӱߵ�ʱ��Ҫ�ж�һ��
 * ����ߵ���ŵ�ʱ��Ҫ��С���������
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

int t;
int n,m;

struct edge
{
    int s,t;
    int next;
    int chongbian;
    int id;
}e[100000*2+100];

int head[10000+100],cnt;
int low[10100],dfn[10100],clo;
int vis[10100];                                 //0 δ���ʹ���1 �ѷ��ʹ�����δ���������ӽڵ� ��2 �ѷ��������ӽڵ�,��ʵ��ȫû��Ҫ����vis

void add(int s , int t , int id)
{
    for(int i = head[s] ; i+1 ; i=e[i].next)            //�ж��رߣ��ǵĻ���Ҫ���,tarjin��ʱ���Զ��Թ�
        if(t == e[i].t)
        {
            e[i].chongbian=e[i^1].chongbian=1;
            return ;
        }

    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].next = head[s];
    e[cnt].chongbian=0;
    e[cnt].id=id;
    head[s] = cnt++;

    e[cnt].s=t;
    e[cnt].t=s;
    e[cnt].next = head[t];
    e[cnt].chongbian=0;
    e[cnt].id=id;
    head[t] = cnt++;
}

vector<int> st;

void targin(int cur ,int fa)
{
    low[cur] = dfn[cur] = ++clo;
    vis[cur]=1;

    for(int i = head[cur] ; i+1 ; i = e[i].next)
    {
        int next = e[i].t;
        if(!vis[next])
        {
            targin(next,cur);

            low[cur] = min(low[next],low[cur]);

            if(low[next] > dfn[cur] && e[i].chongbian == 0)
                st.push_back(e[i].id);
        }
        else if(fa != next && vis[next] == 1)       //���ŵ�ʱ��Ҫ�ж�next�ǲ������Ƚڵ�(��ֹ�����رߣ���Ϊ��ʹ�Ѿ�ȥ���ˣ�addʱ��ӵ���˫���)���������ʱ����
            low[cur] = min(dfn[next],low[cur]);
    }
    vis[cur]=2;
}

int main()
{
    //FR;
    scanf("%d",&t);

    while(t--)
    {
        clo=0;
        clr(low,0);
        clr(dfn,0);
        clr(head,-1);
        clr(vis,0);
        st.clear();
        cnt=0;

        scanf("%d%d",&n,&m);
        for(int i = 0 ; i < m ; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b,i+1);
        }

        targin(1,-1);

        printf("%d",st.size());
        if(!st.empty())
        {
            sort(st.begin(),st.end());
            printf("\n%d",st[0]);
            for(int i = 1 ; i < st.size() ; i++)
                printf(" %d",st[i]);
        }
        puts("");

        if(t) puts("");
    }
    return 0;
}
