/*
 * ���⣺
 * ����Pseudoforest��һ��ͼ����ͼ�������ͼ���ÿһ����ͨ��������ֻ��һ����
 * �������Pseudoforest�����б�Ȩ������Pseudoforest
 * ��������Pseudoforest�ı�Ȩ��
 *
 * ˼·��
 * ������������壬���鼯�ϲ���ʱ��Ҫ�����жϣ�
 * ����һ������g��g[i]��ʾ��iΪ�������ͨ������û�л�
 * ���������ͨ�����ϲ������ֻ��һ�������л�
 * ���һ���߲���һ�������������һ��������ô�͵��ж�ԭ�ȵķ�������û�л�
 *
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

struct edge
{
    int s;
    int t;
    int v;

    bool operator <(const edge& b)const
    {
        return v>b.v;
    }
}e[100000+100];

int n,m;

int f[10100];
bool g[10100];

int find(int x)
{
    return x!=f[x]?f[x]=find(f[x]):x;
}

int kru()
{
    int res=0;
    int cnt=0;
    int ok=0;

    for(int i = 0 ; i < m ; i++)
    {
        int v=find(e[i].s);
        int u=find(e[i].t);

        if(v!=u)      //������ͬ����ͨ�����ϲ�
        {
            if(!(g[v]&&g[u]))
            {
                cnt++;
                res+=e[i].v;
                if(g[u])
                    f[v]=u;
                else
                    f[u]=v;
            }
        }
        else if(!g[v])      //һ�������ӻ��ı�
        {
            g[v]=true;
            res+=e[i].v;
        }
    }

    return res;
}

int main()
{
    while(~scanf("%d%d",&n,&m) && (n||m))
    {
        clr(g,false);
        for(int i = 0 ; i < n ; i++)
            f[i]=i;
        for(int i = 0 ; i < m ; i++)
        {
            scanf("%d%d%d",&e[i].s,&e[i].t,&e[i].v);
        }

        sort(e,e+m);
        printf("%d\n",kru());
    }
    return 0;
}
