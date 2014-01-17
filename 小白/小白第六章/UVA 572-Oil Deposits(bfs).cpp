/*
 * 题意：@是一个油点，和@八个方向紧邻的算作一个污点，输出多少污点
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

int dir[8][2] = {1,1,-1,1,-1,-1,1,-1,0,1,1,0,-1,0,0,-1};
char g[100][100];
int r,c;

int dfs(int x , int y)
{
    g[x][y] = '*';

    for(int i = 0 ; i < 8 ; i++)
    {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];

        if(tx >= 0 && tx < r && ty >= 0&& ty < c && g[tx][ty] == '@')
            dfs(tx,ty);
    }
}

int main()
{
    while(cin >>r >>c && (r || c))
    {
        for(int i = 0 ;  i < r ; i++)
            cin >> g[i];

        int cnt=0;
        for(int i = 0 ; i < r ; i++)
            for(int j = 0 ; j < c ; j++)
            {
                if(g[i][j] == '@')
                {
                    dfs(i,j);
                    cnt++;
                }
            }
        cout << cnt << endl;
    }

    return 0;
}








