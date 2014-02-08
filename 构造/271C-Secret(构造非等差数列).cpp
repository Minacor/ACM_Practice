/*
 * 题意：
 * 有k个人分担n个数(1~n)，每个人拿到的数不能重复且最后不能有剩余，且每个人拿到的子数列不能是等差数列
 * 输出一种分配方式，第i个数output[i]表示output[i]这个人拿了i这个数
 *
 * 思路：
 * 由题意知只要有一个人拿的数<=2就一定不可以，故n/k<=2时直接输出-1，表示其中至少有一人拿不到三个数
 * 否则按如下方法构造：
 * 1:首先输出1~n
 * 2:由于保证每人拿的数>=3，之后两两输出1~n
 * 剩余n-3*k个数，集中给第一个人
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
const int MAX = 200000+100;
const int inf = 522133279;
const int mod = 1000000007;

int main()
{
    int n,k;
    cin >> n>> k;
    int len;

    if(n/k <= 2)
    {
        cout << -1 << endl;
    }
    else
    {
        for(int i = 1 ; i <= k ; i++)
            cout << i << ' ';
        for(int j = 1 ; j <= k ; j++)
            cout << j << ' ' << j << ' ';
        n-=3*k;
        while(n--)
            cout << 1 << ' ';
    }
    return 0;
}
