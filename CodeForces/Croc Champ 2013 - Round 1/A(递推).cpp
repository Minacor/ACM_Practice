/*
 * 题意：
 * 每一对数代表信息到达的时间和信息个数
 * 每秒只能传送一个信息
 * 求传输时间以及信息累积的最多个数
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

int n;
int dis[2000000+100];

int main()
{
    cin >> n;
    int leiji,maxsize; //leiji记录处理完当前队列里的数据所需的时间，maxsize记录信息阻塞时的最大信息数

    for(int i = 0 ; i < n ; i++)
    {
        int a,b;
        cin >> a >> b;
        if(!i)
        {
            leiji = a+b;
            maxsize = b;
        }
        else
        {
            if(leiji > a)
            {
                maxsize = max(maxsize,leiji-a+b);   //（累计时间-当前时间）就是卡在队列里的信息个数，加上瞬间加入的b个
                leiji = leiji+b;

            }
            else
            {
                maxsize = max(maxsize,b);       //否则队列中没有被卡的信息
                leiji = a+b;
            }
        }

    }
    cout << leiji << ' ' << maxsize << endl;
    return 0;
}
