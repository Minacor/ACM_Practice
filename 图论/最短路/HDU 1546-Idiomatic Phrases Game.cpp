/********************************************************

    题意：
    给一群成语，一个成语能够得到下一个成语的条件是
    前一个的最后4个字符匹配后一个的前4个字符，花费时间为
    解前一个成语的时间

    求由第一个得出最后一个的最短时间

    思路：
    裸的最短路
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
const int MAXN = 1000000+100;
const int inf = 522133279;
const int mod = 1000000007;

int g[1010][1010];
int vis[1010],low[1010];
int n;

struct node
{
    string f;
    string b;
    int t;
}p[1010];

int spfa()
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

        for(int i = 1 ; i <= n ; i++)
        {
            if(low[i] > low[cur]+g[cur][i])
            {
                low[i] = low[cur]+g[cur][i];

                if(!vis[i])
                {
                    que.push(i);
                    vis[i]=1;
                }
            }
        }
    }

    return low[n] == inf ? -1 : low[n];
}

int main()
{
    while(scanf("%d",&n),n)
    {
        clr(g,0x1f);
        for(int i = 1 ; i <= n ; i++)
        {
            string tmp;
            cin >> p[i].t >> tmp;

            p[i].f = tmp.substr(0,4);
            p[i].b = tmp.substr(tmp.size()-4);

            for(int j = 1 ;  j < i  ; j++)
            {
                if(p[i].b == p[j].f)
                    g[i][j] = p[i].t;
                if(p[i].f == p[j].b)
                    g[j][i] = p[j].t;
            }
        }

        cout << spfa() << endl;
    }
    return 0;
}
