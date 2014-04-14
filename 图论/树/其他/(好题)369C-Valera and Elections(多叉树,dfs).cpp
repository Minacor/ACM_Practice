/*
 * 题意：
 * 给一颗多叉树(顶点数为n，边数为n-1的无向图)，一行三个数表示相邻的点和权值
 * 权值为1表示这条边不用修理，2表示要修理
 * 现在从1节点开始通向各个点，如果到达一个点之前有需要修理的边，就把这个点归进一个集合
 * 输出最小集合
 *
 * 思路：
 * 如果1-i，i-n之间有需要修的路，压入的是n而不是i，最基本的贪心
 * 一个点之后如果没有需要修理的路，并且这个点和上一个点的路恰好需要修理，那么这个点一定是要加入集合的
 *
 * 问题就是如何确定这样的点：
 * 方法就是回溯，用一个res += dfs()记录接下来的边状态，dfs函数：如果后续没有节点或者没有需要修理的路，就返回0，
 * 这样如果res为0的话，说明回溯上来的路径中没有需要修的边 ， 若同时权值w == 2的话，这个点就被加入了
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

struct edge
{
    int now;
    int next;
    int state;
}e[200000+100];

int head[100000+100],vis[100000+100];
int edgenum=0;

void add(int x , int y , int v)
{
    e[edgenum].now=y;
    e[edgenum].next = head[x];
    e[edgenum].state = v;
    head[x] = edgenum++;
}

vector<int> out;

int dfs(int cur,int prew)   //prew前一条路的状态
{
    int ok=0;
    vis[cur]=1;
    for(int i = head[cur] ;i+1 ;i = e[i].next)
    {
       int next = e[i].now;
       if(!vis[next])
            ok += dfs(next,e[i].state);
    }

    if(!ok && prew == 2)    //后续(以cur为根节点的子树)没有要修的路(!ok)，且前一条恰好需要修理
    {
        out.push_back(cur);
        return 1;
    }
    return ok;      //要不后续有要修的路，要不前面一条不是要修的路，或者后续没有要修的路但是前面一条不需要修，还可以向上找更小的
}

int main()
{
    clr(head,-1);
    int n;
    cin >> n;
    for(int i = 0 ; i < n-1 ; i++)
    {
        int a,b,v;
        cin >>a>>b>>v;
        add(a,b,v);
        add(b,a,v);
    }

    dfs(1,1);

    cout << out.size() << endl;
    for(int i = 0 ; i < out.size() ; i++)
        cout << out[i] << ' ';
    return 0;
}
