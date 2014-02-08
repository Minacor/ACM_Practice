/*
 * 题意：
 * 给n个数，再给一个n位二进制数m(注意这个数是反的，即最左边的是最低位)
 * sum的求法：根据二进制数的数位：如果i位是1就加上a[i],0就不加
 * 求0~m中的二进制数求出的最大和
 *
 * 思路：
 * 贪心很明显，由于二进制数的性质，10000>01111也就是说把当前位由1改为0，把较低位全改为1，所得数一定比原数小
 * 所以枚举m的每一位数，如果是1就把它暂时改0，而后加上所有较低位的a[i]
 * 直接加会超时，之前先做一下求和预处理
 * 由于a和m都是反着给出的，所以枚举的时候也要从后往前枚举
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

int a[100000+100];
int sum[100000+100];
int n;

int getsum(int pos)
{
    int ans=0;
    for( ; pos < n ; pos++)
        ans += a[pos];
    return ans;
}

int main()
{
    string s;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        if(i)
            sum[i] = sum[i-1]+a[i];
        else sum[i]=a[i];
    }
    cin >> s;
//    reverse(a,a+n);
//    reverse(s.begin(),s.end());

    int maxc=0,tmp=0;
    for(int i = s.size()-1 ; i >= 0 ; i--)
    {
        if(s[i] == '1')
        {
            maxc = max(tmp+sum[i]-a[i],maxc);
            tmp += a[i];
        }
    }
    cout << max(maxc,tmp) << endl;
    return 0;
}
