/*
 * ���⣺
 * ��һ��������:��nͷţm�������
 * ������m��ÿ��������a b����ʾa��Ϊb�ܳ���,����϶����д�����
 * ���м�ͷţ������ţ��Ϊ�ǳ�����
 *
 * ˼·:
 * һ��ǿ��ͨ�������ţһ������Ϊ��Ҷ�������
 * ��������ǿ��ͨ����AB��A�е�һͷţ��ΪB�е�һͷţ��������ôA�е���ͷţһ���Ͽ�B�е�����ţ
 * ��ô��ÿһ��ǿ��ͨ�������㣬��������ͼ
 * ͳ������ͼ�г���Ϊ0�Ķ��㣬���ǡ��ֻ��һ������ô���ǿ��ͨ�������ţ�ͱ�����ţ�Ͽɣ��������Ĵ𰸾�����������е�ţ��ͷ��
 * �������������û�б��Ͽɵ�ţ�������Ѿ�������ͼ����ͨ�����
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

int totpart;
int cnt;
int part[100010];       //part[x] : x����part[x]��ǿ��ͨ����
int n,m;

struct edge
{
    int s;
    int t;
    int next;
}e[500100*2];

int head[100010];

void add(int s , int t)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].next = head[s];
    head[s] = cnt++;
}

int dfn[100100],low[100100],clo;
int instack[100010];
stack<int> st;

void targin(int cur)
{
    dfn[cur]=low[cur] = ++clo;
    st.push(cur);
    instack[cur]=1;

    for(int i = head[cur] ; i+1 ; i=e[i].next)
    {
        int next = e[i].t;

        if(!dfn[next])
        {
            targin(next);
            low[cur] = min(low[cur],low[next]);
        }
        else if(instack[cur])
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
            instack[tmp]=0;
            part[tmp]=totpart;
        }while(cur!=tmp);
    }
}

int out[100010];

void init()
{
    clr(head,-1);
    clr(out,0);
    clr(part,0);
    totpart=clo=cnt=0;
    clr(dfn,0);
    clr(low,0);
    clr(instack,0);
    while(!st.empty()) st.pop();
}

int main()
{
    //FR;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i = 0 ; i < m ; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
        }

        for(int i = 1 ; i <= n ; i++)       //����ͼ������ͼ�Ĵ�������һ���ˣ����������ж���Ϊ�����dfs
            if(!dfn[i])
                targin(i);

        for(int i = 0 ; i < cnt ; i++)
            if(part[e[i].s] != part[e[i].t])
                out[part[e[i].s]]++;

        int tt=0,pos=-1;
        for(int i = 1 ; i<= totpart ; i++)
            if(out[i] == 0)
            {
                tt++;
                pos=i;
            }

        if(tt==1)
        {
            int fi=0;
            for(int i = 1 ; i <= n ; i++)
                fi += (part[i]==pos);
            printf("%d\n",fi);
        }
        else
            cout << 0 << endl;
    }
    return 0;
}
