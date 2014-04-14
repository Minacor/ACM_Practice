/*
 * ���⣺
 * ����һЩ�˵�ͶƱ����ʾ��ϲ����Щ�ˡ������������ļ���������ж����ˡ�
 * Ҫ�󣺶��ڼ������ÿ���ˣ�1:������Ͷ��Ʊ��2:��ϲ�����˱����ڼ����3:����������ϲ����
 *
 * ˼·��
 * ����Ҫ����������ͼ�����÷�ͼ����Ч���ر��,���ҵڶ��ֱ���÷�ͼ��󷽱��˴���
 * ����������������Ϊ0���˱��Ϊ������(ɾ��)����ζ��û��ϲ��������ɾ��һЩ���Ժ�û��ϲ������
 * Ȼ��dfs����ͼ���ѳ���Ϊ0���˱�ǣ���ζ����û��ͶƱ
 * Ҳͬʱ��Ͷ����Щ�˵��˱�ǵ�����Ϊ��ϲ�����˲������ڼ������ˣ�����Щ�˼�ΪA
 * Ȼ���ٰ�Ͷ��A���˸ɵ����Դ�����
 * ʣ�����Ĺ���������ʣ����ͼ��Ѱ�������ͨ���ˣ��ҵ�������ͼ������ͨ����
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
const int MAXN = 10000+10;
const int inf = 522133279;
const int mod = 1000000007;

vector<int> g[MAXN],rg[MAXN];
int del[MAXN];
int in[MAXN],out[MAXN];
int n,m;

void init()
{
    clr(in,0);
    clr(out,0);
    clr(del,0);
    for(int i = 0 ; i <= n ; i++)
        g[i].clear(),rg[i].clear();
}

void topo()
{
    queue<int> que;

    for(int i = 1 ; i <= n ; i++)
        if(!in[i])
            que.push(i),del[i]=1;

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();

        for(int i = 0 ; i < g[cur].size() ; i++)
            if(--in[g[cur][i]] == 0)
            {
                que.push(g[cur][i]);
                del[g[cur][i]]=1;
            }
    }
}

void dfs(int cur)
{
    del[cur]=1;

    for(int i = 0 ; i < rg[cur].size() ; i++)
        if(!del[rg[cur][i]])
            dfs(rg[cur][i]);
}

int num=0;
int vis[MAXN];
void find_max(int cur)
{
    if(del[cur])
        return ;
    num++;
    del[cur]=1;

    for(int i = 0 ; i < g[cur].size() ; i++)      //ע��������ͼ�������ҵĲ���ǿ��ͨ��������ͨ,�������˺�̻�����ǰ����
        if(!del[g[cur][i]])
           find_max(g[cur][i]);

    for(int i = 0 ; i < rg[cur].size() ; i++)
        if(!del[rg[cur][i]])
           find_max(rg[cur][i]);
}

int main()
{
    //FR;
    int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i = 0 ; i < m ; i++)
        {
            int from,to,num;
            scanf("%d%d",&from,&num);

            while(num--)
            {
                scanf("%d",&to);
                g[from].push_back(to);
                rg[to].push_back(from);
                in[to]++,out[from]++;
            }
        }
        topo();

        for(int i = 1 ; i <= n ; i++)
            if(out[i] == 0)
                dfs(i);

        int ans=-1;
        for(int i = 1 ; i <= n ; i++)
        {
            num=0;
            find_max(i);
            ans = max(ans,num);
        }
        printf("%d\n",ans);
    }
    return 0;
}

