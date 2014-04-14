/*
 * 题意：
 * 给一个图，每个字母代表一种管道铺设方向，如果水能够从一块田流到另一块，就说明这两块田连通
 * 连通的判断法是：有管道相连
 *
 * 思路：
 * 设置一个dir[][]数组，dir[i][j]表示种类i的田的j方向的管道铺设情况，1表示有管道铺设
 * 用并查集把联通的田放在一个集合
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

int dir[11][4]=
{
    {1,0,0,1},
    {1,1,0,0},
    {0,0,1,1},
    {0,1,1,0},
    {1,0,1,0},
    {0,1,0,1},
    {1,1,0,1},
    {1,0,1,1},
    {0,1,1,1},
    {1,1,1,0},
    {1,1,1,1}
};

int n,m;
int f[3000];

char g[60][60];

int find(int x)
{
    return x==f[x]?x:(f[x]=find(f[x]));
}

void merger(int x,int y)
{
    x=find(x);
    y=find(y);

    if(x!=y)
        f[x]=y;
}

map<int,int> mp;

int main()
{
    while(~scanf("%d%d",&n,&m) && (n>=0&&m>=0))
    {
        mp.clear();
        for(int i = 0 ; i <= n*m+m ; i++)
            f[i]=i;
        for(int i = 1 ; i <= n ; i++)
            scanf("%s",g[i]+1);
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= m ; j++)
            {
                if(i-1>=1 && dir[g[i-1][j]-'A'][2] && dir[g[i][j]-'A'][0])  //上下两田相连的条件是，上有通向下的管道，下有通向上的管道，以下类似
                    merger((i-1)*m+j , i*m+j);
                if(i+1<=n && dir[g[i+1][j]-'A'][0] && dir[g[i][j]-'A'][2])
                    merger((i+1)*m+j , i*m+j);
                if(j-1>=1 && dir[g[i][j-1]-'A'][1] && dir[g[i][j]-'A'][3])
                    merger(i*m+j-1,i*m+j);
                if(j+1<=m && dir[g[i][j+1]-'A'][3] && dir[g[i][j]-'A'][1])
                    merger(i*m+j+1,i*m+j);
            }

        for(int i = m+1 ; i <= m*(n+1) ; i++)
            mp[find(i)]++;
        printf("%d\n",(int)mp.size());
    }

    return 0;
}
