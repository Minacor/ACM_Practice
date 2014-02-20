/*
 * 题意：
 * 给一个三角阵，其中'.'表示可旋转，'X'表示不可旋转，每个点的颜色不同
 * 旋转：两两相邻的三个'.'(即一个三角形),可以旋转，每一次旋转得到一个相对颜色分布不同的三角形
 * 问给出的三角阵经过各个子三角形旋转得到多少不同的颜色分布
 *
 * 思路：
 * 规律：一个三角形旋转可得到3个 ...
 * 一个子阵中都是'.'，且任意点必与某两点相邻构成一个可旋转三角，总点数为n，则可以得到A(n,n)/2,即n!/2种不同的颜色分布
 * 那么只要统计这样的子阵有几个就可以了，结果累乘
 * 一个点属于一个子阵这样的统计，是并查集的经典运用
 */

#line 2 "HexagonPuzzle.cpp"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
#define OUT(x) cerr << #x << ": " << (x) << endl
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
const int mod = 1000000007;

class HexagonPuzzle {
public:
    vector<string> g;
    int len;
    int f[60*60];
    LL cnt[60*60];

    int find(int x)
    {
        return x != f[x] ? f[x] = find(f[x]) : x;
    }

    void merger(int x , int y)
    {
        x = find(x);
        y = find(y);

        if(x != y)
            f[y]=x;
    }

    //每个点的编号，从上到下，从左至右,1-base
    int pos(int x , int y)
    {
        return (1+x)*x/2+y+1;
    }

    // 判断子阵或者点能否合并成一个
    void ju(int x , int y)
    {
        if(x+1<len && y-1>=0 &&
        g[x+1][y]=='.'&&g[x][y-1]=='.')
        {
            merger(f[pos(x,y)],f[pos(x+1,y)]);
            merger(f[pos(x,y)],f[pos(x,y-1)]);
        }

        if(x-1>=0 && y+1<=x+1&&
        g[x-1][y]=='.'&&g[x][y+1]=='.')
        {
            merger(f[pos(x,y)],f[pos(x-1,y)]);
            merger(f[pos(x,y)],f[pos(x,y+1)]);
        }
    }

    //计算A(n,n)/2
    LL calc(LL n)
    {
        LL sum=1;
        for(LL i = 1 ; i <= n ; i++)
        {
            //注意同余定理对除法不适用！！ 所以要先除掉2，而非计算完毕之后再除2
            if(i==2) continue;
            sum = (sum*i)%mod;
        }
        //sum/=2;
        return sum;
    }

    int theCount(vector <string> board)
    {
        memset(cnt,0,sizeof cnt);
        len = board.size();
        g = board;
        LL sum=1;
        int tot = (1+len)*len/2;
        for(int i = 0 ; i <= tot ; i++)
            f[i]=i;

        for(int i = 0 ; i < board.size() ; i++)
            for(int j = 0 ; j <= i ; j++)
                if(board[i][j] == '.')
                    ju(i,j);

        for(int i = 1 ; i <= tot ; i++)
            cnt[find(i)]++;
        int ok=0;
        for(int i = 1 ; i <= tot ; i++)
        {
            if(cnt[i] < 3)
                continue;
            else
            {
                cout << cnt[i] << endl;
                sum = (sum * calc(cnt[i]))%mod;
            }
        }

        return int(sum%mod);
    }