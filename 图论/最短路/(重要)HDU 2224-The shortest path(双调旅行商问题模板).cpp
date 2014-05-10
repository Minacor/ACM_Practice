/********************************************************

    ���⣺
    ����n���㣬����x����Ӵ�С����
    ���1��n��Ȼ���ٴ�n��1�����·
    ȥ��ʱ�򾭹��ĵ��x��������С���� ����ʱ�򾭹��ĵ��x�������Ӵ�С
    ����ÿ����ֻ�ܾ���һ���ұ��뾭��һ��(1��n����) ������·�ĳ���

    ˼·��
    �����˫�����������⣺
    �����ó̼�Ϊ������㿪ʼ���ϸ�ش�����ֱ�����ҵ㣬Ȼ���ϸ�ش��ҵ���ֱ�������㡣
    ��ʵ�ϣ�����ȷ��������˫��·�ߵ�O(n*n)ʱ����㷨


*********************************************************/
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

struct node
{
    int x;
    int y;
}p[210];

int n;
double g[210][210];
double low[210],vis[210];

double dis(node a , node b)
{
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double b[210][210];

double dp()
{
    b[1][2]=g[1][2];

    for(int j = 3 ; j <= n ; j++)
    {
        for(int i = 1 ; i <= j-2 ; i++)
            b[i][j]=b[i][j-1]+g[j-1][j];

        b[j-1][j]=inf;
        for(int k = 1 ; k <= j-2 ; k++)
        {
            double tmp = b[k][j-1]+g[k][j];
            if(tmp < b[j-1][j])
                b[j-1][j]=tmp;
        }
    }

    b[n][n] = b[n-1][n] + g[n-1][n];
    return b[n][n];
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 1 ; i <= n ; i++)
            scanf("%d%d",&p[i].x,&p[i].y);

        for(int j = 2 ; j <= n ; j++)
            for(int i = 1 ; i <j ; i++)
                g[i][j] = dis(p[i],p[j]);

        printf("%.2lf\n",dp());
    }
    return 0;
}
