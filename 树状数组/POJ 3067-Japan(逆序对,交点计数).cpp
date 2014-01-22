/*

题意：日本岛东海岸与西海岸分别有N和M个城市，现在修高速公路连接东西海岸的城市，求交点个数。
做法：记每条告诉公路为(x,y), 即东岸的第x个城市与西岸的第y个城市修一条路。当两条路有交点时，满足（x1-x2）*（y1-y2） < 0。
所以，将每条路按x从小到大排序，若x相同，按y从小到大排序。 然后按排序后的公路用树状数组更新，求y的逆序数之和即为交点个数。
上面说的可能有点难理解，详细说明如下。
记第i条边的端点分别为xi,yi。
由于x是从小到大排序的，假设当前我们在处理第k条边，那么第1~k-1条边的x必然是小于（等于时候暂且不讨论）第k条边的 x 的，那么前k-1条边中，与第k条边相交的边的y值必然大于yk的，
所以此时我们只需要求出在前k-1条边中有多少条边的y值在区间[yk, M]即可,也就是求yk的逆序数，M为西岸城市个数，即y的最大值。 所以就将问题转化成区间求和的问题，树状数组解决。
当两条边的x相同时，我们记这两条边的y值分别为ya，yb（ya<yb),我们先处理（x，ya），再处理（x，yb），原因很明显，因为当x相同时，这两条边是认为没有交点的，
若先处理（x，yb），那么下次处理（x，ya）时，（x，ya）就会给（x，yb）增加一个逆序，也就是将这两条边做相交处理了。

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
const int INF = 0xfffffff;

struct node
{
    int x;
    int y;

    bool operator < (const node& b)const
    {
        if(x == b.x)
            return y < b.y;
        return x < b.x;
    }

}p[1000000+100];

int tree[1050];                         //树状数组维护的是各个y值的个数
int n,m,k;

int lowbit(int t)
{
    return t&-t;
}

void modify(int pos , int delta)
{
    for(;pos <= 1010 ; pos += lowbit(pos))
        tree[pos] += delta;
}

int getsum(int pos)
{
    int t=0;

    for(;pos > 0 ; pos -= lowbit(pos))
        t += tree[pos];

    return t;
}

int main()
{
    //FR;
    int t;
    scanf("%d",&t);

    for(int ka =1 ; ka <= t ; ka++)
    {
        memset(tree , 0 , sizeof tree);

        scanf("%d%d%d",&n,&m,&k);

        for(int i = 0 ; i < k ; i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        sort(p,p+k);

        LL ans=0;

        for(int i = 0 ; i < k ; i++)
        {
           int tmp = getsum(m) - getsum(p[i].y); //当前总y值的个数 - <=当前y值的个数，先处理小的y的话，这两个式子里面都是包含增加的数的，所以抵消了
           ans += tmp;
           modify(p[i].y,1);                     //对应的y值数量+1
        }

        printf("Test case %d: %I64d\n",ka,ans);
    }

    return 0;
}
