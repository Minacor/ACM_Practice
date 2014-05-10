/*******************************************************

    ���⣺
    ���ݣ�
    ��һ����n�����ж��ٷ���
    ������n�У�
    ÿ�е�һ����vv��ʾ���������õ���Ȩֵ��-100~100
    �ڶ�����num��ʾ��������ܹ�ͨ��num������
    Ȼ��num�������ܹ�ͨ��ķ���ı�ţ�����ͨ��
    ��һ������͵�n�������Ȩֵ��Ϊ0

    �������˹���100�ĳ�ʼȨֵ��������Ҫ��1��ʼͨ��n
    ÿ����һ������ͱ��뽫��������Ȩֵ�ӵ��Լ���Ȩֵ��
    ����Լ���Ȩֵ�ڵ����յ�ǰ <=0 �ˣ��͹���
    ������������ν���
    �����˹��ܷ񵽴��յ�n

    ˼·��
    ������Ȼ�����л��ˣ���spfa���·�����ж���Ȩ������Ϊ
    һ��������Ȩ������ôȨֵ�Ϳ��������ۼӣ�
    ���������е�ĳ���ܹ������յ㣬��ô��һ����Ӯ

    �ر�ע�⣺
    ��cnt�����л��Ļ����ܹ��ҳ����еĻ��������ǣ�
    ���л��бض���һ������������������,����cnt[i] >= n
    �ж�һ���ܷ񵽴��յ㣬���ô��ݱհ������ʾͿ�����

********************************************************/

//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include "iostream"
#include "cstring"
#include "algorithm"
#include "cmath"
#include "cstdio"
#include "sstream"
#include "queue"
#include "vector"
#include "list"
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
#define PI acos(-1.0)
#define mkp make_pair
using namespace std;
typedef long long LL;
const int MAXN = 100000+100;
const int inf = 522133279;
const int mod = 1000000007;

int g[110][110],mg[110][110];
int low[110];
int cnt[110];
int vis[110];
int vv[110];
int n;

void spfa()
{
    for(int i =0 ; i <= n ; i++)
        low[i]=-inf;
    clr(vis,0);
    vis[1]=1;
    cnt[1]++;
    low[1]=100;

    queue<int> que;
    que.push(1);

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        vis[cur]=0;
        if(cnt[cur] >= n)
            break;

        for(int i = 1 ; i <= n ; i++)
        {
            if(g[cur][i])
            {
                if(low[i] <= low[cur]+vv[i] && low[cur]+vv[i] > 0)      //low[cur]+vv[i] > 0�����������üӣ��Ѿ�<=0�˾Ͳ���������ȥ��
                {
                    low[i] = low[cur]+vv[i];

                    if(!vis[i])
                    {
                        vis[i] = 1;
                        que.push(i);
                        cnt[i]++;
                    }
                }
            }
        }
    }

    if(low[n] > 0)      //����ܹ�ֱ�ӵ����յ�
    {
        printf("winnable\n");
        return ;
    }
    else                //�����ж��Ƿ����������еĻ���ֻҪ����ĳһ���ܹ������յ��һ����Ӯ
    {
        for(int i = 1 ; i <= n ; i++)
            if(cnt[i] >= n && mg[i][n])
            {
                printf("winnable\n");
                return ;
            }
    }
    printf("hopeless\n");
}

int main()
{

    while(~scanf("%d",&n) && n!=-1)
    {
        clr(g,0);
        clr(cnt,0);
        clr(mg,0);
        for(int i = 1 ; i <= n ; i++)
        {
            int num;
            scanf("%d%d",&vv[i],&num);

            for(int j = 0 ; j < num ; j++)
            {
                int tmp;
                scanf("%d",&tmp);
                mg[i][tmp]=g[i][tmp] = 1;
            }
        }

        for(int k = 1 ; k <= n ; k++)
            for(int i = 1 ; i <= n ; i++)
                for(int j = 1 ; j<= n ; j++)
                    if(mg[i][k]+mg[k][j]==2)
                        mg[i][j]=1;
        spfa();
    }
    return 0;
}

/*

    9
    0 2 2 5
    100 1 3
    100 1 4
    100 1 2
    1 1 6
    1 2 7 8
    1 1 5
    -100 1 9
    0 0

*/
