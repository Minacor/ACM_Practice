/*
 * 题意：
 * 第一行三个数据：图的行数和列数n,m,要添加k堵墙
 * 给一幅图，图上 '.' 表示可通行 '#'表示墙
 * 要求添加k堵墙以后可行的地方是联通的，输出添加墙以后的地图
 *
 * 思路：
 * dfs是追到根之后在回溯，所以可以在回溯上来的时候设置墙，这样就保证了之前的可行的地方连通
 * 本题数据安排上来看，原图可行地方是联通的，故不用考虑多个连通块
 */
 
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
#define FR (freopen("in.txt","r",stdin))
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 100000+100;
const int inf = 522133279;

string g[510];
int vis[510][510];
int dir[4][2] = {1,0,0,1,-1,0,0,-1};

int n,m,k;

void dfs(int x,int y)
{
    if(k == 0)
        return ;
    vis[x][y] = 1;

    for(int i = 0 ; i < 4 ; i++)
    {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];

        if(tx >= 0 && tx < n && ty >= 0 && ty < m && !vis[tx][ty] && g[tx][ty]!='#')
        {
            dfs(tx,ty);
        }
    }

     if(k)      //注意放墙的代码写在哪
        g[x][y] = 'X',k--;

}
int main()
{
    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; i++)
        cin >> g[i];
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            if(g[i][j] == '.')
                dfs(i,j);

    for(int i = 0 ; i < n ; i++)
        cout << g[i] << endl;
    return 0;
}
