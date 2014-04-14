/*
 * 题意：
 * 首先是错误理解：
 * {
 *     给n个点(0~n-1)和m个操作
 *     M a b表示连接ab点
 *     S a表示删除与a点直接相连的所有边
 *     问最后的连通分支数
 *     初始时候所有点不连通
 * }
 * 正确理解：
 * {
 *     M a b表示把ab放进同一个集合
 *     S a表示把a从其属于的集合中删除
 *     也就是说M 0 1,M 0 2, S 0之后，1,2,还是属于同一集合的
 *     问最后有多少不同集合
 * }
 *
 * 思路：
 * 并查集删点
 * 删除当前节点，准确的说是从当前节点集合中剔除当前节点，它的子节点不要动。
 * 普通的并查集在合并的时候有些节点是有子节点的，如果删除了这个节点的关系（把它的父亲设置为自己），那么当它的子节点合并的时候就找不到父亲了。
 * 解决的方法有两种：（很直接的）遍历所有的节点，find(x),归并到根，显然不可能。
 * 或者在插入的时候，每一个节点都是叶子节点，那么删除的时候就很方便，不会有没有归并到根的子节点了。
 */

//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define mkp make_pair
using namespace std;
typedef long long LL;
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int n,m;
int f[2000000+100];
int vf=1000000+1;

int find(int x)
{
    return x!=f[x] ? f[x] = find(f[x]) : x;
}

void merger(int x , int y)
{
    int tx = find(x);
    int ty = find(y);

    if(tx!=ty)
    {
        if(tx > 1000000)            //如果有映射到虚拟结点上的树，就合并到那棵树上
            f[ty] = tx;
        else if(ty > 1000000)
            f[tx] = ty;
        else                        //没有的话，就新建一棵虚拟树，并合并到它上面，总之就是避免真实结点之间建立关系！
            f[tx]=f[ty] = vf++;
    }
}

void del(int x)                      //删除一个节点的话，只需新建一棵虚拟树，把这个节点映射到那棵树上就可以了
                                     //假设原来f[x]=vvf,这样的话，只是x这个节点脱离vvf这棵树，其余的点还是在vvf树上，关系没变
{
    f[x] = vf++;
}

bool ok[2000000+100];

int main()
{
    int tot=0;
    while(~scanf("%d%d",&n,&m) && (n||m))
    {
        clr(ok,false);
        getchar();

        for(int i = 0 ; i <= 2000000+10 ; i++)
            f[i]=i;
        for(int i = 0 ; i < m ; i++)
        {
            char op;
            scanf("%c",&op);

            if(op == 'M')
            {
                int a,b;
                scanf("%d%d",&a,&b);
                merger(a,b);
            }
            else
            {
                int a;
                scanf("%d",&a);
                del(a);
            }
            getchar();
        }

        int cnt=0,tt;
        for(int i = 0 ; i < n ; i++)
            if(!ok[tt=find(i)])
            {
                ok[tt]=1;
                cnt++;
            }
        printf("Case #%d: %d\n",++tot,cnt);
    }
    return 0;
}
