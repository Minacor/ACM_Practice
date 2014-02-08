/*
 * 题意：
 * 第一行一个数是4^n ，需要构建一个2^n * 2^n的数阵
 * 接下来4^n个数是要填入数阵里的
 * 一个数阵，如果它是1*1的，那么唯一的一个数就是答案
 * 如果是2^i * 2^i的，那么找到数阵中的最大值，加上这个最大值
 * 然后把这个数阵分成四个2^(i-1) * 2^(i-1)的数阵，继续上述两条的判断
 * 输出最大可以达到的答案
 *
 * 思路：
 * 画个流程图很容易看出来，最大的数被计算n次，接下来前3大的数被计算n-1次，类推
 * 所以只要将输入排个序依次计算就可以了
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

LL a[2000000+100];

LL pow(int n)
{
    if(n==-1)
        return 0;
    LL ans=1;
    for(int i = 1 ; i <= n ; i++)
        ans *= 4;
    return ans;
}

int main()
{
    int n=0;
    LL num;
    cin >> num;
    while(pow(n) != num) n++;

    for(int i = 0 ; i < num ; i++)
        cin >> a[i];

    sort(a,a+num);

    LL pos = num-1;
    LL ans=0;
    LL x=0;

    while(pos >= 0)
    {
        LL up = pow(x)-pow(x-1);
        for( ; up>0 && pos>=0  ; pos--,up--)
            ans += a[pos]*(n+1-x);
        x++;
    }
    cout << ans << endl;

    return 0;
}
