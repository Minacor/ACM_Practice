/*
 * http://blog.csdn.net/zhang20072844/article/details/6703432
 * 
 * ���⣺
 * ����һ��ƻ����������������Ϊ1��ÿһ����֧��Ϊһ������һֱ��N���������ƻ������
 * ÿ����֧(���)����ֻ�������һ��ƻ����Ҳ����һ��������治����������ƻ��
 * ����ע��һ�㣬��Ҫ��ƻ��������ɶ�������ƻ����ÿ���ڵ���Էֳ��ܶ�棬Ӧ���Ƕ������
 * �����ǽ��֮��Ĺ�ϵ��a b��ʾa����b���֮������֦����
 *
 * ���������ֲ�����Q ��C
 * C  j  ����˼����� j ������������ƻ����ժ����(-1)�����û�У���ô�ͻ᳤���µ�һ��(+1)
 * Q  j  ������ ��jΪ�����������ϵ�ƻ�������������
 * ���ϸտ�ʼÿ����㳤����ƻ��
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
#define FR (freopen("in.txt","r",stdin))
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 100000+100;
const int inf = 522133279;

struct egde
{
    int now;
    int next;
}e[MAX];

int head[MAX];
int line[MAX];              //line[i] : ������Ϊi�Ľ������ƻ������1������Ϊ0
int st[MAX],ed[MAX];        //st[i]~ed[i]��ʾ��iΪ���ڵ��һ������
int vis[MAX];       //�����û�б����ʹ�
int index,cnt;      //indexʱ�����cnt��¼����
int tree[MAX];
int n;

void dfs(int cur)           //���ṹ������Խṹ��ʱ����ǶԷ��ʴ���ı��
{
    vis[cur]=1;
    st[cur]=ed[cur]= ++index;
    for(int i = head[cur] ; i != -1 ; i = e[i].next)
    {
        int next = e[i].now;
        if(!vis[next])
            dfs(next);
    }
    ed[cur]=index;
}

int getsum(int pos)
{
    int t=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        t += tree[pos];
    return t;
}

void modify(int pos ,int delta)
{
    for( ; pos <= n ; pos += lowbit(pos))
        tree[pos] += delta;
}

void add(int x,int y)
{
    e[cnt].now=y;
    e[cnt].next = head[x];
    head[x] = cnt++;
}

void init()
{
    getchar();
    index=0;
    cnt=0;
    fill(line,line+n+1,1);      //��ʼ��ʱ�������ǳ���ƻ����
    clr(st,0);
    clr(ed,0);
    clr(tree,0);
    clr(vis,0);
    clr(head,-1);
    for(int i = 1 ; i <= n ; i++)
        modify(i,1);
}

int main()
{
    //FR;
    while(~scanf("%d",&n))
    {
        init();
        for(int i = 0 ; i < n-1 ; i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            getchar();
            add(a,b);
        }
        dfs(1);

        int q;
        scanf("%d",&q);
        getchar();
        while(q--)
        {
            char com;
            int num;
            scanf("%c %d",&com,&num);
            getchar();
            if(com == 'Q')
                printf("%d\n",getsum(ed[num])-getsum(st[num]-1));   //���st[num]�������������Ԫ�صĺ�
            else
            {
                if(line[st[num]])           //��ƻ����ժƻ����ûƻ���ͳ�ƻ��
                    modify(st[num],-1);
                else
                    modify(st[num],1);
                line[st[num]] = !line[st[num]];
            }
        }
    }

    return 0;
}

