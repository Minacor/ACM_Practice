/*
 * ���⣺
 * ��һ�����У�������һ�ֲ�����һ�ν��������������ڵ��������ɴβ�����������оͱ��������
 * �����ٵĲ�������
 *
 * ˼·��
 * �����������ǣ���һ�������������������������Ϊֹ�������ð�ݵ�˼�룬��Ҳ����ð�ݵĴ���
 * ��������������50W��ð�ݾͺǺ���
 *
 * ���ǿ��ǵ�������һ���������Ľ����������������������������ɵ��������
 * (����Ծ��������У����� i<j �� Ai > Aj ������(Ai,Aj) , ��������������������Ե�����)
 *
 * ���Ա������������������״������������������ÿһ������ǵ�ǰ��ǰ�������������������ټ�����
 *
 * ���������ݷ�Χ0~999999999����״�����pos�����ܶ�λ����ô��������Ҫ��ɢ��
 * ��ɢ���������ǽ���������С������������֮��Ĵ�С��ϵ��ʹ���ܹ�����״����ά��
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

int tree[500000+100];
int ok;
int n;

struct node
{
    int v;
    int id;

    bool operator < (const node& b)const
    {
        if(!ok)
            return v<b.v;
        else
            return id<b.id;
    }

}num[500000+100];

int lowbit(int t)
{
    return t & -t;
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
    for( ; pos <= n ; pos += lowbit(pos))
        tree[pos] += delta;
}

int main()
{
    while(~scanf("%d",&n) && n)
    {
        ok=0;
        memset(tree,0,sizeof tree);

        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d",&num[i].v);
            num[i].v++;
            num[i].id=i;
        }

        sort(num+1,num+1+n);    //����v�Ĵ�С����ʹ���ܹ��������ǵĴ�С��ϵ��ɢ������С������

        num[1].v=1;
        for(int i = 2 ; i <= n ; i++)
        {
            if(num[i].v != num[i-1].v)
                num[i].v=i;
        }

        ok=1;
        sort(num+1,num+1+n);    //��ԭԭ��

        LL ans=0;
        for(int i = 1 ; i <= n ; i++)
        {
            modify(num[i].v,1);
            ans += getsum(n) - getsum(num[i].v);
        }

        printf("%I64d\n",ans);

    }

    return 0;
}
