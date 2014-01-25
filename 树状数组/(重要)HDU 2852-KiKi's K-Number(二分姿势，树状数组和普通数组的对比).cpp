/*
 * ���⣺
 * 3�ֲ�����
 * p = 0 ������e���뼯��
 * p = 1 ������e�Ӽ�����ɾ�������û������������ָ���ַ���
 * p = 2 ���ҳ���a��k������ע�������"��"ָ���ǽ������е�����С�����������һ��a֮��ĵ�k����������n����ͬ����Ҳ��Ҫ��n�ε�
 *
 * ˼·��
 * ׼���������飬��״����treeά���������ֳ��ִ�����ԭ����originҲ�Ǽ�¼���ִ���
 * ֻ������״�����������ټ������֮���Ա��ѯ��origin�Ƿ���Ԫ�ص���Ӻ�ɾ��
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
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;
const int inf = 50000000;

int n;
int tree[100000+100];
int origin[100000+100];

int lowbit(int n)
{
    return n&-n;
}

int getsum(int pos)
{
    int t=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        t += tree[pos];
    return t;
}

void modify(int pos , int delta)
{
    for( ; pos <= 100000 ; pos += lowbit(pos))
        tree[pos] += delta;
}

void query(int a, int k)                //���ֵ����ƣ��Ժ�����������ư�~
{
    if(getsum(100000)-getsum(a) < k)
    {
        puts("Not Find!");
        return;
    }

    int l=a , r = 100000;
    int mid;

    do
    {
        mid = (l + r) >> 1;

        int tmp = getsum(mid)-getsum(a);

        if(tmp >= k)            //�Ⱥź���Ҫ����©
            r = mid-1;
        else
            l = mid+1;
    }while(l <= r);

    printf("%d\n",l);
}

int main()
{
    FR;

    while(~scanf("%d",&n))
    {
        memset(origin,0,sizeof origin);
        memset(tree,0,sizeof tree);

        int op;

        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d",&op);

            if(op == 0)             //��Ӻ�ɾ����ԭ�����в�����ͬʱ������״���飬��ʵ����������������һ���ģ�ֻ�������ܲ�ͬ
            {
                int e;
                scanf("%d",&e);

                origin[e]++;
                modify(e,1);
            }
            else if(op == 1)
            {
                int e;
                scanf("%d",&e);

                if(origin[e] == 0) puts("No Elment!");
                else
                {
                    origin[e]--;
                    modify(e,-1);
                }
            }
            else
            {
                int a,k;
                scanf("%d%d",&a,&k);

                query(a,k);
            }
        }
    }

    return 0;
}
