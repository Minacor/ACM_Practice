/*
 * 题意：
 * 给定第一个数是数据组数t
 * 然后每组两个数n p ，要求构造这样的图：
 * 1 母图恰好有2n+p条边
 * 2 没有自环和重边
 * 3 对于任意顶点数为k(1<=k<=n)的子图，其边数 <= 2k+p
 * 输出就是2n+p条边的两个端点
 *
 * 思路：
 * 大概框架：
 * 从子图k=2开始构造，能够构造完全图的就构造完全图
 * 直到不能构造完全图以后，每往其中加一个点x，就加边(1,x),(2,x)...(x-1,x)，加到满足边数mk <= min( k(k-1)/2 , 2k+p) 为止
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
#define FO (freopen("out.txt","w",stdout))
#define clr(a,b) memset(a,b,sizeof(a))
#define mkp make_pair
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 1000000;
const int inf = 522133279;
const int mod = 1000000007;

int n,p;
int mir[30];

map< pair<int,int> , int> out;

int main()
{
    int t;
    for(int i = 5 ; i <= 24 ; i++)
        mir[i] = (i*i-5*i)/2;       //当顶点数为i时，若p < mir[i]时就不能构造完全图了，只能构造边数为k*(k-1)/2 - (mir[k]-p)的图

    cin >> t;
    while(t--)
    {
        out.clear();
        cin >> n >> p;

        for(int x = 1 ; x <= 5 ; x++)
            for(int y = x+1 ; y <= 5 ; y++)
                out[mkp(x,y)]++;

        for(int k = 6 ; k <= n ; k++)
        {
            int full = k*(k-1)/2 - (mir[k]-p);

            for(int x = 1 ; x < k ; x++)
                if(out.size() < full)
                    out[mkp(x,k)]++;
            if(out.size() == 2*n+p)
                break;
        }

        map< pair<int,int> , int> ::iterator it = out.begin();
        for( ; it != out.end() ; it++)
            cout << (it->first).first << ' ' << (it->first).second << endl;
    }

    return 0;
}
