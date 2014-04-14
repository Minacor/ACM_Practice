/*
 * ���⣺
 * ���룺
 * ��һ��һ������ʾ��n��ѧУ
 * ������n��,��i�б�ʾi���ѧУ�б�������ϵ����ѧУ,��0��������ϵ�ǵ����
 * ������������
 * 1������ѡ�񼸸�ѧУ������Ϣ����ʹ����ѧУ�ܹ����յ���Ϣ
 * 2��������ĳЩѧУ��Ӷ��ٸ���ϵʹ������ѡ��һ��ѧУ�ܹ�ʹ��֪ͨ������ѧУ
 *
 * ˼·��
 * ����ǿ��ͨ���㹹������ͼ,����ͼһ��totpart����
 * ͳ��ͼ�����Ϊ0�ĵ�ĸ���ans1�ͳ���Ϊ0�ĸ���ans2
 * ��1����ans1����2������ж��ǿ��ͨ��������ô����max(ans1,ans2),ֻ��1���Ļ�����0
 * ��2�ĵó�֤�����Կ���
 * http://www.cnblogs.com/kuangbin/archive/2011/08/07/2130277.html
 * �򵥵�˵���ñ�֤��ӱ��Ժ�û�����=0����=0�ĵ㣬Ȼ��һ������=0�ĵ��������һ����ͨ��֧�����=0�ĵ���һ����
 * ������ͬʱ������һ��һ�������㣬����ĸ���ʣ�࣬��������������ͨ��֧��ѡ�������ĸ��Ϳ�����
 * ������ͼ��ֻ��һ����ʱ���������ߵ���һ������(��Ϊ��һ�����������Լ�),�����������ߣ�����Ҫ����Ϊ0
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
}e[20000];

int in[1100],out[1100];

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
        }while(cur!=tmp);
    }
}

void init()
{
    clr(head,-1);
    clr(in,0);
    clr(out,0);
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
    while(~scanf("%d",&n))
    {
        init();
        for(int i = 1 ; i <= n ; i++)
        {
            int a;
            while(scanf("%d",&a) && a)
                add(i,a);
        }

        for(int i = 1 ; i <= n ; i++)
            if(!dfn[i])
                tarjin(i);

        for(int i = 0 ; i < cnt ; i++)
            if(part[e[i].s] != part[e[i].t])
                in[part[e[i].t]]++,out[part[e[i].s]]++;

        int ans1=0,ans2=0;
        for(int i = 1 ; i <= totpart ; i++)
        {
            if(in[i] == 0)
                ans1++;
            if(out[i] == 0)
                ans2++;
        }

        printf("%d\n%d\n",ans1,(totpart==1?0:max(ans1,ans2)));
    }

    return 0;
}
