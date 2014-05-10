/*********************************************************

    ���⣺
    ��һ������ͼ���ҵ����е�������������̻�·(��һ���������������ɾ�����ٷ��ش˾�������·)
    �����ǳ������֮�����������������������ͬ�ľ���

    ˼·��
    floyd�һ�������

**********************************************************/
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include "iostream"
#include "cstring"
#include "algorithm"
#include "cmath"
#include "cstdio"
#include "sstream"
#include "queue"
#include "vector"
#include "list"
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
#define PI acos(-1.0)
#define mkp make_pair
using namespace std;
typedef long long LL;
const int MAXN = 100000+100;
const int inf = 522133279;
const int mod = 1000000007;

int n,m;
int g[110][110];
int step[110][110];

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i = 0 ; i < 110 ; i++)
            for(int j = 0 ; j < 110 ; j++)
                g[i][j]=inf;

        for(int i = 0 ; i < m ; i++)
        {
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            g[a][b]=g[b][a]=min(g[a][b],v);
        }

        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                step[i][j] = step[j][i]=g[i][j];

        int ans=inf;

        /**
            �����㷨����
            floyd�� g[i][j]ָ����i��j֮�����ʱ���·
            ��ôҪ����������Ԫ���ϵĻ�����Ҫ�������һ�����㣬
            ����������k��
            ans = min(ans,g[i][j]+step[i][k]+step[k][j]);
            �������ܱ�֤���ڽ�Ļ��������һ������Ԫ���ϵĻ�
            Ҫע��i,j,k������ͬ��ע��ѭ���ķ�Χ
        */
        for(int k=1;k<=n;k++)
        {
            for(int i = 1 ; i < k ; i++)
                for(int j = 1 ; j < i ; j++)
                    ans = min(ans,g[i][j]+step[i][k]+step[k][j]);

            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(g[i][j]>g[i][k]+g[k][j])
                    {
                        g[i][j]=g[i][k]+g[k][j];
                    }
        }

        if(ans == inf)
            puts("It's impossible.");
        else
            printf("%d\n",ans);
    }
    return 0;
}
