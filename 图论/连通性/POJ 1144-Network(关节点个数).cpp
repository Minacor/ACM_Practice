/*
 * 题意：
 * 第一行结点个数n
 * 接下来若干行表示第一个数为编号的结点和接下来的几个编号间有边相连，以0行结束
 *
 * 思路：
 * 求关节点个数裸题
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
#define mkp make_pair
using namespace std;
typedef long long LL;
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int n;

struct edge
{
    int s;
    int t;
    int next;
}e[110*110*2];

int head[110],cnt;
int subnet[110];
int vis[110];

int low[110],dfn[110],clo;

void add(int s,int t)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].next=head[s];
    head[s] = cnt++;

    e[cnt].s=t;
    e[cnt].t=s;
    e[cnt].next=head[t];
    head[t] = cnt++;
}

void init()
{
    clr(head,-1);
    clr(vis,0);
    cnt=0,clo=0;
    clr(low,0);
    clr(dfn,0);
    clr(subnet,0);
    subnet[1]=-1;
}
void tarjin(int cur)
{
    dfn[cur] = low[cur] = ++clo;
    vis[cur] = 1;

    for(int i = head[cur] ; i+1 ; i=e[i].next)
    {
        int next = e[i].t;
        if(!vis[next])
        {
            tarjin(next);
            low[cur] = min(low[next],low[cur]);
            if(low[next] >= dfn[cur])
                subnet[cur]++;
        }
        else low[cur] = min(dfn[next],low[cur]);
    }

}

int main()
{
    string line;
    while(cin >> n && n)
    {
        cin.ignore();
        init();
        while(getline(cin,line) && line != "0")
        {
            int st;
            istringstream iss(line);
            iss >> st;
            int tmp;
            while(iss >> tmp)
                add(st,tmp);
        }
        tarjin(1);

        int cnt=0;
        for(int i = 1 ; i <= n ; i++)
            cnt += (subnet[i]>0);
        cout << cnt << endl;
    }
    return 0;
}
