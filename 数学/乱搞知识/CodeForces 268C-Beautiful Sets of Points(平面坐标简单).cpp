/*
 * 题意：
 * 在一个横坐标上限n，纵坐标上限m的坐标系中，找出元素数量最多的整点集
 * 使得点集中的任何两个点的距离不是整数
 *
 * 思路：
 * 很显然，一条平行于坐标轴的直线上不可能出现两个以上的点，所以集合元素最大为min(n,m)
 * 所以依据较小的边安排一条正方形的对角线就可以了，这样就能保证任何点之间的距离为n*sqrt(2)
 * 且集合元素取到最大值
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
const int MAX = (1<<15)+100;
const int inf = 522133279;

int main()
{
    int n,m;
    cin >> n >> m;
    int ok=0;
    if(n<m)
        swap(n,m);

    cout << m+1 << endl;
    int j=0;
    for(int i = m ; i >= 0 ; i--)
        cout << j++ << ' ' << i << endl;

    return 0;
}
