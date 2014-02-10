/*
 * 题意：
 * 输入一个n个元素的数列和一个数x，判断最少要增加几个数使得排序以后的x在数列中间
 * 中间的定义：(n+1)/2向下取整
 *
 * 思路：
 * 首先判断x是否在原数列中，不在则加入，非常重要的一步，能使程序大大简化
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

int l,r;
int a[1000];
int n,x;

int main()
{
    cin >> n >> x;
    int ans=1;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        if(a[i]==x)
            ans=0;
    }
    if(ans)     //如果不在就加入
        a[++n]=x;
    sort(a+1,a+n+1);

    //l:第一次出现x的位置;r:最后一个x的位置
    l = lower_bound(a+1,a+1+n,x)-a; //lower_bound,返回一个迭代器，指向第一个>=x的元素
    r = upper_bound(a+1,a+1+n,x)-a-1;//upper_bound，返回一个迭代器，指向第一个>x的元素

    // 1 2 3 4 5 6 7
    int mid = (n+1)/2;
    if(l <= mid && mid <= r)        //x本身已在中间
        cout << ans << endl;
    else if(l > mid)                //第一个x出现在中间右边，则要补的元素个数就是l左边的-l右边的，此情况下必须将数列补到奇数个
        cout << (l-1)-(n-l)+ans << endl;
    else if(r < mid)                //最后一个x出现在中间左边，类似补数，要注意的是将数列补足到偶数个数就可以了
        cout << (n-r)-r+ans << endl;
    return 0;
}
