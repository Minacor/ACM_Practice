/*
 * �ο����ϣ�http://blog.csdn.net/lyy289065406/article/details/6762370
 *
 * ���⣺
 * ��һ������ͼ��ʩ���Ӷ���������һ��·����ά��ʱ������·������ͨ��
 * �����͵�������ʱ���ܴ�һ�����㵽������һ�����㣬��ʱ�����Ҫ�޶����·����ͨ��Щ����
 * Ϊ�˱�֤�����������У�������ĳһ��·��ά��ʱ��ʣ�µĵ�·�ܱ�֤�κ���������֮����ͨ
 * ����С��Ҫ�޵Ķ���·��
 *
 * ˼·��
 * tarjin��low����+����
 * ��Ŀת��Ϊ������Ӽ�����ʹ��һ��ͼ���˫��ͨͼ
 * ��������tarjin�ó�low����
 * ��û���رߵ�����£�lowֵ��ͬ�ĵ�һ������ͬһ˫��ͨ�����������رߵ�lowֵ��ͬҲ��������ͬһ˫��ͨ����
 * ����û���رߣ����Կ���ֱ������lowֵ�ж�
 * ����������ͬһ˫��ͨ�����ĵ��������һ�㣬��Ϊ���㡿
 * �����ת��Ϊ��������Ӽ�����ʹ��һ������ͼ���˫��ͨͼ
 *
 * Ȼ���и�����
 * ��Ҫʹ������һ�������������������ߺ󣬱��һ��˫��ͨͼ����ô
 * �������ӵı��� =�� ������ܶ���Ϊ1�Ľ���� + 1 ��/ 2
 *
 * ����ͼ�����ļ��㷨��
 * ����ö��ͼG��ֱ����ͨ�ĵ㣬ֻҪ�������㲻��ͬһ�������㡿�У���ô���Ǹ������ڵġ����㡿�Ķ�����+1
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
#define mkp make_pair
using namespace std;
typedef long long LL;
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int n,m;
int g[1010][1010];
int low[1010],dfn[1010],clo;

void tarjin(int cur,int fa)
{
    dfn[cur] = low[cur] = ++clo;

    for(int i = 1 ; i <= n ; i++)
    {
        if(g[cur][i])
        {
            if(!dfn[i])
            {
                tarjin(i,cur);
                low[cur] = min(low[i],low[cur]);
            }
            else if(fa != i)
                low[cur] = min(low[cur],dfn[i]);
        }
    }
}

int f[1010];

int solve()
{
    clr(f,0);

    for(int i = 1 ; i <= n ; i++)
        for(int j = i+1 ; j <= n ; j++)
        {
            if(g[i][j])
            {
                if(low[i] != low[j])            //��������ļ��㷨
                    f[low[i]]++,f[low[j]]++;
            }
        }

    int cnt=0;
    for(int i = 1 ; i <= n ; i++)
        if(f[i] == 1)
            cnt++;
    return cnt;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        clr(low,0);
        clr(dfn,0);

        for(int i = 0 ; i < m ; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a][b] = g[b][a]=1;
        }

        tarjin(1,-1);
        cout << (solve()+1)/2 << endl;
    }
    return 0;
}
