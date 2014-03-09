/*
 * 题意：
 * 第一行三个数n(细菌总数,从1~n编号),m(转移种数),k(菌落数)
 * 第二行k个数 表示第i个菌落有c[i]个细菌
 * 接下来m行描述转移的费用，指第u个细菌和第v个细菌之间转移需要花费w
 * 如果同菌落间的任意两个细菌转移费用都是0的话，输出Yes并输出菌落间转移的最小花费
 * 如果有某两个同菌落细菌转移花费不是0的话就仅输出No
 *
 * 思路：
 * 一个集合表示集合内的元素之间的转移花费都是0，用并查集搞定
 * 找最小花费的话就是500^3的floyd
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
const int MAX = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int n,m,k;
int c[510];
int f[MAX];
int pos[MAX],p;
int g[510][510];

int find(int x)
{
    return x!=f[x] ? f[x]=find(f[x]) : x;
}

void merger(int x , int y)
{
    x = find(x);
    y = find(y);

    if(x!=y)
        f[y]=x;
}

int main()
{
    cin >> n >> m >> k;
    clr(g,0x1f);

    for(int i = 1 ; i <= n ; i++) f[i]=i;
    for(int i = 1 ;i <= k ; i++)
    {
        cin >> c[i];
        for(int j = 0 ; j < c[i] ; j++)
            pos[++p] = i;
    }

    for(int i = 0 ; i < m ; i++)
    {
        int x,y,v;
        cin >> x >> y >> v;

        if(!v) merger(x,y);
        g[pos[x]][pos[y]]=g[pos[y]][pos[x]]=min(v,g[pos[x]][pos[y]]);
    }

    int ok=1;
    for(int i = 2 ; i <= n ; i++)
        if(pos[i]==pos[i-1]&&find(i)!=find(i-1))
        {
            ok=0;
            break;
        }
    if(!ok) cout << "No" << endl;
    else
    {
        for(int mid=1 ; mid <= k ; mid++)
            for(int i = 1 ; i <= k ; i++)
                if(g[mid][i] < inf)
                    for(int j = 1 ; j <= k ; j++)
                        if(i!=j && g[i][j] > g[i][mid]+g[mid][j])
                            g[i][j]=g[i][mid]+g[mid][j];
        cout << "Yes" << endl;
        for(int i = 1 ; i <= k ; i++)
        {
            g[i][i]=0;
            for(int j = 1 ; j <= k ; j++)
                cout << (g[i][j]==inf?-1:g[i][j]) << ' ';
            cout << endl;
        }
    }
    return 0;
}
