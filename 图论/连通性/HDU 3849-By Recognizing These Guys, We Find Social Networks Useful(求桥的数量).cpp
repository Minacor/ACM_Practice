/*
 * 题意：
 * 给一张关系网，关系网是无向图，把其中的桥命名为:关键关系
 * 问给定的网络中有多少关键关系
 *
 * 注意：图可能不连通，这时要输出0，输出是输出输入时给定的边，且相对位置不能发生改变
 *
 * 思路:
 * 无向图求桥的数量；裸题，且本题没有重边
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

int t;
int id,cnt;
int n,m;

map<string , int> stn;
map<int , string> nts;
vector<int> out;

struct edge
{
    int s;
    int t;
    int next;
    int id;
}e[100000*2+100];

int head[10010],low[10010],dfn[10010],clo;

void add(int s , int t , int id)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].next = head[s];
    e[cnt].id=id;
    head[s] = cnt++;

    e[cnt].s=t;
    e[cnt].t=s;
    e[cnt].next = head[t];
    e[cnt].id=id;
    head[t] = cnt++;
}

void tarjin(int cur , int fa)
{
    dfn[cur] = low[cur] = ++clo;

    for(int i= head[cur] ; i+1 ; i = e[i].next)
    {
        int next = e[i].t;
        if(!dfn[next])
        {
            tarjin(next,cur);
            low[cur] = min(low[cur],low[next]);

            if(dfn[cur] < low[next])
                out.push_back((e[i].id-1)*2);
        }
        else if(fa != next)
            low[cur] = min(dfn[next],low[cur]);
    }
}

void init()
{
    clr(dfn,0);
    clr(low,0);
    cnt=0;
    id=0;
    clo=0;
    clr(head,-1);
    stn.clear();
    nts.clear();
    out.clear();
}

int main()
{
    cin >> t;
    while(t--)
    {
        init();
        cin >> n >> m;
        for(int i = 1 ; i <= m ; i++)
        {
            string ss,tt;
            cin >> ss >> tt;
            if(!stn[ss])
            {
                stn[ss]=++id;
                nts[id]=ss;
            }
            if(!stn[tt])
            {
                stn[tt]=++id;
                nts[id]=tt;
            }
            add(stn[ss],stn[tt],i);
        }
        tarjin(1,-1);

        int cnt=0;
        for(int i = 1 ; i <= n ; i++)
            cnt += (dfn[i]!=0);

        if(cnt != n)
        {
            cout << 0 << endl;
            continue;
        }

        sort(out.begin(),out.end());
        cout << out.size() << endl;
        for(int i = 0 ; i < out.size() ; i++)
            cout << nts[e[out[i]].s] << ' ' << nts[e[out[i]].t]<< endl;
    }
    return 0;
}
