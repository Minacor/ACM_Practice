/*
 * 题意：
 * 对于每一个i，令v(i)是不超过i的最大素数，u(i)是>i的最小素数
 * 给定一个n 求∑(2,n) 1/(v(i)*u[i])
 *
 * 思路：
 * 两个素数a,b之间的所有1/(v(i)*u[i])和是(b-a)/ab = 1/a-1/b
 * 然后发现上式是裂项相消的标准式子
 * 所以只要找到n的v(n)=down , u(n)=up ,他们的答案就是1/2-1/up-(up-n-1)/up*down
 * 即用裂项相消算出n = up时的和，再减去多算的后缀(up-n-1)/up*down
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
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
//const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int prime(LL x)
{
    for(LL i = 2 ; i*i <= x ; i++)
        if(x%i==0)
            return 0;
    return 1;
}

LL gcd(LL x , LL y)
{
    if(y==0) return x;
    return gcd(y,x%y);
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        LL n;
        cin >> n;

        LL down = n,up = n+1;
        while(!prime(down))down--;
        while(!prime(up))up++;

        LL delta = up-n-1;

        LL fenzi = down*(up-2)-2*delta;
        LL fenmu = 2*up*down;
        LL g = gcd(fenzi,fenmu);
        cout << fenzi/g << "/" << fenmu/g << endl;
    }
    return 0;
}
