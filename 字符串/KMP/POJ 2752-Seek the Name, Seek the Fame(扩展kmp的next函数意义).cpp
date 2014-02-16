/*
 * 题意：
 * 给一个字符串，如果其前缀==后缀，输出匹配的长度，从小到大输出
 *
 * 扩展kmp的next函数意义
 * next[i]表示子串s[i...n]的前缀能够匹配原串前缀的最大长度(即公共前缀长度),注意next[0]=0
 * 如果这个长度==n-i，说明子串就是原串的前缀，而这个子串本身是后缀，所以符合条件
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
const int MAXN = 400000+10;
const int inf = 522133279;
const int mod = 1000000007;

int next[MAXN];

void extendKMP(string a)
{
    stack<int> st;
    st.push(a.size());

    int m = a.size();
    int i,j,k;
    for(i = 0 ; i < m-1 && a[i] == a[i+1]; i++);
    next[1]=i;

    k = 1;

    for(i = 2 ; i < m ; i++)
    {
        int len = k+next[k] , L = next[i-k];
        if(L < len-i)
            next[i]=L;
        else
        {
            for(j = max(0,len-i) ; i+j < m && a[j] == a[i+j] ;j++);
            next[i]=j;
            k=i;
        }
    }

    for(i = 0 ; i < a.size() ; i++)
        if(a.size()-i==next[i])
            st.push(next[i]);
    cout << st.top();
    st.pop();
    while(!st.empty())
    {
        cout << ' ' << st.top();
        st.pop();
    }
    cout << endl;
}

int main()
{
    string a;
    while(cin >> a)
    {
        clr(next,0);
        extendKMP(a);
    }
    return 0;
}
