/*
 * ���⣺
 * ��һ�Ŷ����(������Ϊn������Ϊn-1������ͼ)��һ����������ʾ���ڵĵ��Ȩֵ
 * ȨֵΪ1��ʾ�����߲�������2��ʾҪ����
 * ���ڴ�1�ڵ㿪ʼͨ������㣬�������һ����֮ǰ����Ҫ����ıߣ��Ͱ��������һ������
 * �����С����
 *
 * ˼·��
 * ���1-i��i-n֮������Ҫ�޵�·��ѹ�����n������i���������̰��
 * һ����֮�����û����Ҫ�����·��������������һ�����·ǡ����Ҫ������ô�����һ����Ҫ���뼯�ϵ�
 *
 * ����������ȷ�������ĵ㣺
 * �������ǻ��ݣ���һ��res += dfs()��¼�������ı�״̬��dfs�������������û�нڵ����û����Ҫ�����·���ͷ���0��
 * �������resΪ0�Ļ���˵������������·����û����Ҫ�޵ı� �� ��ͬʱȨֵw == 2�Ļ��������ͱ�������
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

int dfs(int cur,int prew)   //prewǰһ��·��״̬
{
    int ok=0;
    vis[cur]=1;
    for(int i = head[cur] ;i+1 ;i = e[i].next)
    {
       int next = e[i].now;
       if(!vis[next])
            ok += dfs(next,e[i].state);
    }

    if(!ok && prew == 2)    //����(��curΪ���ڵ������)û��Ҫ�޵�·(!ok)����ǰһ��ǡ����Ҫ����
    {
        out.push_back(cur);
        return 1;
    }
    return ok;      //Ҫ��������Ҫ�޵�·��Ҫ��ǰ��һ������Ҫ�޵�·�����ߺ���û��Ҫ�޵�·����ǰ��һ������Ҫ�ޣ������������Ҹ�С��
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
