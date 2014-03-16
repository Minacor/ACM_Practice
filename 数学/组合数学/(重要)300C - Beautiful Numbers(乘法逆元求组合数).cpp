/*
 * 题意：
 * 给三个数a,b,n
 * 定义good number : 某个数中每个数位除了a就是b
 * 定义exc number : 某个数是good num ， 并且其所有数位上的数的和sum也是good num
 * 求长度为n的所有数中exc num的数量
 *
 * 思路：
 * 一个符合要求的数一定是由i个a和n-i个b组成的，所以只要枚举i，然后判断下a*i+(n-i)*b是不是good num就行了
 * 是的话，就有C(n,i)种情况，本题重点就是求组合数，n很大，递推肯定超时，但不递推，用普通除法是不能用同余定理的
 * 所以这里就要用到乘法逆元
 * 网上搞了个模板
 * http://www.cnblogs.com/fzf123/archive/2013/04/27/3047997.html
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
const int MAX = 100+100+2*100+100;
const int inf = 522133279;
const int mod = 1000000007;

LL a,b;
int n;
LL pre[1000000+100];

int ju(LL x)
{
    int ok=1;
    while(x)
    {
        if(x%10!=a && x%10!=b)
        {
            ok=0;
            break;
        }
        x/=10;
    }
    return ok;
}

LL inv(LL aim)          //lnv(x)求的就是x的乘法逆元，C(n,x) = n! / ( (n-x)!  *  x! ) (mod p) =  n! * inv( (n-x)!  *  x!)
{
    LL tmp=1;
    aim %= mod;
    LL m = mod-2;

    while(m)
    {
        if(m&1) tmp = tmp*aim%mod;
        aim = aim*aim%mod;
        m >>= 1;
    }
    return tmp;
}

int main()
{
    //FR;
    cin >> a >> b >> n;

    if(a==b)
    {
        cout << ju(a*n) << endl;
        return 0;
    }

    pre[0]=1;
    for(int i = 1 ; i <= n ; i++)
        pre[i] = (pre[i-1]*i) % mod;

    LL res=0;
    for(int i = 0 ; i <= n ; i++)
    {
        if(ju(a*i+(n-i)*b))
            res = (res + pre[n]*inv(pre[i]*pre[n-i])) % mod;
    }
    cout << res << endl;
    return 0;
}


