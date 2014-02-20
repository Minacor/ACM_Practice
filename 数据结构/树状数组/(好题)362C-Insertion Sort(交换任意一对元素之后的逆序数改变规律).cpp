/*
 * 题意：
 * 用冒泡排序将一个数列变成升序需要交换ans次
 * 现在任意交换一对数(可以不相邻)，得到一个新的序列和一个新的ans
 * 求最小的ans 和可以得到这个ans的交换对(i,j)的数量
 *
 * 思路：
 * 先得到原数列的ans，可以用树状数组计算
 * 然后设置一个dp数组，dp[i][j]表示min(i,j)~max(i,j)中比j小的数的个数
 *
 * 因为交换两个数以后，原来这两个数中间的数不是逆序的变成了逆序，反之亦然，所以很好推出公式
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

int n;
int a[5100];
int tree[5100];
int dp[5100][5100];

int getsum(int pos)
{
    int t=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        t += tree[pos];
    return t;
}

void modify(int pos , int delta)
{
    for( ; pos <= n ; pos += lowbit(pos))
        tree[pos] += delta;
}

map< int , int > out;

int main()
{
    FR;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        a[i]++;
    }

    for(int i = 1 ; i <= n ; i++)
    {
        dp[i][i]=0;
        for(int j = i-1 ; j >= 1 ; j--)
            dp[j][i] = dp[j+1][i] + (a[j]<a[i]);
        for(int j = i+1 ; j <= n ; j++)
            dp[j][i] = dp[j-1][i] + (a[j]<a[i]);
    }

    int ans=0;
    for(int k = 1 ; k <= n ; k++)
    {
        ans += getsum(n)-getsum(a[k]);
        modify(a[k],1);
    }

    for(int i = 1 ; i <= n ; i++)
        for(int j = i+1 ; j <= n ; j++)
        {
            if(a[i] > a[j])
            {
                int tmp = (ans - 2*dp[j-1][i] + 2*dp[i+1][j])-1;    //这样的公式算的是头尾两数和中间数的逆序关系，所以最后要算上头尾，交换后逆序对少了1，故最后-1
                out[tmp]++;
            }
        }

    map<int , int> :: iterator it = out.begin();
    cout << it->first << ' ' << it -> second << endl;

    return 0;
}
