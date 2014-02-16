/*
 * 题意：
 * 在a,b中找出最长的串s，使得s是a的前缀，同时是b的后缀
 *
 * 思路：
 * 裸扩展KMP，但注意一点:
 * 模式串a可能比文本串b长，这时就要特判ret[0];
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
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int next[50010],ret[50010];

void getnext(string a)
{
    clr(next,0);
    clr(ret,0);
    int m=a.size();
    int i,j,k;
    for(i=0;i<m-1&&a[i]==a[i+1];i++);
    next[1]=i;

    k=1;
    for(i=2;i<m;i++)
    {
        int len = k+next[k],L=next[i-k];
        if(L < len-i)
            next[i]=L;
        else
        {
            for(j = max(0,len-i);i+j<m&&a[j]==a[i+j];j++);
            next[i]=j;
            k=i;
        }
    }

}

void extendKMP(string a , string b)
{
    getnext(a);
    int m = a.size(),n = b.size();
    int i,j,k=0;
    for(j=0;j<n&&j<m&&a[j] == b[j];j++);
    ret[0]=j;

    if(ret[0]==b.size())    //如果整个b就是a的前缀,特判
    {
        cout << b << ' ' << b.size() << endl;
        return ;
    }
    k=0;
    for(i=1;i<n;i++)
    {
        int len = k+ret[k],L=next[i-k];
        if(L<len-i)
            ret[i]=L;
        else
        {
            for(j = max(0,len-i);j<m&&i+j<n && a[j]==b[i+j];j++);
            ret[i]=j;
            k=i;
        }

        if(n-i==ret[i])
        {
            cout << b.substr(i) << ' ' << ret[i] << endl;
            return ;
        }
    }

    cout << 0 << endl;
}

int main()
{
    string a,b;
    while(cin >> a >> b)
        extendKMP(a,b);
    return 0;
}
