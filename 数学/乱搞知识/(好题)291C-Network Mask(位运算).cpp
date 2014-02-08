/*
 * 题意：
 * 给n个IP地址(IP address)
 * 已知能够用子网掩码(subnet mask)获得网络地址(network address)
 * 方法是子网掩码的32位二进制数与IP地址的做与运算
 * 且子网掩码一定是111...100...0这样的形式，不会出现01相间的，1占据高位
 * 现输出这样的子网掩码，使得其与n个IP的与运算能够得到恰好m个不同的网络地址
 * 如果有多种结果，输出包含1最少的
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
const int MAX = 200000+100;
const int inf = 522133279;
const int mod = 1000000007;

unsigned int g[100000+100];
map<int,int> cnt;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i = 0 ; i < n ; i++)
    {
        int a,b,c,d;
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        g[i] = (a << 24) | (b << 16) | (c << 8) | d;
    }

    unsigned int ok=0;
    for(unsigned int op = 0xFFFFFFFFu ; op ; op <<= 1)  //一个F代表4个1，注意如果这里op用LL的话，右移操作不会消除最高位的1，导致错误
    {
        for(int i = 0 ; i < n ; i++)
        {
            int tmp = op&g[i];
            ++cnt[tmp];
        }

        if(m == cnt.size())
            ok=op;

        cnt.clear();
    }

    if(!ok) puts("-1");
    else
    {
        unsigned int a,b,c,d;
        a=(ok>>24)&255,b=(ok>>16)&255,c=(ok>>8)&255,d=ok&255;
        printf("%u.%u.%u.%u\n",a,b,c,d);
    }
    return 0;
}
