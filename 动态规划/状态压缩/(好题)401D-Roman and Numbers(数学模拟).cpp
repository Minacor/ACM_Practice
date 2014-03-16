/*
 * 题意：
 * 给一个最多18位的n和<=100的m，求有几个这样的x:
 * 1, 能够经过数字重组得到n
 * 2, 没有前导零
 * 3, x%m==0
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
const int MAX = 100+100+2*100+100;
const int inf = 522133279;
const int mod = 1000000007;

LL dp[1<<18][110];  //dp[i][j],当前选择状态下余数为j的种数
LL re=1;            //去重，除以相同数的全排列
int cnt[10];        //记录重复次数
LL jiecheng[20];    //A(n,n)预处理

int main()
{
    jiecheng[0]=1;
    for(int i = 1 ; i < 20 ; i++)
        jiecheng[i]=jiecheng[i-1]*i;

    string line;
    int m;
    cin >> line >> m;
    int len = line.size();

    for(int i = 0 ; i < len ; i++)
        cnt[line[i]-'0']++;
    for(int i = 0 ; i < 10 ; i++)
        re *= jiecheng[cnt[i]];

    dp[0][0]=1;     //什么数都没选时0%m余数为0，一种情况
    int up = 1<<len;
    for(int i = 1 ; i < up ; i++)
        for(int j = 0 ; j < len ; j++)
            if(i & (1 << j))
            {
                int last = i - (1 << j);        //注意枚举j的时候已经规定顺序了
                if((last==0&&line[j]!='0')||last)   //上一状态为0的话，本状态加入的数是非零数，因为没有前导零
                    for(int k = 0 ; k < m ; k++)    //枚举上一状态的余数
                        dp[i][(k*10+(line[j]-'0'))%m] += dp[last][k];
            }
    cout << dp[up-1][0]/re << endl;
    return 0;
}
