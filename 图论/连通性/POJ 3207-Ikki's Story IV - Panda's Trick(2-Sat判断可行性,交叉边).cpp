/*
 * ���⣺
 * ��֪һ��Բ��˳ʱ����� n ���㣬�� n ��������m�Զ���֮�������ߣ�
 * ����Ҫô��԰��Ҫô��Բ�ڣ�ÿ�����������һ���ߣ����Ƿ����һ����������������еı߶����ཻ��
 *
 * ˼·��
 * ��ÿ���߿��������� i , i+m �ֱ��ʾ�����ڲ������ⲿ��
 * ���������i, j�Ķ˵��������ϵĽ��棬�������Ե�֮�������һ�����ⲿһ�����ڲ�
 * ��������� i�����Ȼ���� j+m ��������� j �����Ȼ���� i+m��������� i+m�����Ȼ���� j ��������� j+m �����Ȼ���� i��
 * ��ͼ��ʱ�����ı�Ϊ
 * i -> j+m
 * j -> i+m
 * i+m -> j
 * j+m -> i
 *
 * �������ͣ�A[x] XOR A[y] ����һ�������⣬��һ����һ�����ڣ���֮��Ȼ
 * ���ǿ��ͨ������Ⱦɫ���ж��Ƿ���ڳ�ͻ���������
 */
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int MAXN = 10000+10;
const int inf = 522133279;
const int mod = 1000000007;

struct node
{
    int s;
    int t;
}g[1000];

struct edge
{
    int s;
    int t;
    int next;
}e[1000000+10000];

int cnt,head[2000];

void add(int s , int t)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].next = head[s];
    head[s]= cnt++;
}

int dfn[2000],low[2000],totpart,part[2000],clo;
int inst[2000];
stack<int> st;

void tarjan(int cur)
{
    dfn[cur] = low[cur] = ++clo;
    st.push(cur);
    inst[cur]=1;

    for(int i = head[cur] ; ~i ; i=e[i].next)
    {
        int next = e[i].t;
        if(!dfn[next])
        {
            tarjan(next);
            low[cur] = min(low[cur],low[next]);
        }
        else if(inst[next])
            low[cur] = min(low[cur],dfn[next]);
    }

    if(dfn[cur] == low[cur])
    {
        totpart++;
        int tmp;

        do
        {
            tmp = st.top();
            st.pop();
            inst[tmp]=0;
            part[tmp] = totpart;
        }while(cur!=tmp);
    }
}

void init()
{
    clr(head,-1);
    clr(dfn,0);
    clr(part,0);
    clr(inst,0);
    clr(low,0);
    clo=totpart=cnt=0;
    while(!st.empty())
        st.pop();
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i = 0 ; i < m ; i++)
        {
            scanf("%d%d",&g[i].s,&g[i].t);
            if(g[i].s > g[i].t)
                swap(g[i].s,g[i].t);
        }

        for(int i = 0 ; i < m ; i++)
            for(int j = i+1 ; j < m ; j++)
            {
                //����ߵ��������
                if( (g[i].s<g[j].t && g[i].s>g[j].s && g[i].t>g[j].t) ||
                    (g[i].t>g[j].s && g[i].s<g[j].s && g[i].t<g[j].t))
                {
                    add(i,j+m);
                    add(j,i+m);
                    add(j+m,i);
                    add(i+m,j);
                }
            }

        for(int i = 0 ; i < 2*m ; i++)
            if(!dfn[i])
                tarjan(i);

        int ok=1;
        for(int i = 0 ; i < m ; i++)
            if(part[i] == part[i+m])
            {
                ok=0;
                break;
            }
        printf("%s\n",(ok?"panda is telling the truth...":"the evil panda is lying again"));
    }
    return 0;
}