/******************************************************

    题意：
    要破坏掉一个电网， 有n个电站编号为1～n，每个电站有它自己的能量值。
    有一个军事基地编号为0，里面有无限个坦克，
    可以开到某个电站轰炸破坏掉电站，并且一个坦克只能破坏一个。
    现在要破坏掉其中一些电站，要让电网的总能量值损失一半以上，
    并且要让所有执行任务的坦克去目的地路费最少。

    思路：
    因为一个坦克只能破坏一个电站，于是题目大大简化
    数据量小，先用flody求出0到1~n的最短路，所有最短路距离为dis
    所有能量值之和为sum
    然后dp[x]表示剩余容量x的情况下，能够破坏的最大能量值
    这样枚举x从1~总距离dis，因为这样路费是递增的，只要遇到一个符合条件的
    使得dp[i] >= sum/2+1，那么就找到符合条件的最短路径和i了

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
