/*
 * ���⣺
 * �����ͼ�Ķ�����ͨ��(��С����С)
 *
 * ˼·��
 * �󶥵���ͨ�ȵķ�����
 * ��n���㣬ÿ����i���������i'��i" �� ����i'��i"֮����һ���ߣ�����Ϊ1
 * ԭͼ�е�ÿһ����(a,b) ���������д��ڶ�Ӧ��������(a",b')��(b",a') , ��������inf
 * �̶�һ��Դ��A"��ö�����л��B' != A'�������������������е���Сֵ���Ǵ�
 */
#include "iostream
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

int m,n;

int g[200][200],tpg[200][200];
int lv[200];

int bfs(int src , int tar)
{
    clr(lv,0);
    queue<int> que;
    que.push(src);
    lv[src]=1;

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();

        for(int i = 1 ; i <= 2*n ; i++)
        {
            if(!lv[i] && g[cur][i]>0)
            {
                lv[i]=lv[cur]+1;
                if(i == tar) return 1;
                que.push(i);
            }
        }
    }

    return 0;
}

int dfs(int cur , int tar , int totf)
{
    int ret=0;
    if(cur == tar || !totf) return totf;

    for(int i = 1 ; i <= 2*n ; i++)
    {
        if(!totf) break;
        if(g[cur][i]>0 && lv[cur]==lv[i]-1)
        {
            int f = dfs(i,tar,min(totf , g[cur][i]));
            ret += f;
            totf -= f;
            g[cur][i] -= f;
            g[i][cur] += f;
        }
    }

    return ret;
}

int dinic(int src , int tar)
{
    int ret=0;
    while(bfs(src,tar))
    {
        int tmp = dfs(src,tar,inf);
        if(!tmp) break;
        ret += tmp;
    }
    return ret;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        clr(tpg,0);
        for(int i = 1 ; i <= n ; i++)
            tpg[i][i+n] = 1;
        for(int i = 1 ; i <= m ; i++)
        {
            int a,b;
            scanf(" (%d,%d)",&a,&b);
            a++,b++;
            tpg[a+n][b] = tpg[b+n][a] = inf;
        }

        int ans = inf;

        for(int i = 2 ; i <= n ; i++)
        {
            for(int x = 0 ; x <= 2*n ; x++)         //ע��ÿ�ζ�Ҫ�ָ�ԭͼ
                for(int y = 0 ; y <= 2*n ; y++)
                    g[x][y] = tpg[x][y];

            ans = min(ans , dinic(n+1,i));
        }

        if(ans == inf) ans = n;
        printf("%d\n",ans);
    }
    return 0;
}
