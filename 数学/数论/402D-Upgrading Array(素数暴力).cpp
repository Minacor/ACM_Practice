/*
 * 题意：
 * 给两个数n，m
 * 给n个数，表示a数组
 * 给m个素数，这些素数叫做"bad prime"，不属于这m个的素数叫做"good prime"
 *
 * 给数组a定义一个beauty值，beauty = ∑f(a[i]),f(x)的计算方法如下：
 * f(1)=0;
 * 假设p是能够整除s的最小素数，则f(s) = f(s/p) +(p is bad prime ? -1 : 1)
 *
 * 然后也可以对a数组进行这样的操作：
 * 选择a数组的前r个元素求gcd，然后这r个数全都 /= gcd，操作数不限，可以为0
 * 求最后能得到的最大的beauty
 *
 * 思路：
 * 题意很容易看出 f(x) = x的所有素因子中good prime的数量 - x的所有素因子中bad prime的数量
 * 那么思路很明确：需要通过操作a使得尽可能地排除多的bad prime
 * 首先预处理出前r个数的gcd，保存在数组中，记为gcd[r]
 * 首先制定一个标记last=1，用来记录最近被除去的那个gcd值，然后逆序枚举每个gcd：
 * 如果f(gcd/last) <= 0 说明x=gcd/last这个数中坏素数更多会使最后的值减小，所以要让前r个数除去这个gcd
 * 反之则不除去
 * 然后f(int x)就是完全的无脑模拟计数和筛选素数过程
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
#define MID(x,y) ((x+y)>>1)
#define FR (freopen("in.txt","r",stdin))
#define FO (freopen("out.txt","w",stdout))
#define clr(a,b) memset(a,b,sizeof(a))
#define mkp make_pair
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 1000000;
const int inf = 522133279;
const int mod = 1000000007;

int n,m;
map<int ,int> bad;
int a[5010],gcd[5010];

int g(int x , int y)
{
    if(y==0)return x;
    return g(y,x%y);
}

int f(int x , int lastprime)
{
    int res=0;
    if(x == 1)
        return 0;

    for(int i = lastprime ; i*i <= x ; i++)
        if(x%i==0)
        {
            if(bad[i]) res += f(x/i,i)-1;
            else res += f(x/i,i)+1;
            return res;
        }
    return bad[x] ? -1 : 1;
}

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    gcd[1]=a[1];
    for(int i = 2 ; i <= n ; i++)
        gcd[i] = g(gcd[i-1],a[i]);

    for(int i = 0 ; i < m ; i++)
    {
        int tmp;
        cin >> tmp;
        bad[tmp]++;
    }

    int ans=0;
    int last=1;
    for(int i = n ; i >= 1 ; i--)
    {
        int ok = f(gcd[i]/last,2);
        if(ok <= 0)
        {
            last = gcd[i];
            ans += f(a[i]/last,2);
        }
        else
            ans += f(a[i]/last,2);
    }
    cout << ans << endl;
    return 0;
}
