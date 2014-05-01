/*********************************************************

    题意：
    现在有一个正方形的湖(100*100)，湖的中心坐标(0,0),右下角坐标(50,50)
    湖中心有一个圆形小岛,中心(0,0)，直径15
    然后湖内有很多鳄鱼，以坐标表示
    小明要以跳到鳄鱼头顶的方式跳出湖的范围，其跳跃距离为d
    问小明能否跳出，能的话输出跳跃的最短路径以及在这个最短路径下的最小跳跃步数

    思路：
    首先过滤点，在小岛内和湖外的鳄鱼过滤不算
    然后剩下的鳄鱼标号1~n，设立超级源点0和超级汇点n+1，
    如果能从小岛上跳到鳄鱼i，那么连接0和i，权值为从小到边缘跳到鳄鱼的最短距离
    如果能从某一鳄鱼i直接跳出小岛，那么连接i和n+1，权值为鳄鱼到边界的最短距离
    当然鳄鱼和鳄鱼之间也要连线

    然后floyd一下，过程中顺便更新步数step[][]
    判断g[0][n+1]是否可达，可达的话就说明存在路径，输出即可

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
const int MAXN = 10000+10;
const int inf = 522133279;
const int mod = 1000000007;

struct node
{
    int x;
    int y;
}p[210];

int n;
double d,g[210][210];
int step[210][210];
double low[210];
int vis[210];

void floyd()
{
    for(int k = 0 ; k <= n ; k++)
        for(int i = 0 ; i <= n ; i++)
            for(int j = 0 ; j <= n ; j++)
                if(g[i][j] > g[i][k]+g[k][j])
                {
                    g[i][j] = g[i][k]+g[k][j];
                    step[i][j] = step[i][k]+step[k][j];
                }
}

int main()
{
    while(~scanf("%d%lf",&n,&d))
    {
        for(int i = 0 ; i <= n+10 ; i++)
            for(int j = 0 ; j <= n+10 ; j++)
            {
                low[i] =  g[i][j] = inf;
                step[i][j]=1;
            }

        int pp=0;
        for(int i = 1 ; i <= n ; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);

            if(x*x+y*y <= 7.5*7.5 || abs(x) >= 50 || abs(y) >= 50)
                continue;
            pp++;
            p[pp].x=x;p[pp].y=y;
        }

        if(d >= 50-7.5)
        {
            printf("42.50 1\n");
            continue;
        }
        n=pp;
        for(int i = 1 ; i <= n ; i++)
            if((p[i].x)*(p[i].x)+(p[i].y)*(p[i].y) <= (7.5+d)*(7.5+d))
                g[0][i]=g[i][0] = sqrt(1.0*p[i].x*p[i].x+p[i].y*p[i].y)-7.5;

        for(int i = 1; i <= n ; i++)
            for(int j = 1 ; j < i ; j++)
            {
                double tmp = sqrt(1.0*(p[i].x-p[j].x)*(p[i].x-p[j].x) + (p[i].y-p[j].y)*(p[i].y-p[j].y));
                if(tmp <= d)
                    g[i][j]=g[j][i] = tmp;
            }

        for(int i = 1 ; i <= n ; i++)
        {
            if(p[i].x-50+d >= 0 || p[i].x+50-d <= 0 || p[i].y-50+d >= 0 || p[i].y+50-d <= 0)
            {
                double t1 = min(fabs(p[i].x-50.0),fabs(p[i].y-50.0));
                double t2 = min(fabs(p[i].y+50.0),fabs(p[i].x+50.0));
                t1 = min(t1,t2);
                g[i][n+1]=g[n+1][i]=t1;
            }
        }
        n++;

        floyd();
        if(g[0][n] >= inf-1)
            printf("can't be saved\n");
        else
            printf("%.2lf %d\n",g[0][n],step[0][n]);
    }
    return 0;
}
