/*
 * �����㷨��©����poj���ݲ���������Ҳ��AC����������ò�㷨
 *
 * ���⣺
 * ��һ��p,n ��ʾһ̨��������һ����p������������������n�ֻ����Ĺ���״��
 * ÿ�п�ͷһ��������ʾ��λʱ�����ܹ�������Qį���Բ�������һ������
 * ������p��������ʾ��̨��������������(���������Ϊ����״̬��)������
 * ��i(1<=i<=p)λ��0��ʾ��ǰ�������ĵ��Բ���������������������ܼ����ӹ�
 * 1��ʾ��ǰ�������ĵ��Ա���������������������ܼ����ӹ�
 * 2��ʾ��û�ж�����ν
 * ����������p��������ʾ����̨�����ӹ��Ժ󣬵���ӵ�в�����״��(���������Ϊ���������)
 * 0��ʾ�ӹ�������û�в���i��1��ʾ�����������i
 * ������ľ��ǵ�λʱ�����ܹ���������ĵ���̨������Ƕ���̨
 *
 * ˼·��
 * ��ͼ������һ������Դ��src��һ���������tar
 * ����һ̨���Ի�û��ʼ���죬��������һ����0��Ȼ��
 * ���һ̨�����Ĺ���״̬��ȫ��0��˵�������ĵ��Բ������κβ�����������ܹ���
 * ����Щ����S���ǰ�������ˮ����ǰ�˵Ļ�����������src->S��ȨֵΪ��Щ������Qi
 * ���һ̨�����Ĺ��������ȫ��1��˵�������Ѿ�����������ˣ���Щ��������ˮ�ߵ�ĩ�ˣ������߼�SS->tar,ȨֵQi
 * �м�Ļ����������i�Ĺ���������ͻ���j����ͻ����ô����i�ӹ��ĵ��Ծ��ܴ���j������i->j��ȨֵΪmin(Qi,Qj)
 * ��ν����ͻ��ָ����i�Ĺ��������������ĳ����i����iλΪ1����j�Ĺ���״̬����iλ��0����˵������ͻ��������0��1��������״̬
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
#define mkp make_pair
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 100+100+2*100+100;
const int inf = 522133279;
const int mod = 1000000007;

int n,p;
int g[110][110];
int lv[110];
int src,tar;

struct node
{
	int in[15];
	int out[15];
	int v;
}lis[100];

struct edge
{
	int s;
	int t;
	int next;
	int c;
}e[110*110*2];
int cnt;
int head[110];

void add(int s , int t , int c)
{
	e[cnt].s=s;
	e[cnt].t=t;
	e[cnt].c=c;
	e[cnt].next = head[s];
	head[s] = cnt++;

	e[cnt].s=t;
	e[cnt].t=s;
	e[cnt].c=0;
	e[cnt].next= head[t];
	head[t]= cnt++;
}

bool bfs()
{
	memset(lv,0,sizeof lv);
	queue<int> que;
	que.push(src);
	lv[src]=1;

	while(!que.empty())
	{
		int cur = que.front();
		que.pop();

		for(int i = head[cur] ; i+1 ; i=e[i].next)
		{
			if(lv[e[i].t]==0 && e[i].c > 0)
			{
				lv[e[i].t] = lv[e[i].s]+1;
				if(e[i].t == tar) return 1;
				que.push(e[i].t);
			}
		}
	}
	return 0;
}

map< pair<int,int> , int > out;

int dfs(int cur , int totflow)
{
	int ret=0;
	if(!totflow || cur == tar)
		return totflow;

	for(int i = head[cur] ; i+1 ; i=e[i].next)
	{
		if(totflow==0) break;
		if(e[i].c > 0 && lv[e[i].t] == lv[cur]+1)
		{
			int f = dfs(e[i].t , min(totflow,e[i].c));
			ret += f;
			totflow -= f;
			e[i].c -= f;
			e[i^1].c += f;
			if(cur!=src&&cur!=tar&&e[i].t!=tar&&e[i].t!=src&&f)
                out[mkp(cur,e[i].t)] += f;
		}
	}
	return ret;
}

int dinic()
{
	int ret=0;
	while(bfs())
	{
		//cout << 1111 << endl;
		int tmp = dfs(src,522133279);
		if(tmp == 0) break;
		ret += tmp;
	}
	return ret;
}

int main()
{
	while(~scanf("%d%d",&p,&n))
	{
		src=0,tar=n+1;
		cnt=0;
		memset(head,-1,sizeof head);
		for(int i = 1 ; i <= n ; i++)
		{
			scanf("%d",&lis[i].v);
			int ok = 1;
			for(int j = 1 ; j <= p ; j++)
			{
				scanf("%d",&lis[i].in[j]);
				if(lis[i].in[j]==1) ok=0;
			}

			if(ok==1) add(src,i,lis[i].v);
			ok=1;
			for(int j = 1 ; j <= p  ; j++)
			{
				scanf("%d",&lis[i].out[j]);
				if(lis[i].out[j]==0) ok=0;
			}
			if(ok) add(i,tar,lis[i].v);
		}

		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= n ; j++)
			{
				if(i==j)continue;
				int ok=1;
				for(int k = 1 ; k <= p ; k++)
					if(lis[i].in[k]+lis[j].out[k] == 1)
					{
						ok=0;
						break;
					}
				if(ok)
					add(j,i,min(lis[i].v,lis[j].v));
			}

		cout << dinic() << ' ';
		cout << out.size() << endl;
		map< pair<int,int> , int > ::iterator it = out.begin();
		for( ; it != out.end() ; it++)
            cout << (it->first).first << ' ' << (it->first).second << ' ' << it->second << endl;
        out.clear();
	}

	return 0;
}
