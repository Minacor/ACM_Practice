/*
 * 题意：
 * 给n组命令，P命令表示画上这一条线段，Q命令表示询问的这条线段属于的集合中有多少线段(两线段相交，属于同一集合)
 *
 * 思路：
 * 并查集+求线段相交模板
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

struct node
{
    double x;
    double y;
}p1[1010],p2[1010];     //p1[i]是线段i的一个端点,p2[i]是i的另一个端点

double xx(node a,node b)            //叉乘
{
    return a.x*b.y-a.y*b.x;
}

bool paichi(node a1,node a2,node b1,node b2)    //快速排斥实验
{
    if(min(a1.x,a2.x) <= max(b1.x,b2.x) &&
       min(b1.x,b2.x) <= max(a1.x,a2.x) &&
       min(a1.y,a2.y) <= max(b1.y,b2.y) &&
       min(b1.y,b2.y) <= max(a1.y,a2.y))
        return 1;
    return 0;
}

bool kuali(node a1,node a2,node b1,node b2)     //跨立实验
{
    node b1a1,a1b2,a1a2,b1b2,b1a2;

    b1a1.x = a1.x-b1.x; b1a1.y = a1.y-b1.y;
    b1b2.x = b2.x-b1.x; b1b2.y = b2.y-b1.y;
    a1a2.x = a2.x-a1.x; a1a2.y = a2.y-a1.y;
    a1b2.x = b2.x-a1.x; a1b2.y = b2.y-a1.y;
    b1a2.x = a2.x-b1.x; b1a2.y = a2.y-b1.y;

    if(xx(b1a1,b1b2)*xx(b1b2,b1a2) >= 0)
    {
        b1a1.y = -b1a1.y;
        b1a1.x = -b1a1.x;
        if(xx(b1a1,a1a2)*xx(a1a2,a1b2) >= 0)
            return true;
    }

    return false;
}

int g[1010];            //g[i]：代表元素为i的集合中有多少元素

int f[1010];

int find(int x)
{
    return x!=f[x]?f[x] = find(f[x]) : x;
}

void merger(int x,int y)
{
    x = find(x);
    y = find(y);

    if(x!=y)
    {
        if(g[x] >= g[y])
        {
            f[y]=x;
            g[x] += g[y];
        }
        else
        {
            f[x]=y;
            g[y]+=g[x];
        }
    }
}

int main()
{
    //FR;
    int t;
    scanf("%d",&t);

    while(t--)
    {
        for(int i = 1 ; i <= 1005 ; i++)
            f[i]=i,g[i]=1;
        int n;
        scanf("%d",&n);

        int tot=0;
        for(int i = 0 ; i < n ; i++)
        {
            char op;
            while((op=getchar())=='\n');

            if(op == 'P')
            {
                ++tot;
                scanf(" %lf %lf %lf %lf",&p1[tot].x,&p1[tot].y,&p2[tot].x,&p2[tot].y);
                for(int j = 1 ; j < tot ; j++)
                    if( paichi(p1[j],p2[j],p1[tot],p2[tot]) &&
                        kuali(p1[j],p2[j],p1[tot],p2[tot]))
                        merger(j,tot);
            }
            else
            {
                int id;
                scanf(" %d",&id);
                printf("%d\n",g[find(id)]);
            }
        }

        if(t)
            puts("");
    }
    return 0;
}
