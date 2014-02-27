/*
 * 题意：有n头牛排成一行，0表示朝左看1表示朝右看，每一头牛能看到他面对方向的所有牛
 * 现在对牛挤奶，每挤一头牛，能看到它的牛都会因为惊吓而少产一份奶，挤过奶的不再计算
 *
 * 求以怎样的顺序选择会使产量减少最小，输出最小损失产量
 *
 * 思路：先记录0的个数和1的个数，哪种牛少就先挤哪种牛，挤完之后剩下的牛都朝一个方向，不会再有减产
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

int n;
int a[200000+100];

int main()
{
    int num0=0 , num1=0;
    int tmp;

    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        num0 += !a[i];
        num1 += a[i];
    }

    LL ans=0;

    if(num0 > num1)
    {
        for(int i = 0 ; i < n ; i++)
        {
            if(!a[i]) num0--;
            else ans += num0;
        }
    }
    else
    {
        for(int i = n-1 ; i >= 0; i--)
        {
            if(a[i]) num1--;
            else ans += num1;
        }
    }

    cout << ans << endl;
    return 0;

}
