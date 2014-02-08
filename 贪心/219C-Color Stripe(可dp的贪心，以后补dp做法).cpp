/*
 * 题意：
 * 有n条颜色条排成一列，有m种颜色可供选择
 * 要求更改最少的颜色调使得相邻颜色不同
 *
 * 思路：
 * 贪心，当m=2时一定会排列成ABAB或BABA这样的循环序列，只要两种更改都判断一下取最小值即可
 * 当m=3时，一旦遇到相邻颜色相同的一定会更改一种颜色，那么不妨把中间的颜色改成与两边都不同的，至少不会变更差
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

int main()
{
    int n,m;
    string s;
    cin >> n >> m >> s;

    int ans=0;
    if(m!=2)
    {
        s+='.';
        for(int i = 1 ; i < s.size()-1 ; i++)
        {
            if(s[i] == s[i-1])
            {
                if(s[i-1] != 'A' && s[i+1] != 'A')
                    s[i] = 'A';
                else if(s[i-1] != 'B' && s[i+1] != 'B')
                    s[i] = 'B';
                else if(s[i-1] != 'C' && s[i+1] != 'C')
                    s[i] = 'C';
                ans++;
            }
        }
        s.erase(s.end()-1);
    }
    else
    {
        string tmp=s;
        int cnt=0;
        for(int i = 0 ; i < s.size() ; i++)
            if(i&1 && s[i]!='A')
                ans++,s[i]='A';
            else if(!(i&1) && s[i] != 'B')
                ans++,s[i]='B';
        for(int i = 0 ; i < s.size() ; i++)
            if(i&1 && tmp[i]!='B')
                cnt++,tmp[i]='B';
            else if(!(i&1) && tmp[i] != 'A')
                cnt++,tmp[i]='A';
        if(cnt < ans)
        {
            ans=cnt;
            s=tmp;
        }
    }
    cout << ans << '\n' << s << endl;
    return 0;
}
