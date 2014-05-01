/*********************************************************

    ���⣺
    ������һ�������εĺ�(100*100)��������������(0,0),���½�����(50,50)
    ��������һ��Բ��С��,����(0,0)��ֱ��15
    Ȼ������кܶ����㣬�������ʾ
    С��Ҫ����������ͷ���ķ�ʽ�������ķ�Χ������Ծ����Ϊd
    ��С���ܷ��������ܵĻ������Ծ�����·���Լ���������·���µ���С��Ծ����

    ˼·��
    ���ȹ��˵㣬��С���ںͺ����������˲���
    Ȼ��ʣ�µ�������1~n����������Դ��0�ͳ������n+1��
    ����ܴ�С������������i����ô����0��i��ȨֵΪ��С����Ե�����������̾���
    ����ܴ�ĳһ����iֱ������С������ô����i��n+1��ȨֵΪ���㵽�߽����̾���
    ��Ȼ���������֮��ҲҪ����

    Ȼ��floydһ�£�������˳����²���step[][]
    �ж�g[0][n+1]�Ƿ�ɴ�ɴ�Ļ���˵������·�����������

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
