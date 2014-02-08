/*
 * 数位dp入门题
 *
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
#define lson(x) (x<<1)//从高位到低位枚䀀
#define rson(x) (x<<1|1)
#define FR (freopen("in.txt","r",stdin))
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = (1<<15)+100;
const int inf = 522133279;

int dp[20][20];     //dp[i][j] : 开头是j的合法i位数有几个

void init()
{
    clr(dp,0);
    dp[0][0]=1;
    for(int i = 1 ; i <= 7 ; i++)               //枚举位数，一个数的最高位对应最大编号，如123的1位编号是3
        for(int j = 0 ; j <= 9 ; j++)           //枚举第i位可能出现的//从高位到低位枚举比原数对应位小的数，在这一位数字
            for(int k = 0 ; k <= 9 ; k++)       //枚举第i-1位可能出现的位置
                if(j!=4 && !(j==6&&k==2))
                    dp[i][j] += dp[i-1][k];     //相当于一个i-1位数前面再加一个j
}

int solve(int x)
{
    int digit[10];
    clr(digit,0);
    int len=0;
    while(x)            //拆分数字，digit[i]表示原数的第i位
    {
        digit[++len] = x%10;
        x/=10;
    }

    int ans=0;
    //从高位到低位枚举比原数对应位小的数，在这一位之前的已枚举过的数和原数一样
    //比如原数是654876，当前枚举到第4位了，那么需要统计的数就是65jxxx(0<=j<4)
    for(int i = len ; i >= 1 ; i--)
    {
        for(int j = 0 ; j < digit[i] ; j++)
           if(j!=4 && !(j==2&&digit[i+1]==6))
                ans += dp[i][j];
        if( digit[i] == 4 || (digit[i]==2&&digit[i+1]==6))//已经枚举过的数中出现不合法子数就直接退出
            break;
    }

    return ans;
}

int main()
{
    //FR;
    int l,r;
    init();
    while(cin >> l >> r && (l||r))
    {
        //solve(x)解决的是比x小的数，所以r要+1
        cout << solve(r+1) - solve(l) << endl;
    }
    return 0;
}
