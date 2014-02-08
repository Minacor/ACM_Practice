/*
 * 数位dp入门题,同hdu的不要62，注意数据范围就行
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
#define lson(x) (x<<1)
#define rson(x) (x<<1|1)
#define FR (freopen("in.txt","r",stdin))
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = (1<<15)+100;
const int inf = 522133279;

LL dp[50][10];

void init()
{
    clr(dp,0);
    dp[0][0]=1;

    for(int i = 1 ; i < 50 ; i++)
        for(int j = 0 ; j < 10 ; j++)
            for(int k = 0 ; k < 10 ; k++)
                if(!(j==4 && k==9))
                    dp[i][j] += dp[i-1][k];
}

LL solve(LL x)
{
    int digit[50];
    clr(digit,0);
    int len = 0;
    while(x)
    {
        digit[++len] = x%10;
        x/=10;
    }

    LL ans=0;
    for(int i = len ; i > 0 ; i--)
    {
        for(int j = 0 ; j < digit[i] ; j++)
            if(!(j == 9 && digit[i+1] == 4))
                ans+=dp[i][j];
        if(digit[i+1] == 4 && digit[i] == 9)
            break;
    }

    return ans;
}

int main()
{
    LL r;
    int t;
    cin >> t;
    init();
    while(t--)
    {
        cin >> r;
        cout << (r+1)-solve(r+1) << endl;
    }
    return 0;
}
