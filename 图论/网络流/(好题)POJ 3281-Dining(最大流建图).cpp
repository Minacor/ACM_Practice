/*
 * ���⣺
 * ��Nͷţ��F��ʳ�����������D�����Ͽ�������
 * Ȼ��ÿ�д���һͷţ��ϲ�ã���ͷ������fi,di��ʾ��ͷţϲ��fi��ʳ�di�����ϣ�������fi������ʾϲ����ʳ���ţ�di������ʾϲ�������ϵı��
 * ��������ʹ�����ž���������F��ʳ���D�����ϣ�����ôι����ʹ�����ܶ��ţι��(ι��=һ��ʳ��һ�����ϣ���һͷţ�������һ��ʳ���һ������)
 * ������ι����ţ��
 *
 * ˼·��
 * ����ؼ��ǽ�ͼ��ͼ�����Ժ������dinic
 * ��ͼ��������1+F+D+2*N+1����㣬1��ʾԴ�㣬1+F+D+2*N+1��ʾ���
 * 1+1 ~ 1+F��ʾʳ���㣬1+F+1 ~ 1+F+N��ʾţ�ı�ţ�1+F+N+1 ~ 1+F+2*NҲ��ʾţ�ı�ţ�Ϊʲô��������˵��
 * 1+F+2*N+1 ~ 1+F+2*N+D��ʾ���ϱ��
 *
 * Ȼ��ϲ����ʳ��ָ��ϲ������ţ�����бߣ�ţiָ��ţi�����бߣ�ţָ����ϲ�������ϵ����бߣ�Դ�㵽����ʳ����ϵ����л��ıߣ�Ȩֵȫ��Ϊ1
 *
 * ��ͼ���ͣ�
 * ���ȣ����ͼ����Ϊ����ģ�飬����������Ϊ��ʳ������ģ��(src-F�߼�)��ιʳ��ģ��(F-N1�߼�)��ţ��ʳ��ģ��(N1-N2�߼�)��ι����ģ��(N2-D�߼�)��ţ������ģ��(D-tar�߼�)
 * Ȼ�����Ϊʲô��ȨֵΪ1����һ��������ʳ���ˮ����һ�ݣ��ڶ���ţ����һ��ʳ��(ˮ)�������ж��ʳ��ָ��ţ��������һ����(ţָ���ıߣ���ţ��ʳ��(������)ģ��)Ϊ1����ζ�����ֻ������1�����������Ե�����һ��ʳ�ˮ��ָ��ͬ��
 * ���������뵽ΪʲôҪ������ţ�ˣ�����Ҫͨ��ţ-ţ�߿�������Ϊ1����ͨ��ʳ��ѡ��ģ��󣬱�֤һͷţֻ����һ��ʳ��
 * Ȼ�����ʳ������Ϊ1�ˣ���ֻ��ѡһ��·�����ϣ��������������Ҳ��Ψһһ���ߣ���ʾ������������ֻ�ܱ�һͷţѡ��
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
const int MAX = 100+100+2*100+100;
const int inf = 522133279;
const int mod = 1000000007;

int F,D,N;
int g[MAX][MAX];
int lv[MAX];

bool bfs(int src , int tar)
{
    clr(lv,0);
    queue<int> que;
    que.push(src);
    lv[src]=1;

    while(!que.empty())
    {
        int cur = que.front(); que.pop();

        for(int i = src ; i <= tar ; i++)
            if(!lv[i] && g[cur][i])
            {
                lv[i]=lv[cur]+1;
                if(i == tar) return 1;
                que.push(i);
            }
    }
    return 0;
}

int dfs(int cur , int src , int tar , int totflow)
{
    int ret=0;
    if(cur==tar||!totflow)
        return totflow;

    for(int i = src ; i <= tar ; i++)
    {
        if(totflow==0) break;
        if(g[cur][i]&&lv[cur]+1==lv[i])
        {
            int f = min(totflow,g[cur][i]);
            int flowdown = dfs(i,src,tar,f);
            ret+=flowdown;
            totflow-=flowdown;
            g[cur][i]-=flowdown;
            g[i][cur]+=flowdown;
        }
    }
    return ret;
}

int dinic(int src , int tar)
{
    int ret=0;
    while(bfs(src,tar))
    {
        int tmp = dfs(src,src,tar,D+F);
        if(!tmp) break;
        ret += tmp;
    }
    return ret;
}

int main()
{
    while(~scanf("%d%d%d",&N,&F,&D))
    {
        int src=1,tar=1+F+D+2*N+1;

        for(int i = 1 ; i <= F ; i++)   //src-F�߼�
            g[src][src+i]=1;
        for(int i = 1+2*N+F+1; i < tar ; i++)   //D-tar�߼�
            g[i][tar]=1;
        for(int i = 1 ; i <= N ; i++)
        {
            g[src+F+i][src+F+i+N]=1;        //N1-N2�߼�
            int fi,di;
            scanf("%d%d",&fi,&di);

            int tmp;
            while(fi--)     //F-N1�߼�
                scanf("%d",&tmp),g[src+tmp][src+F+i]=1;
            while(di--)     //N2-D�߼�
                scanf("%d",&tmp),g[src+F+i+N][src+F+2*N+tmp]=1;
        }

        printf("%d\n",dinic(src,tar));
    }
    return 0;
}

