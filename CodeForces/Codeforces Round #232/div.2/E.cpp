/*
 * ���⣺
 * �������ݣ�
 * ��һ��һ����n:��ʾ��һ�ø��ڵ�id=1�ĸ��������������нڵ�ĳ�ʼֵΪ0
 * �ڶ���n-1����p2,p3...pn��pi��ʾ��i����ʾid=i�Ľڵ�ĸ��ڵ���pi
 * ������һ����m:��ʾ��m��ѯ�ʣ�������m��ѯ��
 * ѯ�������ַ�ʽ��
 * 1) 1 pos x k������id=pos�ĵ�ľ���Ϊi(i>=0,0��ʾpos����)���ӽڵ��ֵ����x-i*k
 *               ����ָ��������֮��ߵ�����
 * 2) 2 pos : ���id=pos�ĵ�ĵ�ǰֵ
 *
 * ˼·��
 * ��״�ṹת����dfsת��Ϊ���Խṹ��st[pos]~ed[pos]��ʾ��posΪ���ڵ��������ͬʱ����lv[pos]��¼pos�����ڵ�ľ���(�����)
 * ��״����ģ�������м���������������״���飬getsumȡ�õľ��ǵ�ǰid=pos�ĵ��ֵ
 *
 * ������������΢�����һ�㣬Ҳ�Ǳ������
 * ������״����ά������һ��ʹ��st[pos]~ed[pos]��������ϵĽڵ��ֵȫ������x+lv[pos]*k
 * �ڶ�����״����ʹ�������ϵĽڵ��ֵȫ������k
 * ��ôÿһ��ѯ�ʣ�curpos����ʵֵ����getsum(first_tree,curpos)-lv[curpos]*getsum(second_tree,curpos)
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
const int MAX = 300000+100;
const int inf = 522133279;
const int mod = 1000000007;

LL tree[2][MAX];
LL lv[MAX];

struct edge
{
    LL now;
    LL next;
}e[MAX];

LL head[MAX];
LL vis[MAX];
LL index,cnt;
LL n;
LL st[MAX] , ed[MAX];

LL getsum(LL id , LL pos)
{
    LL ans=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        ans = (ans+tree[id][pos])%mod;
    return ans;
}

void modify(LL id , LL pos , LL delta)
{
    for( ; pos <= n ; pos += lowbit(pos))
        tree[id][pos] = (tree[id][pos]+delta)%mod;

}

void dfs(LL cur,LL deep)
{
    vis[cur]=1;
    st[cur]=ed[cur]=++index;
    lv[cur]=deep;
    for(LL i = head[cur] ; i+1 ; i=e[i].next)
    {
        LL next = e[i].now;
        if(!vis[next])
            dfs(next,deep+1);
    }
    ed[cur]=index;
}

void add(LL x , LL y)
{
    e[cnt].now = y;
    e[cnt].next = head[x];
    head[x] = cnt++;
}

void init()
{
    clr(head,-1);
}

int main()
{
    cin >> n;
    init();
    for(int i = 2 ; i <= n ; i++)
    {
        LL a;
        cin >> a;
        add(a,i);
    }
    dfs(1,1);
    int m;
    cin >> m;
    while(m--)
    {
        int op;
        cin >> op;

        if(op==1)
        {
            LL a,x,k;
            cin >> a >> x >> k;
            modify(0,st[a],(x+k*lv[a])%mod);
            modify(0,ed[a]+1,-(x+k*lv[a])%mod);
            modify(1,st[a],k);
            modify(1,ed[a]+1,-k);
        }
        else
        {
            LL pos;
            cin >> pos;
            //ע�������֮����ܸ�ֵ��С������+һ��mod����
            cout << ((getsum(0,st[pos])-lv[pos]*getsum(1,st[pos])+mod)%mod+mod)%mod << endl;
        }
    }

    return 0;
}


