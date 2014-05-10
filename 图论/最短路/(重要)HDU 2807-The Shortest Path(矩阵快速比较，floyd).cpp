/********************************************************

    题意：
    给定两个数n,m
    给n个m*m的矩阵
    如果矩阵A*B=C，那么就表示A到C有一条单向路径，距离为1.
    然后给定一个数w
    给w个询问，每个询问两个数st,ed
    输出这两个矩阵的最短距离。

    思路：
    本题的核心是O(n)的矩阵快速比较
    这个方法主要是让每个矩阵乘上一个向量(这个向量是<1,2,3,4,...m>)，
    让这个矩阵变成一个一维的标识矩阵，
    之后就利用这个标识矩阵来判断两个矩阵是否相等

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

int n,m;

int mar[100][100][100];
int vec[100][100];      //vec[i][x]表示i这个矩阵的第x行进行向量乘运算后保存的值，这个值等于 ∑ y=(1,m) mar[i][x][y]*y
int g[110][110];

void floyd()
{
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
        {
            if(i!=j)
            {
                for(int x = 1 ; x <= m  ;x++)
                {
                    vec[0][x]=0;            //vec[0]保存当前矩阵相乘以后的值
                    for(int y = 1 ; y <= m ; y++)
                        vec[0][x]+=mar[i][x][y]*vec[j][y];
                }

                for(int k = 1 ; k <= n ; k++)
                {
                    if(k!=i&&k!=j)
                    {
                        int ok=1;
                        for(int x = 1 ; x <= m ; x++)           //直接比较vec[i]的每一维的值即可
                        {
                            if(vec[k][x]!=vec[0][x])
                            {
                                ok=0;
                                break;
                            }
                        }
                        if(ok)
                            g[i][k]=1;
                    }
                }
            }
        }

    for(int k = 1 ; k <= n ; k++)
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
}

int main()
{
    while(~scanf("%d%d",&n,&m) && (n+m))
    {
        clr(g,0x1f);
        clr(vec,0);
        for(int i = 1 ; i<= n ;i++)
        {
            for(int x = 1 ; x <= m ; x++)
                for(int y = 1 ; y <= m ;y++)
                {
                    scanf("%d",&mar[i][x][y]);
                    vec[i][x] += mar[i][x][y]*y;      //计算vec值
                }
        }

        floyd();
        int w;
        scanf("%d",&w);
        while(w--)
        {
            int s,t;
            scanf("%d%d",&s,&t);

            if(g[s][t] == inf)
                puts("Sorry");
            else
                printf("%d\n",g[s][t]);
        }
    }
    return 1;
}
