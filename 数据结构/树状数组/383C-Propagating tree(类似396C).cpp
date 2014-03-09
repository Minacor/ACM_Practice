/*
 * 题意：
 * 第一行两个数:树的节点数n和询问数m
 * 第二行n个数，表示树上第i个结点的权值，结点从1开始标号
 * 接下来n-1行表示结点a和b之间有边连接
 * 接下来m行询问
 * 1 pos v ：把pos结点加上v，它的孩子-v，孩子的孩子又+v，如此类推直到叶子
 * 2 pos ：输出pos结点的值
 *
 * 思路：
 * 类似396C，树状数组模拟差分数列+树结构转线性结构
 * dfs转型的时候同时更新lv,lv[i]=0表示结点是奇数层的，1表示是偶数层的
 * 两个树状数组，第一个维护的是子树+v的值，第二个是子树-v的值
 * 第一棵树代表奇数层，第二棵树代表偶数层，同样性质的层操作一定是相同的(同加同减)，不同性质的层操作一定不同
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
const int MAX = 200000+10;
const int inf = 522133279;
const int mod = 1000000007;

int n,m;
int num[MAX];
int index,tot;
int lv[MAX],st[MAX],ed[MAX];
int vis[MAX];
int head[MAX];
int tree[2][MAX];

struct edge
{
    int now;
    int next;
}e[MAX];

void add(int x,int y)
{
    e[tot].now=y;
    e[tot].next = head[x];
    head[x]=tot++;
}

void dfs(int cur,int deep)
{
    vis[cur]=1;
    st[cur] = ++index;
    lv[cur] = deep;
    for(int i = head[cur] ; i+1 ; i = e[i].next)
    {
        int next=e[i].now;
        if(!vis[next])
            dfs(next,1-deep);
    }
    ed[cur] = index;
}

void modify(int id , int pos , int delta)
{
    for( ; pos <= n; pos+=lowbit(pos))
        tree[id][pos] += delta;
}

int getsum(int id , int pos)
{
    int t=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        t += tree[id][pos];
    return t;
}

int main()
{
    //FR;
    clr(head,-1);
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; i++)
        scanf("%d",num+i);

    for(int i = 1 ; i < n ; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    dfs(1,0);

    while(m--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            int pos,v;
            scanf("%d%d",&pos,&v);
            modify(lv[pos],st[pos],v);
            modify(lv[pos],ed[pos]+1,-v);
            modify(1-lv[pos],st[pos],-v);       //另一颗树是完全相反的操作
            modify(1-lv[pos],ed[pos]+1,v);
        }
        else
        {
            int pos;
            scanf("%d",&pos);
            printf("%d\n",getsum(lv[pos],st[pos])+num[pos]);    //询问的时候，只需询问代表自己层性质的那一棵树就行了
        }
    }
    return 0;
}
