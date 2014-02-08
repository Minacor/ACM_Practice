/*
 * 题意：
 * 输入第一行给一个数n，表示有n堆牌
 * 接下来n行，每一行开头一个数k，表示这堆牌有k张牌，从左到右分别是牌堆的top到bottom
 * 接下来的k个数表示每张牌的面值
 * 现在有两个人a,b要取牌，a只会从每堆牌的top取，b只会从bottom取
 * 两人都是最优决策
 * 问最后两人各自获得的点数
 *
 * 思路：
 * 对于每一堆牌，如果这堆牌是奇数张，就把中间那张存到数组mid中暂不处理
 * 然后每堆牌除中间牌外，左边的牌一定是a的，右边的牌一定是b的
 * 因为两人都是最优决策，如果a能够越过中间牌取到右边的牌x，说明牌x足够优，b会率先拿走这张牌，不让a拿到，所以越界不会发生
 * 这样预先把所有牌堆的左边牌加到a，右边牌加到b，然后对于中间牌的集合mid：
 * 由于a先拿，则a一定会取mid中最大的，然后b拿剩下的最大的....所以将mid排序以后交错加到a，b就可以了
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

int mid[110];
int midcnt;
int n,k;
int a[110];
int l,r;
int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> k;
        for(int j = 1 ; j <= k ; j++)
            cin >> a[j];
        if(k&1) mid[midcnt++] = a[(k+1)>>1];
        for(int i = 1 ; 2*i <= k ; i++)
            l += a[i] , r += a[k-i+1];
    }
    sort(mid,mid+midcnt);
    bool cur=0;
    for(int i = midcnt-1 ; i>=0 ; i--)
    {
        if(!cur) l+=mid[i];
        else r += mid[i];
        cur=!cur;
    }
    cout << l <<' ' << r << endl;
    return 0;
}
