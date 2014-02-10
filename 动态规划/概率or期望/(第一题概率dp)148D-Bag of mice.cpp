/*
 * 题意：
 * 原来袋子里有w只白鼠和b只黑鼠
 * 龙和王妃轮流从袋子里抓老鼠。谁先抓到白色老鼠谁就赢。
 * 王妃每次抓一只老鼠不会有老鼠跑出，龙每次抓完一只老鼠之后会有一只老鼠跑出来。
 * 每次抓老鼠和跑出来的老鼠都是随机的。
 * 如果两个人都没有抓到白色老鼠则龙赢。王妃先抓。
 * 问王妃赢的概率。
 *
 * 概率dp
 * 一般求概率是顺推，求期望是逆推
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

int w,b;
double dp[1010][1010]; //dp[i][j]轮到王妃时剩下i只白老鼠，j只黑老鼠

int main()
{
    cin >> w >> b;
    clr(dp,0);
    for(int i = 1 ; i <= w ; i++)
        dp[i][0]=1;

    //dp构造的依据
    //王妃赢的概率 = 这次王妃赢的概率+下次王妃赢的概率+下下次...
    //虽然每一次转移直观上是这次+下次
    //但是下次的两种情况里,d[i][j-3],dp[i-1][j-2]也是由它们的下次赢的概率转换过来的
    //因为对于每一个dp[i][j]，都+了本次赢的概率
    //所以最后一定是没输*没输*...*赢了
    //即赢了 = 本次赢了+(本次没输 * (下次赢了 + 下次没输 * (下下次赢了 + 下下次没输 * (... * 最后赢了)))) <-> 总局赢了 = 本次赢了+本次没输*子局赢了
    for(int i = 1 ; i <= w ; i++)
        for(int j = 1 ; j <= b ; j++)
        {
            //抓到了白老鼠
            dp[i][j] += 1.0*i/(i+j);
            //抓到了黑老鼠，下一次龙抓到了黑老鼠，跑了黑老鼠
            if(j >= 3) dp[i][j] += 1.0*j/(i+j)*dp[i][j-3]*(1.0*(j-2)/(i+j-2))*(1.0*(j-1)/(i+j-1));
            ////抓到了黑老鼠，下一次龙抓到了黑老鼠，跑了白老鼠
            if(j >= 2) dp[i][j] += 1.0*j/(i+j)*dp[i-1][j-2]*(1.0*i/(i+j-2))*(1.0*(j-1)/(i+j-1));
        }
    printf("%.9lf\n",dp[w][b]);
    return 0;
}
