/*
 * ���⣺
 * ��һ�����ݱհ�(һ��n*n����g[i][j]=1��ʾi��j��ֱ��·��������ͼ)
 * Ҫ����һ������������ݱհ�������ͼ���������ͼ�ı������٣��������
 *
 * ˼·��
 * ���������Ǳ���ģ�һ��nԪ�������ڵ�����Ԫ������ֻ��Ҫn���߾Ϳɻ��ഫ��(1���⣬1��ʱ����0)
 * ���������ıߣ��п��ܳ���1->2 , 2->3 , 1->3����������ʱ��1->3���Ƕ���ߣ�Ҫȥ��
 * ȥ�ߵķ���������floyd�����㷨�����g[i][j],g[i][k],g[k][j]����·������ô�Ϳ���ȥ��g[i][j]
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

int n;
int g[210][210];
int dfn[210],low[210],clo;
int totpart,suo[210],part[210];
stack<int> st;
int inst[210];

void init()
{
    clr(dfn,0);
    clr(suo,0);
    clr(part,0);
    clo=totpart=0;
    clr(inst,0);
    while(!st.empty()) st.pop();
}

void tarjin(int cur)
{
    dfn[cur]=low[cur]=++clo;
    inst[cur]=1;
    st.push(cur);

    for(int i = 1 ; i <= n ; i++)
    {
        if(g[cur][i] && cur!=i)
        {
            if(!dfn[i])
            {
                tarjin(i);
                low[cur] = min(low[cur],low[i]);
            }
            else if(inst[i])
                low[cur] = min(low[cur],dfn[i]);
        }
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
            suo[totpart]++;
        }while(cur!=tmp);
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        init();
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                scanf("%d",&g[i][j]);

        for(int i = 1 ; i <= n ; i++)
            if(!dfn[i])
                tarjin(i);

        int ans=0;
        for(int i = 1 ; i <= totpart ; i++)
            ans += (suo[i]==1?0:suo[i]);

        for(int k = 1 ; k <= n ; k++)
            for(int i = 1 ; i <= n ; i++)
                for(int j = 1 ; j <= n ; j++)
                    if(i!=j&&i!=k&&j!=k&&g[i][j] && g[i][k] && g[k][j]) //ע��ijk������ͬ
                        g[i][j] = 0;

        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j<= n ; j++)
                if(g[i][j] && part[i]!=part[j])     //��ͬ����֮�����Ҫ���ı߾�Ҫ������
                    ans++;
        printf("%d\n",ans);
    }
    return 0;
}
