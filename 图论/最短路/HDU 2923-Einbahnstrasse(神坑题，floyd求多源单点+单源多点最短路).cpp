/********************************************************

    题意：
    第一行n（最多几个不同地名）,c,r（r条路）
    第二行c+1个地名，第一个地名表示公司所在地
    后c个地名表示破车的所在地，注意地名可能重复！！！！坑死了！！
    然后r条路
    a <-v-- b表示 b->a有一条长为v的路
    a --v-> b表示 a->b有一条长为v的路
    a <-v-> b表示 ab间有一条长为v的双向路

    最后问每辆破车派一辆车去拉，这些车来回所走的最短路总和

    思路：
    floyd找全源最短路


********************************************************/


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
const int MAXN = 1000000+100;
const int inf = 522133279;
const int mod = 1000000007;

int g[1010][1010],rg[1010][1010];
int vis[1010],low[1010];
int n,c,r;
int up;
int R;
map<string , int> lis;
string place[1010];

int getnum(string s)
{
    int res=0;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(isdigit(s[i]))
            res = res*10+(s[i]-'0');
    }
    return res;
}

/*int spfa()
{
    clr(vis,0);
    clr(low,0x1f);
    low[1]=0;
    vis[1]=1;

    queue<int> que;
    que.push(1);

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        vis[cur]=0;

        for(int i = 1 ; i <= up ; i++)
        {
            if(low[i] > low[cur]+g[cur][i])
            {
                low[i] = low[cur]+g[cur][i];

                if(!vis[i])
                {
                    vis[i]=1;
                    que.push(i);
                }
            }
        }
    }
    int res=0;
    for(int i = 2 ; i <= R ; i++)
        res+=low[i];
    return res;
}

int rspfa()
{
    clr(vis,0);
    clr(low,0x1f);
    low[1]=0;
    vis[1]=1;

    queue<int> que;
    que.push(1);

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        vis[cur]=0;

        for(int i = 1 ; i <= up ; i++)
        {
            if(low[i] > low[cur]+rg[cur][i])
            {
                low[i] = low[cur]+rg[cur][i];

                if(!vis[i])
                {
                    vis[i]=1;
                    que.push(i);
                }
            }
        }
    }
    int res=0;
    for(int i = 2 ; i <= R ; i++)
        res+=low[i];
    return res;
}*/

int floyd()
{
    for(int k = 1 ; k <= n ; k++)
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                if(g[i][j] > g[i][k]+g[k][j])
                    g[i][j] = g[i][k]+g[k][j];
    int res=0;
    for(int i = 1 ; i <= c ; i++)
        res+=(g[lis[place[i]]][1]+g[1][lis[place[i]]]);
    return res;
}

int main()
{
    int ka=0;
    while((cin >> n >> c >> r),n+c+r)
    {
        clr(g,0x1f);
        clr(rg,0x1f);
        lis.clear();
        up=0;
        for(int i = 0 ; i <= c ; i++)
        {
            cin >> place[i];
            string tmp=place[i];

            if(!lis[tmp])
                lis[tmp] = ++up;
        }

        for(int i = 0 ; i < r ; i++)
        {
            string a,dir,b;
            cin >> a >> dir >> b;
            if(!lis[a]) lis[a]=++up;
            if(!lis[b]) lis[b]=++up;
            int x = lis[a],y = lis[b];

            int num = getnum(dir);
            if(dir[0]=='<')
                rg[x][y]=g[y][x]=min(g[y][x],num);
            if(dir[dir.size()-1] == '>')
                rg[y][x]=g[x][y]=min(g[x][y],num);
        }

        cout << ++ka << ". " << floyd() <<endl;
    }
    return 0;
}
