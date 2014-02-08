/*
 * 题意：
 * 给一个01串，求其中恰好包含n个1的字串数
 *
 * 思路：
 * dp[i] 表示第i个1到第i+1个1(或字符串结尾)之间的0的个数+1
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
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 200000+100;
const int inf = 522133279;
const int mod = 1000000007;

int dp[1000000+110];

int main()
{
    int n;
    string line;
    cin >> n >> line;
    int sum=0;
    LL ans=0;
    dp[0]=1;
    for(int i = 0 ; i < line.size() ; i++)
    {
        sum += (line[i] == '1');
        if(sum >= n)
            ans += dp[sum-n]; //比如11000010 n=1，当i=6时，增加了1,01,001,0001,00001五个串
                            //i=7时，增加了10,010,0010,00010,000010五个串
                            //sum-n~sum之间包含了恰好n个1，然后往前算0的个数，有x个0就增加了x+1个串
        dp[sum]++;  //  如果sum值没变，说明当前遍历到了一个0，即sum~sum+1之间又多了一个0，故++
    }
    cout << ans << endl;
    return 0;
}
