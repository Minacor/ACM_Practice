/*
 * ���⣺
 * ����һ��������ͨͼ��Ҫ������ͼ�ָ�����ɸ�����Ϊ2��·��
 *
 * ˼·��
 * ���ȣ�������ͼ���������ߵ�һ�������ԣ�ż�����ߵ�һ������
 *
 * ����dfs(v)����δ�����ʵ���Щ�ߣ����ܹ�������Щ�����������ߵĶ���v
 * ������ӵı��������ģ���ô����������ƥ�伯���е������,����(u,v)
 * ��������ͻ᷵��u����ʾ�����������(u,v)���Ÿ������ƥ��
 *
 * ����dfs(v)�Ĺ���������
 * �ҵ��ڽӵ�ǰ���������δ�����ʹ��ıߣ�����Щ��ѹ��adjacent����,����Ƿ���
 * �Լ���adjacent�е�ÿ������u,����dfs(u)
 * ����dfs(u)����һ������w����ô˵�����ǿ��Բ��(v u w)����·��
 * �������0����Ҫ��u���������뵽unpair������
 * ��Ȼ(v,u)Ŀǰ�����κ�·���У����ǿ���ƥ��unpair��v���ɵı߼��е�����������
 * ��ʱ��·�����Ǽ�������������u,w��v���ɵ�·��(u,v,w)
 * ����������unpair��ʣ��һ�����㣬��ô��������ͷ���������㣬���򷵻�0
 *
 * �²�Ĳ��ԣ�
 * ̰�ģ��ܹ��ҵ�(1��2��3)�����ľ����
 * ʣ�಻�ܵģ������ʣ��(1��4)û�������� �Ͱ�4ѹ��������
 * ���ݵ���������ʱ�򣬾�Ҫ��4������ȸ�ƥ���ˣ�����ܿ��ܳ���(1��4)�����������
 * ��ʣ�����û��ƥ��ģ���Ȼ��Ҫ�Ȼ���ƥ����(1��2��3 ���Ƶ�С���������)����Ϊdfs��ǰ�Ķ�����п���Ҫ"�չ�"����ֱ�������������
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

struct edge
{
    int s;
    int t;
    int next;
    int vis;
}e[100100*2];

int n,m;
int cnt,head[100100];
int color[100100];

void add(int s , int t)
{
    e[cnt].s=s;
    e[cnt].t=t;
    e[cnt].next=head[s];
    e[cnt].vis=0;
    head[s] = cnt++;
}

int dfs(int cur)
{
    queue<int> adjacent;
    for(int i = head[cur] ; ~i ; i=e[i].next)
    {
        if(!e[i].vis)
        {
            adjacent.push(e[i].t);
            e[i].vis = e[i^1].vis = 1;
        }
    }

    queue<int> unpair;

    while(!adjacent.empty())
    {
        int u = adjacent.front();
        adjacent.pop();

        int w = dfs(u);

        if(w == 0)
            unpair.push(u);
        else
            printf("%d %d %d\n" , cur,u,w);
    }

    while(unpair.size() >= 2)
    {
        int u = unpair.front();
        unpair.pop();
        int v = unpair.front();
        unpair.pop();
        printf("%d %d %d\n",u,cur,v);
    }

    if(unpair.size())
        return unpair.front();
    return 0;
}

int main()
{
    scanf("%d%d",&n,&m);
    clr(head,-1);
    for(int i = 0 ; i < m ; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }

    if(m%2)
        puts("No solution");
    else
        dfs(1);

    return 0;
}
