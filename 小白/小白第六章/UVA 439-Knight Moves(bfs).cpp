/*
 * 题意：给两个国际象棋棋盘上的坐标，输出骑士从第一个坐标到第二个的最短次数
 *
 * 思路：bfs
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
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;

struct point
{
    int x;
    int y;
    int cnt;

    bool operator == (const point &b)const
    {
        return x==b.x && y == b.y;
    }
}s,e;

int dir[8][2] = {-1,2,1,2,1,-2,-1,-2,2,-1,2,1,-2,-1,-2,1};
int vis[10][10];

int bfs()
{
    if(s == e)
        return 0;
    memset(vis,0,sizeof vis);
    queue<point> que;
    point tmp,pre;
    que.push(s);

    while(!que.empty())
    {
        pre = que.front();
        que.pop();

        for(int i = 0; i < 8 ; i++)
        {
            int x = pre.x + dir[i][0];
            int y = pre.y + dir[i][1];

            if(x >= 1 && x <= 8 && y >= 1 && y <= 8 && !vis[x][y] )
            {
                vis[x][y]=1;
                tmp.x=x,tmp.y=y;
                tmp.cnt = pre.cnt+1;
                que.push(tmp);

                if(tmp == e)
                    return tmp.cnt;
            }
        }
    }
}

int main()
{
    string a,b;

    while(cin >> a >> b)
    {
        s.x = a[0]-96;
        s.y = a[1]-'0';
        e.x = b[0]-96;
        e.y = b[1]-'0';

        printf("To get from %s to %s takes %d knight moves.\n",a.c_str(),b.c_str(),bfs());
    }
}

