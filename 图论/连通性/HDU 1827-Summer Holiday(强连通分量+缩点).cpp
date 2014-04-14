/*
 * ���⣺
 * �����⣺
 * ��˵lcy����Ԥ��������̩7���Σ�Wiskey���Ǹ��˵�ҹ�����°��������ŵÿ�������Ϣ���ߴ�ң�
 * ��Ȼ�������������˵���ϵ��ʽ������һ��һ����ϵ��ȥʵ��̫��ʱ��͵绰���ˡ�
 * ��֪��������Ҳ��һЩ���˵���ϵ��ʽ������������֪ͨ�����ˣ����������˰�æ֪ͨһ�±��ˡ�
 * ���ܰ�Wiskey���������Ҫ֪ͨ�����ˣ����ٵû����ٵ绰�Ѿ����������˶���֪ͨ����
 * ע��A����ϵ��B������B����ϵ��A������ϵ�ǵ����
 *
 * ˼·��
 * һ��ǿ��ͨ������������˶����ܻ�����ϵ�ģ�֪ͨ��һ���˾���֪ͨ��������
 * ������ǿ��ͨ�������㣬��������Ȩֵ��Ȼ�������з����еĵ���Ȩֵ��С��
 * Ȼ��ͳ������ͼ�����Ϊ0�����㣬��Щ�����е�����һ�˾��Ǳ��뱻ֱ��֪ͨ��
 * ��ȻҪ֪ͨ�����������������Ϊ0���������������С���Ѿ�����Щ�����Ȩֵ��
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
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int totpart;
int cnt;
int head[1100];
int n,m;

struct edge
{
    int s;
    int t;
    int next;
}e[4400];

int in[1100],v[1100];

void add(int s , int t)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].next = head[s];
    head[s] = cnt++;
}

int dfn[1100],low[1100],clo;
int inst[1100];
int part[1100];
int suov[1100];
stack<int> st;

void tarjin(int cur)
{
    dfn[cur] = low[cur] = ++clo;
    st.push(cur);
    inst[cur]=1;

    for(int i = head[cur] ; i+1 ; i=e[i].next)
    {
        int next = e[i].t;

        if(!dfn[next])
        {
            tarjin(next);
            low[cur] = min(low[next],low[cur]);
        }
        else if(inst[next])
            low[cur] = min(low[cur],dfn[next]);
    }

    if(low[cur] == dfn[cur])
    {
        totpart++;
        int tmp;

        do
        {
            tmp = st.top();
            st.pop();
            inst[tmp]=0;
            part[tmp] = totpart;
            suov[totpart] = min(suov[totpart],v[tmp]);
        }while(cur!=tmp);
    }
}

void init()
{
    clr(head,-1);
    clr(in,0);
    clr(suov,0x1f);
    clr(part,0);
    clr(dfn,0);
    clr(inst,0);
    totpart=clo=cnt=0;
    while(!st.empty())
        st.pop();
}

int main()
{
    //FR;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i = 1 ; i <= n ; i++)
            scanf("%d",v+i);
        for(int i = 0 ; i < m ; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
        }

        for(int i = 1 ; i <= n ; i++)
            if(!dfn[i])
                tarjin(i);

        for(int i = 0 ; i < cnt ; i++)
            if(part[e[i].s] != part[e[i].t])
                in[part[e[i].t]]++;

        int ans1=0,ans2=0;
        for(int i = 1 ; i <= totpart ; i++)
            if(in[i] == 0)
            {
                ans1++;
                ans2 += suov[i];
            }
        printf("%d %d\n",ans1,ans2);
    }

    return 0;
}
