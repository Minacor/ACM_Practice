/*
 * ���⣺
 * ÿһ��ѯ���ҳ�st��ed��һ��·�����㣺����·���е�(���Ȩֵ-��СȨֵ)��С,�����ھ����-1
 *
 * ˼·��
 * �Ȱ����бߴ�С��������Ȼ��ö��ÿһ��Ȩֵdown
 * ��down��Ϊ���ޣ�����kruscal��Ȩֵ>=down�ı߹�����������ֻҪst��ed������,�ͷ�������·����max-min
 * Ȼ�������Сֵ
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

    bool operator <(const edge&b)const
    {
        return v<b.v;
    }
}e[2020];

int n,m;

vector<int> sp;
int f[210];

int find(int x)
{
    return x!=f[x] ? f[x]=find(f[x]) : x;
}

void merger(int x,int y)
{
    x = find(x);
    y = find(y);

    if(x!=y)
        f[x]=y;
}

void init()
{
    for(int i = 1 ; i <= n ; i++)
        f[i]=i;
}

int st,ed;

int kru(int down)
{
    init();
    int pos=0;

    while(e[pos].v < down) pos++;

    int minc = e[pos].v,maxc = -1;

    for( ; pos < m ; pos++)
    {
        int u = find(e[pos].s);
        int v = find(e[pos].t);

        if(u!=v)
        {
            maxc = e[pos].v;
            merger(u,v);
        }

        if(find(st) == find(ed))
            return maxc-minc;
    }
    return -inf;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        sp.clear();
        for(int i = 0 ; i < m ; i++)
        {
            scanf("%d%d%d",&e[i].s,&e[i].t,&e[i].v);
            sp.push_back(e[i].v);
        }
        sort(e,e+m);
        sort(sp.begin(),sp.end());
        sp.erase(unique(sp.begin(),sp.end()),sp.end());

        int q;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d",&st,&ed);
            int ans=inf;
            for(int i = 0 ; i < sp.size() ; i++)        //ö��ÿһ������ֵ
            {
                int ok = kru(sp[i]);
                if(ok == -inf) break;
                ans = min(ans,ok);
            }
            if(ans == inf) ans = -1;
            printf("%d\n",ans);
        }
    }
    return 0;
}
