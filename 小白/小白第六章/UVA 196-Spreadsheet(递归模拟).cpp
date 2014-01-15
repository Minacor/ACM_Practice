/*
 * 题意：给一个表格，其中的公式要把它算成数字，输出表格
 *
 * 思路：递归计算数值，算是一个记忆化搜索吧，题目范围坑爹，其实只需要1000*1000
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

string mir[1010][1010];
int g[1010][1010];

int dfs(int x , int y)
{
    if(g[x][y] != INF)
    {
        return g[x][y];
    }

    string curf = mir[x][y];
    int now=0;
    int curc=0,curr=0;

    for(int i = 0 ; i < curf.size() ; i++)
    {
        if(curf[i] == '+' || curf[i] == '=')
        {
            i++;
            while(isalpha(curf[i]))
            {
                curc = curc * 26 + (curf[i++]-'A'+1);
            }

            while(i < curf.size() && isdigit(curf[i]))
            {
                curr = curr * 10 + (curf[i++]-'0');
            }

            g[curr][curc] = dfs(curr,curc);

            now += g[curr][curc];
            curr=curc=0;
            i--;
        }
    }

    return now;
}

int r,c;
int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        cin >> c >> r;

        for(int i = 1 ; i <= r ; i++)
            for(int j = 1 ; j <= c ; j++)
            {
                cin >> mir[i][j];
                if(mir[i][j][0] != '=')
                {
                    g[i][j] = atoi(mir[i][j].c_str());
                }
                else
                {
                    g[i][j] = INF;
                }
            }

        for(int i = 1 ; i <= r ; i++)
            for(int j = 1 ; j <= c; j++)
            {
                if(g[i][j] == INF)
                    g[i][j] = dfs(i,j);
            }

        for(int i = 1 ; i <= r ; i++)
        {
            cout << g[i][1];

            for(int j = 2 ; j <= c ; j++)
            {
                cout << ' ' << g[i][j];
            }
            cout << endl;
        }
    }

    return 0;

}

/*

1
2 2
1 1
1 =A1+B1

5
1 2
1
=A1
1
0

*/
