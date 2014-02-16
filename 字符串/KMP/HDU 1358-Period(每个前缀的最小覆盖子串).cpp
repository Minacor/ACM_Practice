/*
 * 题意：
 * 给一个字符串a
 * 对于a的每一个长度大于1的前缀s,如果它是循环次数大于1的循环串，输出s的长度和最大循环次数
 *
 * 思路：
 * kmp寻找每个前缀的最小覆盖子串,如果这个子串恰好是循环节且子串!=前缀就输出、
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

char a[1000000+100];
int next[1000000+100];
int n;

void getnext()
{
    clr(next,0);
    for(int i = 1 ; i < n ; i++)
    {
        int j=i;
        while(j)
        {
            j=next[j];
            if(a[i]==a[j])
            {
                next[i+1]=j+1;
                break;
            }
        }

        int tmp = i+1-next[i+1];
        if( tmp != i+1&& (i+1)%tmp==0)  //(i+1)%tmp==0表示无多余后缀，即前缀为循环串
            cout << i+1 << ' ' << (i+1)/tmp<<endl;
    }
}

int main()
{
    int ka=1;
    while(scanf("%d",&n),n)
    {
        scanf("%s",a);
        printf("Test case #%d\n",ka++);
        getnext();
        puts("");
    }
    return 0;
}
