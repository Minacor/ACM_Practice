/*
 * 题意：
 * 给三个数n，m，k
 * 现在房间里有n种插座，m种电器，k中转换器
 * 电器有自己的插头，相同的插头和插座才能配对
 * 转换器由两个字符表示：A B 表示A类型的插头能够转化成B类型的插头
 * 转换器无限使用
 * 求最少的不能供电的电器
 *
 * 思路：
 * 最大流建图，设立超级源点src和超级汇点tar
 * 电器的标号是1~m
 * 插头和插座归为一类标号，计数方法:用一个map去记录所有不同种类的插头和插座，依次从m+1开始编号
 * 假设最后插头和插座的种类数是x
 * 则tar = x+m+1 ， src = 0
 * 然后建边：
 * src到各个电器，即1~m建立权值为1的边 ，表示最终只能选一个插头来插
 * 各个电器到能够匹配到的插座和插头(以下统称为插头)编号建边，权值为1，表示一个电器最多只能插到一个插头上
 * 插头 - 插头之间，如果有转换器相连的，比如A B ， 那么A，B建边，权值为inf，表示有多少A就能够得到多少B
 * 插头 - tar之间建边，权值为1，表示最后这一个插头选中至多一个电器
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

int n,m,k;
struct edge
{
    int s;
    int t;
    int next;
    int c;
}e[110*110*110];

int lv[3*110];
int src,tar;
int head[3*110];
int cnt;
map<string , int> lis;

void add(int s , int t , int v)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].next = head[s];
    e[cnt].c=v;
    head[s] = cnt++;

    e[cnt].s=t;
    e[cnt].t=s;
    e[cnt].next = head[t];
    e[cnt].c=0;
    head[t]=cnt++;
}

bool bfs()
{
    queue<int> que;
    clr(lv,0);
    lv[src]=1;
    que.push(src);

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();

        for(int i = head[cur] ; i+1 ; i = e[i].next)
        {
            if(lv[e[i].t]==0 && e[i].c > 0)
            {
                lv[e[i].t] = lv[cur]+1;
                if(tar == e[i].t) return 1;
                que.push(e[i].t);
            }
        }
    }
    return 0;
}

int dfs(int cur , int totflow)
{
    int ret = 0;
    if(cur == tar || totflow == 0)
        return totflow;

    for(int i = head[cur] ; i+1 ; i = e[i].next)
    {
        if(totflow == 0) break;
        if(lv[e[i].t] == lv[cur]+1 && e[i].c > 0)
        {
            int f = dfs(e[i].t , min(totflow,e[i].c));
            totflow -= f;
            e[i].c -= f;
            e[i^1].c += f;
            ret += f;
        }
    }
    return ret;
}

int dinic()
{
    int ret=0;
    while(bfs())
    {
        int tmp = dfs(src,inf);
        if(tmp == 0)
            break;
        ret+=tmp;
    }
    return ret;
}

string chazuo[110],dianqi[110],adapter[110][2];

int main()
{
    clr(head,-1);
    cin >> n;
    int tot=0;
    for(int i = 1 ; i <= n ; i++)
        cin >> chazuo[i] , lis[chazuo[i]] = ++tot;
    cin >> m;
    string line;
    for(int j = 1 ; j <= m ; j++)
    {
        cin >> line >> dianqi[j];
        if(lis[dianqi[j]] == 0) lis[dianqi[j]] = ++tot;
        add(j , m+lis[dianqi[j]] , 1);
        add(0,j,1);
    }

    cin >> k;
    for(int i = 1 ; i <= k ; i++)
    {
        cin >> adapter[i][0] >> adapter[i][1];
        if(!lis[adapter[i][0]])
            lis[adapter[i][0]] = ++tot;
        if(!lis[adapter[i][1]])
            lis[adapter[i][1]] = ++tot;
        add(m+lis[adapter[i][0]] , m+lis[adapter[i][1]] , inf);
    }

    src = 0 ; tar = m+lis.size()+1;

    for(int i = 1 ; i <= n ; i++)
        add(m+lis[chazuo[i]],tar,1);
    cout << m-dinic() << endl;
    return 0;
}
