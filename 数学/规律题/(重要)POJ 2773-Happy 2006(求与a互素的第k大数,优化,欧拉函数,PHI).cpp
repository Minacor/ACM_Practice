/*
 * 题意：
 * 求与m互素的第K大数
 *
 * 思路：
 * 有几个重点
 * 1:首先是基本思想，题目中k>m
 *   根据欧拉函数：gcd(a,m)=gcd(a+k*m,m),可知区间[1,m],[m+1,m+m]...[(n-1)m+1,nm]中与m互素的数的个数是相同的
 *   把这个数称为PHI
 *   这样我们只要求出[1,m]中的与m互素的数就行了,可以直接gcd判断区间中每一个数
 *   但是仅仅这样，程序只能跑2400+，所以要优化
 * 2:优化1：
 *   计算PHI，这里有个模板过程
 *   在计算PHI时，其实已经对m进行分解，求出了m的所有素因子
 *   再想，所有与m不互素的数，都至少与m有一个公共素因子
 *   于是，我们可以在每次找到一个m的素因子后，将它的整数倍标记，这样，后面枚举的时候就可以用O(1)的时间判断了
 *   这样能跑到300+ms
 * 3:优化2：
 * 因为m <= 1000000 所以算出sqrt(m)，也就是1000以内的素数就可以了，这样能跑到几十ms，大功告成
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

int gcd(int x , int y)
{
    if(y == 0)
        return x;
    return gcd(y,x%y);
}

int p[1000000+100],isp[1000000+100];
int ishuzhi[1000000+100];
int len,pnum;       //PHI,1000以内素数个数
int huzhi[1000000+100]; //标记互质数

void prime()        //获取1000以内的素数
{
    for(int i = 2 ; i <= 1000 ; i++)
        if(!isp[i])
        {
            p[pnum++]=i;
            for(int j = i*2 ; j <= 1000 ; j+=i)
                isp[j]=1;
        }
}

void init(int x)        //求PHI模板
{
    len=1;
    clr(ishuzhi,0);

    int xx = x;
    for(int i = 0 ; i < pnum ; i++)
    {
        if(xx%p[i]==0)      //如果此素数是m的因子，就按优化1处理，并从m中除去这个因子
        {
            len *= p[i]-1;
            xx/=p[i];

            for(int j = p[i] ; j <= x ; j += p[i])
                ishuzhi[j]=1;

            while(xx%p[i]==0)
                xx/=p[i],len*=p[i];
        }
    }
    if(xx > 1)
    {
        len *= xx-1;
        for(int j = xx ; j <= x ; j += xx)
            ishuzhi[j]=1;
    }
    /*for(int i = 1 ; i <= x; i++)      PHI也可以这么求，huzhi内储存互质数,这样就不用写下面的getcur了
        if(!ishuzhi[i]) huzhi[len++]=i;*/
}

int getcur(int aim,int x)       //获得此区间的第aim+个数
{
    int cnt=0;
    for(int i = 1 ; i <= x ;i++)
    {
        if(!ishuzhi[i]) cnt++;
        if(cnt == aim)  return i;
    }
}

int main()
{
    int a,b;
    prime();

    while(~scanf("%d%d",&a,&b))
    {
        init(a);
        if((b%len)==0)
            printf("%d\n", a*(b/len-1)+getcur(len,a));
        else
            printf("%d\n",a*(b/len)+getcur(b%len,a));
    }

    return 0;
}
