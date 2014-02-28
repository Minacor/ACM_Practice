/*
 * 题意：
 * 输入数据：
 * 第一行一个数n:表示给一棵根节点id=1的根树，根树的所有节点的初始值为0
 * 第二行n-1个数p2,p3...pn，pi表示第i个表示id=i的节点的父节点是pi
 * 第三行一个数m:表示有m个询问，接下来m行询问
 * 询问有两种方式：
 * 1) 1 pos x k：距离id=pos的点的距离为i(i>=0,0表示pos自身)的子节点的值加上x-i*k
 *               距离指的是两点之间边的数量
 * 2) 2 pos : 输出id=pos的点的当前值
 *
 * 思路：
 * 树状结构转利用dfs转化为线性结构，st[pos]~ed[pos]表示以pos为根节点的子树，同时利用lv[pos]记录pos到根节点的距离(即深度)
 * 树状数组模拟差分数列计数，利用两个树状数组，getsum取得的就是当前id=pos的点的值
 *
 * 接下来可能稍微难理解一点，也是本题核心
 * 两个树状数组维护，第一个使得st[pos]~ed[pos]这颗子树上的节点的值全部加上x+lv[pos]*k
 * 第二个树状数组使得子树上的节点的值全部加上k
 * 那么每一次询问，curpos的真实值就是getsum(first_tree,curpos)-lv[curpos]*getsum(second_tree,curpos)
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
const int MAX = 300000+100;
const int inf = 522133279;
const int mod = 1000000007;

LL tree[2][MAX];
LL lv[MAX];

struct edge
{
    LL now;
    LL next;
}e[MAX];

LL head[MAX];
LL vis[MAX];
LL index,cnt;
LL n;
LL st[MAX] , ed[MAX];

LL getsum(LL id , LL pos)
{
    LL ans=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        ans = (ans+tree[id][pos])%mod;
    return ans;
}

void modify(LL id , LL pos , LL delta)
{
    for( ; pos <= n ; pos += lowbit(pos))
        tree[id][pos] = (tree[id][pos]+delta)%mod;

}

void dfs(LL cur,LL deep)
{
    vis[cur]=1;
    st[cur]=ed[cur]=++index;
    lv[cur]=deep;
    for(LL i = head[cur] ; i+1 ; i=e[i].next)
    {
        LL next = e[i].now;
        if(!vis[next])
            dfs(next,deep+1);
    }
    ed[cur]=index;
}

void add(LL x , LL y)
{
    e[cnt].now = y;
    e[cnt].next = head[x];
    head[x] = cnt++;
}

void init()
{
    clr(head,-1);
}

int main()
{
    cin >> n;
    init();
    for(int i = 2 ; i <= n ; i++)
    {
        LL a;
        cin >> a;
        add(a,i);
    }
    dfs(1,1);
    int m;
    cin >> m;
    while(m--)
    {
        int op;
        cin >> op;

        if(op==1)
        {
            LL a,x,k;
            cin >> a >> x >> k;
            modify(0,st[a],(x+k*lv[a])%mod);
            modify(0,ed[a]+1,-(x+k*lv[a])%mod);
            modify(1,st[a],k);
            modify(1,ed[a]+1,-k);
        }
        else
        {
            LL pos;
            cin >> pos;
            //注意这里，减之后可能负值很小，所以+一个mod不够
            cout << ((getsum(0,st[pos])-lv[pos]*getsum(1,st[pos])+mod)%mod+mod)%mod << endl;
        }
    }

    return 0;
}


