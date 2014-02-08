/*
 * ���⣺
 * ��һ��01����������ǡ�ð���n��1���ִ���
 *
 * ˼·��
 * dp[i] ��ʾ��i��1����i+1��1(���ַ�����β)֮���0�ĸ���+1
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
            ans += dp[sum-n]; //����11000010 n=1����i=6ʱ��������1,01,001,0001,00001�����
                            //i=7ʱ��������10,010,0010,00010,000010�����
                            //sum-n~sum֮�������ǡ��n��1��Ȼ����ǰ��0�ĸ�������x��0��������x+1����
        dp[sum]++;  //  ���sumֵû�䣬˵����ǰ��������һ��0����sum~sum+1֮���ֶ���һ��0����++
    }
    cout << ans << endl;
    return 0;
}
