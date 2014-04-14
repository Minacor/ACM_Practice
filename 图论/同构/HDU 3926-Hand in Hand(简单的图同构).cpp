/*
 * ���⣺
 * ����������ͼ��ͼ�еĶ�������Ϊ2���ж��Ƿ���ͬ��ͼ
 *
 * ˼·��
 * ��������Ϊ2������ζ��һ��ͼ���ж����ͨ�����Ļ���ÿ����ͨ����������(����������)���ǻ�
 *
 * �����Ļ���ֻҪ���鼯�ϲ�ͬһ����ͬһ���ϵĵ㣬Ȼ������Ƚ�һ��
 * �������ͼ�Ļ���������ͬ���Ҳ�ͬ����������������ͬ����ͬ���������Ļ�����ͬ����ô������ͼ��ͬ��
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
    int nodenum;                            //��������Ķ�����
    int isloop;                             //��������Ƿ�Ϊ��

    bool operator<(const edge &b)const      //����˳������ν��ֻҪ����ͼ�����������ͬ������
    {
        if(nodenum == b.nodenum)
            return isloop < b.isloop;
        return nodenum < b.nodenum;
    }
}g[2][10100];

int f[2][10100];

int find(int id,int x)
{
    return (x!=f[id][x]) ? f[id][x] = find(id,f[id][x]) : x;
}

void merger(int id , int x , int y)
{
    x = find(id,x);
    y = find(id,y);

    if(x == y)          //����ǻ��ͱ��
        g[id][x].isloop = 1;
    else                //�����ϲ�С�����������涨һ���ϲ����򣬷�ֹ��������ʹ�����Ƚϳ���
    {
        if(g[id][y].nodenum >= g[id][x].nodenum)
        {
            f[id][x]=y;
            g[id][y].nodenum += g[id][x].nodenum;
        }
        else
        {
            f[id][y]=x;
            g[id][x].nodenum += g[id][y].nodenum;
        }
    }
}

int main()
{
    int n1,n2,m1,m2;
    int st,ed;
    int t;
    scanf("%d",&t);

    for(int ka = 1 ; ka <= t ; ka++)
    {
        for(int i = 0 ; i < 2 ; i++)
            for(int j = 1 ; j <= 10010 ; j++)
            {
                g[i][j].isloop=0;
                g[i][j].nodenum=1;
                f[i][j]=j;
            }

        scanf("%d%d",&n1,&m1);
        for(int i = 0 ; i < m1 ; i++)
        {
            scanf("%d%d",&st,&ed);
            merger(0,st,ed);
        }
        scanf("%d%d",&n2,&m2);
        int ok = (n2==n1)&&(m2==m1);            //����������ͬ��һ������ͬ��ͼ

        for(int i = 0 ; i < m2 ; i++)
        {
            scanf("%d%d",&st,&ed);
            if(!ok) continue;
            merger(1,st,ed);
        }

        if(ok)
        {
            sort(g[0]+1,g[0]+1+n1);
            sort(g[1]+1,g[1]+1+n2);

            for(int i = 1 ; i <= n1 ; i++)
                //  �Ƚϣ�ͬ�������g[0]��g[1]Ӧ����һģһ����
                if((g[0][i].nodenum != g[1][i].nodenum) || (g[0][i].isloop!=g[1][i].isloop))
                {
                    ok=0;
                    break;
                }
        }

        printf("Case #%d: %s\n",ka,(ok?"YES":"NO"));
    }

    return 0;
}
