/*
 * http://blog.csdn.net/zhang20072844/article/details/6703432
 * 
 * 题意：
 * 给你一颗苹果树，树的主干设为1，每一个分支设为一个数，一直到N，代表这颗苹果树。
 * 每个分支(结点)上面只能最多有一个苹果，也就是一个结点上面不可能有两个苹果
 * 另外注意一点，不要把苹果树想象成二叉树，苹果树每个节点可以分出很多叉，应该是多叉树。
 * 输入是结点之间的关系，a b表示a结点和b结点之间有树枝连接
 *
 * 下面是两种操作，Q 和C
 * C  j  的意思是如果 j 这个结点上面有苹果就摘下来(-1)，如果没有，那么就会长出新的一个(+1)
 * Q  j  就是问 以j为根结点的子树上的苹果总数并输出。
 * 树上刚开始每个结点长满了苹果
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
const int MAX = 100000+100;
const int inf = 522133279;

struct egde
{
    int now;
    int next;
}e[MAX];

int head[MAX];
int line[MAX];              //line[i] : 如果编号为i的结点上有苹果就是1，否则为0
int st[MAX],ed[MAX];        //st[i]~ed[i]表示以i为根节点的一颗子树
int vis[MAX];       //结点有没有被访问过
int index,cnt;      //index时间戳，cnt记录边数
int tree[MAX];
int n;

void dfs(int cur)           //树结构变成线性结构，时间戳是对访问次序的编号
{
    vis[cur]=1;
    st[cur]=ed[cur]= ++index;
    for(int i = head[cur] ; i != -1 ; i = e[i].next)
    {
        int next = e[i].now;
        if(!vis[next])
            dfs(next);
    }
    ed[cur]=index;
}

int getsum(int pos)
{
    int t=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        t += tree[pos];
    return t;
}

void modify(int pos ,int delta)
{
    for( ; pos <= n ; pos += lowbit(pos))
        tree[pos] += delta;
}

void add(int x,int y)
{
    e[cnt].now=y;
    e[cnt].next = head[x];
    head[x] = cnt++;
}

void init()
{
    getchar();
    index=0;
    cnt=0;
    fill(line,line+n+1,1);      //初始的时候树上是长满苹果的
    clr(st,0);
    clr(ed,0);
    clr(tree,0);
    clr(vis,0);
    clr(head,-1);
    for(int i = 1 ; i <= n ; i++)
        modify(i,1);
}

int main()
{
    //FR;
    while(~scanf("%d",&n))
    {
        init();
        for(int i = 0 ; i < n-1 ; i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            getchar();
            add(a,b);
        }
        dfs(1);

        int q;
        scanf("%d",&q);
        getchar();
        while(q--)
        {
            char com;
            int num;
            scanf("%c %d",&com,&num);
            getchar();
            if(com == 'Q')
                printf("%d\n",getsum(ed[num])-getsum(st[num]-1));   //获得st[num]这颗子树上所有元素的和
            else
            {
                if(line[st[num]])           //有苹果就摘苹果，没苹果就长苹果
                    modify(st[num],-1);
                else
                    modify(st[num],1);
                line[st[num]] = !line[st[num]];
            }
        }
    }

    return 0;
}

