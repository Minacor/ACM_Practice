/*
 * 题意：一群牛从1-N编号后乱序排列，输入是当前牛前面排的比它编号小的牛数，第一头牛由于是0故忽略，
 * 输出乱序排列的牛的编号
 *
 * 思路：从后往前推，假如排在最后的一头牛比他编号小的数量为a，那么它的编号必然为a+1，因为前面出现了所有的1~a数。(规则1)
 * 我们把编号为a+1的这头牛删掉，假如排在倒数第二的一头牛比他编号小的数量为b，那么该牛就为删掉编号后剩余牛中的第b+1头牛，我们可以照此思路下去...
 * 问题就可以转化为搜索排在第k位的数为多少
 *
 * 用树状数组解：
 * 倒序推。刚开始的时候把n个位置都准备好，然后塞牛，塞一头就把相关的位置减1，表示之前能站的地方少了一个。
 * 然后倒序找位置的时候，用的是二分查找。因为树状数组的和是有序的
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
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;

int n;
int tree[8100];         //树状数组模拟的是这样一个序列:0 1 0 1 1 ... 其中1表示这个位置可以塞牛，0表示不可以。
                        //因为逆序，所以已用的一定排在当前判断的后面，不会影响计数
int out[8100];
int order[8100];

int lowbit(int t)
{
    return t&(-t);
}

void modify(int pos , int delta)
{
    for( ;  pos <= n ; pos += lowbit(pos))
        tree[pos] += delta;
}

int getsum(int pos)
{
    int t=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        t += tree[pos];
    return t;
}

int Bsearch(int aim)      //找到一个位置，使得在它之前(包括自己)的可用位置和为aim，依据规则一，这个位置标号必定是aim
{
    int mid , l = 1 , r = n;

    while(l <= r)
    {
        mid = (l+r) >> 1;
        if(getsum(mid) >= aim)
            r = mid-1;
        else
            l = mid+1;
    }

    return l;
}

int main()
{
    freopen("in.txt" , "r" , stdin);

    scanf("%d",&n);

    for(int i = 1 ; i <= n ; i++)
    {
        if(i > 1)
            scanf("%d",order+i);
        modify(i,1);                                    //把所有位置准备好，表示都可以站牛，即(1,1,1,1...)
    }

    for(int i = n ; i >= 1 ; i--)
    {
        out[i] = Bsearch(order[i]+1);                   //根据规则1，我们寻找这样的a+1的位置
        modify(out[i],-1);                              //把安排完的位置去掉(即置0)
    }

    for(int i = 1 ; i <= n ; i++)
        printf("%d\n",out[i]);

    return 0;
}

/* 第一组case执行过程:
 初始 : 1 1 1 1 1
 一   : order[i]+1=1，而getsum(1)=1,故返回1,1位置零，变成 0 1 1 1 1
 二   : order[i]+1=2, 而getsum(3)=2,故返回3,3位置零，变成 0 1 0 1 1
 ...
 */
