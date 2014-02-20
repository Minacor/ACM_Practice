/*
 * 题意：
 * 给一个长为n的序列，可以将它的前m(m = 0~n)个数平移到末尾得到一个新序列，所以一共有n个不同序列
 * 求这n个序列的最小逆序数
 *
 * 思路：
 * 逆序数用树状数组求，只要求出一个逆序数ans，它的将第一个元素移到末尾得到的那个新序列的逆序数也可确定
 * 减少的逆序对为a[i],增加的为n-a[i]-1(因为序列里的数是严格的 0 ~ n-1 )
 * 这样一个循环找最小值即可
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
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;

int n;
int a[5010],tmp[5010];
int tree[5010];

int lowbit(int t)
{
    return t&-t;
}

int getsum(int pos)
{
    int t=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        t+=tree[pos];
    return t;
}

void modify(int pos)
{
    for( ; pos <= n ; pos += lowbit(pos))
        tree[pos]++;
}

int main()
{
    //FR;
    while(~scanf("%d",&n))
    {
        memset(tree,0,sizeof tree);

        for(int i = 1 ; i <= n ; i++)
            scanf("%d",a+i) , a[i]++;

        LL ans=0;
        for(int i = 1 ; i <= n ; i++)
        {
            modify(a[i]);
            ans += getsum(n) - getsum(a[i]);
            a[i]--; //注意变回来 不然找最小值会出错
        }

        LL minc = ans;

        for(int i = 1 ; i < n ; i++)
        {
            ans = ans-(a[i]) + (n-a[i]-1);
            minc = min(minc,ans);
        }

        cout << minc << endl;

    }
    return 0;
}
