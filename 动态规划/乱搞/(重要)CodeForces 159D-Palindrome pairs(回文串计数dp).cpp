/*
 * 题意:
 * 给一个字符串，把一对互不重叠的回文子串称作回文串对，求回文串对对数
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

LL dpl[2100],dpr[2100];     //dpl[i]表示0~i中末尾字符为line[i]的回文子串个数
                            //dpr[i]表示i~end中首字符为line[i]的回文子串个数
int main()
{
    string line;
    cin >> line;
    for(int pos=0 ; pos < line.size() ; pos++)
    {
        //奇偶分类
        for(int l = pos , r = pos ; l>=0&&r<line.size()&&line[l]==line[r] ; l--,r++)
            dpl[r]++,dpr[l]++;
        for(int r = pos+1 , l = pos ; l>=0&&r<line.size()&&line[l]==line[r] ; l--,r++)
            dpl[r]++,dpr[l]++;
    }

    LL ans=dpl[0]*dpr[1];
    for(int i = 1 ; i < line.size() ; i++)
    {
        dpl[i]+=dpl[i-1];       //求和预处理之后，dpl[i]就表示0~i中的回文子串个数
        ans += dpl[i]*dpr[i+1];
    }
    cout << ans << endl;
    return 0;
}
