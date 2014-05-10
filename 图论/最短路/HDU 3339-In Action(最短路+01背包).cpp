/******************************************************

    ���⣺
    Ҫ�ƻ���һ�������� ��n����վ���Ϊ1��n��ÿ����վ�����Լ�������ֵ��
    ��һ�����»��ر��Ϊ0�����������޸�̹�ˣ�
    ���Կ���ĳ����վ��ը�ƻ�����վ������һ��̹��ֻ���ƻ�һ����
    ����Ҫ�ƻ�������һЩ��վ��Ҫ�õ�����������ֵ��ʧһ�����ϣ�
    ����Ҫ������ִ�������̹��ȥĿ�ĵ�·�����١�

    ˼·��
    ��Ϊһ��̹��ֻ���ƻ�һ����վ��������Ŀ����
    ������С������flody���0��1~n�����·���������·����Ϊdis
    ��������ֵ֮��Ϊsum
    Ȼ��dp[x]��ʾʣ������x������£��ܹ��ƻ����������ֵ
    ����ö��x��1~�ܾ���dis����Ϊ����·���ǵ����ģ�ֻҪ����һ������������
    ʹ��dp[i] >= sum/2+1����ô���ҵ��������������·����i��

*******************************************************/

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

int t;
int n,m;
int g[110][110];
int vv[110];
int dp[MAXN];

void floyd()
{
    for(int k= 0 ; k<= n ; k++)
        for(int i = 0;  i <= n ; i++)
            for(int j = 0 ; j <= n ; j++)
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
}

void init()
{
    clr(g,0x1f);
    clr(dp,0);
}

int main()
{
    scanf("%d",&t);

    for(int ka = 1 ; ka <= t ; ka++)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i = 0 ; i < m ; i++)
        {
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            g[a][b]=g[b][a]=min(g[a][b],v);
        }
        floyd();
        int sum=0,tot=0,dis=0;
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d",vv+i);
            if(g[0][i] != inf)
                sum+=vv[i],dis+=g[0][i];
            tot+=vv[i];
        }

        if(sum < tot/2+1)
        {
            puts("impossible");
            continue;
        }

        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = dis ; j >= g[0][i] ; j--)
                dp[j] = max(dp[j],dp[j-g[0][i]]+vv[i]);
        }

        sum = sum/2+1;
        for(int i=1 ; i <= dis ; i++)
        {
            if(dp[i] >= sum)
            {
                printf("%d\n",i);
                break;
            }
        }

    }
    return 0;
}
