/*
 * ���⣺
 * ��һ�������壬�䶥��ֱ�ΪA,B,C,D��һֻ���ϴ�D����Ҫ��n��(ÿ�ξ�������)�ٻص�D�����м����߷�
 *
 * ˼·��
 * ������A,B,C,D���Ϊ0,1,2,3
 * ��dp[i][j] ��ʾ����i���Ժ��ҵ�ǰ���ڶ�������j���߷�����
 * ��ת�Ʒ��̺�������������� dp[i][j] = ��dp[i-1][k] , k!=j , ��ʾ�Ǵ�k�����ߵ�j��
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

int dp[10000000+100][5];
int n;

int main()
{
    cin >> n;
    clr(dp,0);
    dp[0][0]=dp[1][1]=dp[1][2]=dp[1][3]=1;
    for(int i = 2 ; i <= n ; i++)
        for(int j = 0 ; j < 4 ; j++)
            for(int k = 0 ; k < 4 ; k++)
                dp[i][j] = (dp[i][j] +  (j==k ? 0 : dp[i-1][k])) % mod;
    printf("%d\n",dp[n][0] % mod);
    return 0;
}
