/*
 * 题意：
 * 多组数据，每组数据一行，两个数：n和m
 * 要求输出(0! + 1! + ... + n!) % m的结果
 *
 * 思路：
 * 纯数学规律题
 * 注意到n超级大而m很小，而且一旦n>=m , n!%m就是0了，后续的计算就没用了
 * 所以当n >= m时只要处理到m就够了
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
using namespace std;
typedef long long LL;
const int MAX = 1000;
const int inf = 522133279;

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        double n;
        int m;
        scanf("%lf%d",&n,&m);

        /*if(n==0&&m==1)
        {
            puts("0");
            continue;
        }*/

        int up = n > m ? m : (int)n;

        LL ans=1;
        LL tmp=1;
        for(int i = 1 ; i <= up ; i++)
        {
            tmp = (tmp*i)%m;
            ans = (ans+tmp)%m;
        }

        printf("%I64d\n",ans%m);        //特别注意的就是这里，如果不%m，上面注释代码块的输出就是1，导致错误
    }

    return 0;
}
