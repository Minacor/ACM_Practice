#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
typedef long long LL;

struct point
{
    int x;
    int y;
}p;

string g[100];
string line;
int n,m;

point sou(int len)
{
    int ok = 1;


    for(int i = 0 ; i <= n-len ; i++)           //下
        for(int j = 0 ; j < m ; j++)
        {
            for(int k = 0 ; k < len ; k++)
                if(line[k] != g[i+k][j])
                {
                    ok = 0;
                    break;
                }

            if(ok)
            {
                p.x = i+1,p.y = j+1;
                return p;
            }
            ok=1;
        }

    ok = 1;

    for(int i = 0 ; i < n ; i++)               //右
        for(int j = 0 ; j <= m-len ;j++)
        {
            for(int k = 0 ;k < len ; k++)
                if(line[k] != g[i][j+k])
                {
                    ok = 0;
                    break;
                }

            if(ok)
            {
                p.x = i+1,p.y = j+1;
                return p;
            }
            ok=1;
        }

    ok = 1;

    for(int i = n-1 ; i >= len-1 ; i--)         //上
        for(int j = 0 ; j < m ; j++)
        {
            for(int k = 0 ; k < len ; k++)
                if(line[k] != g[i-k][j])
                {
                    ok = 0;
                    break;
                }

            if(ok)
            {
                p.x = i+1,p.y = j+1;
                return p;
            }
            ok=1;
        }


    ok = 1;

    for(int i = 0 ; i < n ; i++)                //左
        for(int j = m-1 ; j >= len-1 ; j--)
        {
            for(int k = 0 ; k < len ; k++)
                if(line[k] != g[i][j-k])
                {
                    ok = 0;
                    break;
                }

            if(ok)
            {
                    p.x = i+1,p.y = j+1;
                    return p;
            }
            ok=1;
        }

    ok = 1;

    for(int i = 0 ; i <= n-len ; i++)           //右下
        for(int j = 0 ; j <= m-len ; j++)
        {
            for(int k = 0 ; k < len ; k++)
                if(line[k] != g[i+k][j+k])
                {
                    ok = 0;
                    break;
                }

            if(ok)
            {
                p.x = i+1,p.y = j+1;
                return p;
            }
            ok=1;
        }

    ok = 1;

    for(int i = n-1 ; i >= len-1 ; i--)           //左上
        for(int j = m-1 ; j >= len-1 ; j--)
        {
            for(int k = 0 ; k < len ; k++)
                if(line[k] != g[i-k][j-k])
                {
                    ok = 0;
                    break;
                }

            if(ok)
            {
                p.x = i+1,p.y = j+1;
                return p;
            }
            ok=1;
        }

    ok = 1;

    for(int i = 0 ; i <= n-len ; i++)               //左下
        for(int j = m-1 ; j >= len-1 ; j--)
        {
            for(int k = 0 ; k < len ; k++)
                if(line[k] != g[i+k][j-k])
                {
                    ok = 0;
                    break;
                }

            if(ok)
            {
                p.x = i+1,p.y = j+1;
                return p;
            }
            ok=1;
        }


    ok = 1;

    for(int i = n-1 ; i >= len-1 ; i--)             //右上
        for(int j = 0 ; j <= m-len ; j++)
        {
            for(int k = 0 ; k < len ; k++)
                if(line[k] != g[i-k][j+k])
                {
                    ok = 0;
                    break;
                }

            if(ok)
            {
                p.x = i+1,p.y = j+1;
                return p;
            }
            ok=1;
        }

    return p;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {

        cin >> n >> m;

        for(int i = 0 ; i < n ; i++)
        {
            cin >> g[i];
            for(int j = 0 ; j < g[i].size() ; j++)
            {
                g[i][j] = tolower(g[i][j]);
            }
        }

        int num;
        cin >> num;

        while(num--)
        {

            cin >> line;
            for(int i = 0 ; i < line.size() ; i++)
                line[i] = tolower((line[i]));

            point out = sou(line.size());

            cout << out.x << ' ' << out.y << endl;
        }

        if(t)
            cout << endl;
    }

    return 0;
}



