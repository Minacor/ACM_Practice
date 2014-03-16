/*
 * ���⣺
 * ��������n��m��k
 * ���ڷ�������n�ֲ�����m�ֵ�����k��ת����
 * �������Լ��Ĳ�ͷ����ͬ�Ĳ�ͷ�Ͳ����������
 * ת�����������ַ���ʾ��A B ��ʾA���͵Ĳ�ͷ�ܹ�ת����B���͵Ĳ�ͷ
 * ת��������ʹ��
 * �����ٵĲ��ܹ���ĵ���
 *
 * ˼·��
 * �������ͼ����������Դ��src�ͳ������tar
 * �����ı����1~m
 * ��ͷ�Ͳ�����Ϊһ���ţ���������:��һ��mapȥ��¼���в�ͬ����Ĳ�ͷ�Ͳ��������δ�m+1��ʼ���
 * ��������ͷ�Ͳ�������������x
 * ��tar = x+m+1 �� src = 0
 * Ȼ�󽨱ߣ�
 * src��������������1~m����ȨֵΪ1�ı� ����ʾ����ֻ��ѡһ����ͷ����
 * �����������ܹ�ƥ�䵽�Ĳ����Ͳ�ͷ(����ͳ��Ϊ��ͷ)��Ž��ߣ�ȨֵΪ1����ʾһ���������ֻ�ܲ嵽һ����ͷ��
 * ��ͷ - ��ͷ֮�䣬�����ת���������ģ�����A B �� ��ôA��B���ߣ�ȨֵΪinf����ʾ�ж���A���ܹ��õ�����B
 * ��ͷ - tar֮�佨�ߣ�ȨֵΪ1����ʾ�����һ����ͷѡ������һ������
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
