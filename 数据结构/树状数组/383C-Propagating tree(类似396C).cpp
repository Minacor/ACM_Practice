/*
 * ���⣺
 * ��һ��������:���Ľڵ���n��ѯ����m
 * �ڶ���n��������ʾ���ϵ�i������Ȩֵ������1��ʼ���
 * ������n-1�б�ʾ���a��b֮���б�����
 * ������m��ѯ��
 * 1 pos v ����pos������v�����ĺ���-v�����ӵĺ�����+v���������ֱ��Ҷ��
 * 2 pos �����pos����ֵ
 *
 * ˼·��
 * ����396C����״����ģ��������+���ṹת���Խṹ
 * dfsת�͵�ʱ��ͬʱ����lv,lv[i]=0��ʾ�����������ģ�1��ʾ��ż�����
 * ������״���飬��һ��ά����������+v��ֵ���ڶ���������-v��ֵ
 * ��һ�������������㣬�ڶ���������ż���㣬ͬ�����ʵĲ����һ������ͬ��(ͬ��ͬ��)����ͬ���ʵĲ����һ����ͬ
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
            modify(1-lv[pos],st[pos],-v);       //��һ��������ȫ�෴�Ĳ���
            modify(1-lv[pos],ed[pos]+1,v);
        }
        else
        {
            int pos;
            scanf("%d",&pos);
            printf("%d\n",getsum(lv[pos],st[pos])+num[pos]);    //ѯ�ʵ�ʱ��ֻ��ѯ�ʴ����Լ������ʵ���һ����������
        }
    }
    return 0;
}
