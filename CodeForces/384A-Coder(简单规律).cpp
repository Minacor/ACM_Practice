/*
 * 题意：问一个n*n的棋盘上最多能放几个C能使他们上下左右不相邻，输出C的个数和其中一种方法
 *
 * 思路：个数满足 (n*n+1)/2
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
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;

int main()
{
    int n;
    cin >> n;
    int ans=0;

    ans = (n*n+1)/2;

    cout << ans << endl;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if((i+j)%2)
                cout << '.';
            else
                cout << 'C';
        }
        cout << endl;
    }
}
