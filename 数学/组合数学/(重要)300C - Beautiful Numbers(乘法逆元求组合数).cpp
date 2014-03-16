/*
 * ���⣺
 * ��������a,b,n
 * ����good number : ĳ������ÿ����λ����a����b
 * ����exc number : ĳ������good num �� ������������λ�ϵ����ĺ�sumҲ��good num
 * �󳤶�Ϊn����������exc num������
 *
 * ˼·��
 * һ������Ҫ�����һ������i��a��n-i��b��ɵģ�����ֻҪö��i��Ȼ���ж���a*i+(n-i)*b�ǲ���good num������
 * �ǵĻ�������C(n,i)������������ص�������������n�ܴ󣬵��ƿ϶���ʱ���������ƣ�����ͨ�����ǲ�����ͬ�ඨ���
 * ���������Ҫ�õ��˷���Ԫ
 * ���ϸ��˸�ģ��
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

LL inv(LL aim)          //lnv(x)��ľ���x�ĳ˷���Ԫ��C(n,x) = n! / ( (n-x)!  *  x! ) (mod p) =  n! * inv( (n-x)!  *  x!)
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


