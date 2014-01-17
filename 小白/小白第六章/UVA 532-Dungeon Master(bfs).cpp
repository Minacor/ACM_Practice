/*
 * 题意：有l层迷宫，每层迷宫r*c规格，问能不能从S到E
 *
 * 思路：简单的bfs，只不过可以向上和向下走了，增加一维z表示在第几层就可以了
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

int dir[6][3] = { {0,1,0} , {0,0,1} , {0,-1,0} , {0,0,-1} , {1,0,0} , {-1,0,0} };

int l,r,c;

struct node
{
    int x,y,z;
    int time;

    bool operator == (const node&b)const
    {
        return x==b.x && y==b.y && z==b.z;
    }

}s,e;

int border(int x , int y , int z)
{
    return (x >= 0 && x < r) && (y >= 0 && y < c) && (z >=0 && z < l);
}

int vis[50][50][50];
char g[50][50][50];

int bfs()
{
    queue<node> que;

    while(!que.empty())
    {
        que.pop();
    }

    que.push(s);
    node tmp , pre;

    while(!que.empty())
    {
        pre = que.front();
        que.pop();

        for(int i = 0 ; i < 6 ; i++)
        {
            int z = pre.z+dir[i][0];
            int x = pre.x+dir[i][1];
            int y = pre.y+dir[i][2];

            if(border(x,y,z) && !vis[z][x][y] && g[z][x][y] != '#')
            {
                vis[z][x][y]=1;
                tmp.x=x,tmp.y=y,tmp.z=z;
                tmp.time = pre.time+1;
                que.push(tmp);

                if(tmp == e)
                {
                    return tmp.time;
                }
            }
        }
    }

    return -1;
}

int main()
{
    while(cin >> l >> r >> c && (l||r||c))
    {
        memset(g,0,sizeof(g));
        memset(vis,0,sizeof(vis));

        for(int i = 0 ; i < l ; i++)
        {
            for(int j = 0 ; j < r ; j++)
            {
                cin >> g[i][j];

                for(int k = 0 ; k < c ; k++)
                {
                    if(g[i][j][k] == 'S')
                    {
                        s.x=j;s.y=k,s.z=i;
                        vis[i][j][k]=1;
                    }
                    else if(g[i][j][k] == 'E')
                    {
                        e.x=j;e.y=k,e.z=i;
                    }
                }
            }
        }

        int ok = bfs();

        if(ok == -1)
            cout << "Trapped!" << endl;
        else
            printf("Escaped in %d minute(s).\n",ok);
    }

    return 0;
}


/*

2 2 3
S#E
.#.

...
...

*/




