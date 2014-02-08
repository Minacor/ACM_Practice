/*
 * 题意：
 * 两个人玩游戏，有一排n个巧克力(一个数列),男从右边吃到左边，女从左到右
 * 每个数字代表吃完巧克力所需时间，一个人不能同时吃两块巧克力，且必须吃完一块之后才能吃下一块
 * 如果两人将要同时开始吃一块巧克力，男让女吃
 * 最后 cout << 女吃的巧克力块数 << ' ' << 男块数
 *
 * 思路：
 * 典型的博弈，平衡博弈，用一个balance表示天平
 * balance > 0表示男方吃完一块巧克力时女方还在吃，反之同理,=0表示两人将同时吃下一块，由题意得此时若只剩一块则男让女
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

int a[100000+100];
int n;

int main()
{
    cin >> n;
    int sum=0;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    int l=0,r=n-1,balance=0;
    int cnt1=0;
    while(l <= r)
    {
        if(balance > 0)
            balance-=a[r--];
        else
            balance+=a[l++];
    }
    cout << l << ' ' << n-l << endl;
    return 0;
}
