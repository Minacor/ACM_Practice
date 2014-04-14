/*
 * 题意：
 * 给定由N个字母组成的密码锁，如【abcdef】每一位字母都可以转动，转动该字母时，将变成它的下一个字母，
 * 如‘a'转动后是b,x转动后是y,
 * 接着给定M个区间，每次转动给定区间内的所有字母，
 * 如密码锁【abcdef】，给定区间【1,3】转动这个区间一次后变为【bcddef】
 * 如果一把锁经过若干转动能变成另一把锁，则这两把锁被认为是相同的
 * 求有多少不同的锁
 *
 * 思路：
 * 最初没有区间的时候，情况是26^n，每增加一个区间(不论长度和位置)，情况都要除去26，即变成26^(n-1)种
 * 因为增加一个区间，相对位置不变的情况都算作一种
 * 这里要注意，如果两个区间是[1,2],[3,6],那么再增加[1,6]时不应该算作新区间，因为能够通过前两个组合成第三个
 * 但是[1,2],[2,6]还是应该把[1,6]算作新区间
 * 于是并查集的作用就是：判断当前区间能否被之前的区间组合出来
 * 具体做法是：每次遇到一个新的区间，就合并[l,r+1]，同时n-=1
 * 最后由于n可能特别大，需要二分求幂
 */

//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define mkp make_pair
using namespace std;
typedef long long LL;
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int t;
int f[10000000+100];
int n,m;

int find(int x)
{
    return x==f[x]?x:f[x]=find(f[x]);
}

int merger(int x , int y)
{
    x = find(x);
    y = find(y);

    if(x!=y)
    {
        f[x]=y;
        return 1;
    }
    return 0;
}

LL mi(int n)            //二分求幂的姿势
{
    LL ans=1,tmp=26;
    while(n)
    {
        if(n&1)
            ans=(ans*tmp)%mod;
        tmp = (tmp*tmp)%mod;
        n/=2;
    }
    return ans%mod;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i = 0 ; i <= n+1 ;  i++)        //初始化注意！由于是r+1了所以上限是n+1！！
            f[i]=i;
        for(int i = 0 ; i < m ; i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            n-=merger(l,r+1);
        }
        printf("%I64d\n",mi(n));
    }
    return 0;
}
