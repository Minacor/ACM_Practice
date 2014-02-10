/*
 * 题意：
 * 定义Anagram:如果a能够经过字母重排得到b，则称a为b的Anagram
 * 现给一个字符串a，其中包含的'?'能够用任何小写字母代替
 * 给一个字符串b，求a中是b的Anagram的子串数
 * 不同位置就算不同子串
 *
 * 思路：
 * 首先若b的长度大于a肯定不行
 * 用cnt保存当前判断字串的字母计数和，mir保存b的字母计数和
 * 从a的头开始枚举长度为b.size()的子串
 * 由于子串和b的长度相同，只要cnt[i] <= mir[i]就必定能有?来补全i字母
 * 所以满足所有字母cnt[i] <= mir[i]的子串就符合条件
 * 当然cnt数组不必每次都清空重新计算，只要把移出的字母减1，移进来的字母加1就行了
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

string a,b;
int cnt[150],mir[150];

int can()
{
    for(int i = 'a' ; i <= 'z' ; i++)
        if(cnt[i] > mir[i])
            return 0;
    return 1;
}

int main()
{
    cin >> a >> b;

    if(a.size() < b.size())
    {
        cout << 0 << endl;
        return 0;
    }

    for(int i = 0 ; i < b.size() ; i++)
    {
        mir[b[i]]++;
        if(isalpha(a[i])) cnt[a[i]]++;
    }

    int ans = can();
    for(int i = 1 ; i+b.size()-1<a.size() ; i++)
    {
        if(isalpha(a[i-1])) cnt[a[i-1]]--;
        if(isalpha(a[i+b.size()-1])) cnt[a[i+b.size()-1]]++;
        ans += can();
    }

    cout << ans;
    return 0;
}