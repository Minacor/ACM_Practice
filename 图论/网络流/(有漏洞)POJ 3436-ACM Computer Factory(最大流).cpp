/*
 * 本题算法有漏洞，poj数据不严密所以也能AC，本题最好用拆点法
 *
 * 题意：
 * 第一行p,n 表示一台完整电脑一共有p个部件，接下来描述n种机器的工作状况
 * 每行开头一个数，表示单位时间内能够处理完Qi台电脑并传给下一个机器
 * 接下来p个数，表示这台机器工作可行性(称这个区域为工作状态区)，即：
 * 第i(1<=i<=p)位，0表示当前传给它的电脑不能有这个部件，机器才能继续加工
 * 1表示当前传给他的电脑必须有这个部件，机器才能继续加工
 * 2表示有没有都无所谓
 * 接下来还是p个数，表示经这台机器加工以后，电脑拥有部件的状况(称这个区域为工作完成区)
 * 0表示加工完后电脑没有部件i，1表示有了这个部件i
 * 现在求的就是单位时间内能够连续处理的电脑台数最多是多少台
 *
 * 思路：
 * 建图，建立一个超级源点src和一个超级汇点tar
 * 首先一台电脑还没开始制造，部件数量一定是0，然后：
 * 如果一台机器的工作状态区全是0，说明给它的电脑不能有任何部件这机器才能工作
 * 即这些机器S就是安排在流水线最前端的机器，建立边src->S，权值为这些机器的Qi
 * 如果一台机器的工作完成区全是1，说明电脑已经被制造完毕了，这些机器是流水线的末端，建立边集SS->tar,权值Qi
 * 中间的话，如果机器i的工作完成区和机器j不冲突，那么机器i加工的电脑就能传给j，建边i->j，权值为min(Qi,Qj)
 * 所谓不冲突，指的是i的工作完成区生产了某部件i，即i位为1，而j的工作状态区的i位非0，就说明不冲突，或者是0非1，共两种状态
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
