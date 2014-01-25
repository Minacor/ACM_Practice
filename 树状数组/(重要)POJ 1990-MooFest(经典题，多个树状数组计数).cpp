/*
 * ���⣺
 * ��nͷţ����һ��ֱ���ϣ�ÿͷţ��������x����ֵx��һ��������ֵv��
 * ��ͷţi,j�ܹ���������������vol = max(vi,vj)�������ȼ����裬���Ҳ�����������vol*dis(i,j) = vol*|xi-xj|
 * ��ÿһ��ţ������������
 *
 * ˼·��
 * ��������Ҫ�ľ��Ǽ������⣬�Ȱ�ţ����vֵ�Ӵ�С����
 * ��ô��������ţiʱ���ܱ�֤ǰi-1ͷţ��vֵ��С������v������ǰ��ͷţ��i�����������ȼ�����vi��
 * ���Զ���ÿһ��i������ֻҪ���ǰiͷţ��������������֮�ͣ����ۼӵ����������𰸾ͳ�����
 * ��ô��λ������֮�ͣ����仰˵��ʲô���ݽṹ���ڴ���iʱ���ٵõ�֮ǰ�Ե�ǰ��Ӱ��ĺ�ֵ���Ǿ�����״������
 * ��������״���飬һ����¼����ֵ�ܺͣ�һ����¼ţ��ͷ��
 * ��Ȼ�����б�i��vֵС��ţ�У�����xֵ��i���С��ţ����ʱ��Ҫ�����Ҽ��㣬���㷨��ʵ����
 * ���getsum(0)��ñ�i��xС��ţ��xֵ�ܺ�lsum��getsum(1)�����Щţ��ͷ��lcnt����ô���ǵ�i�ľ���֮�;���lcnt*i.x-lsum,�����Ҿ�����Ϊ�����Ĺ�ϵ
 * �ұ����ƣ�����rcnt����ֱ�Ӽ���:�����Ѿ�����i-1ͷţ�����lcntͷ���ұ߾���i-1-lcnt��
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
struct niu
{
    int x;
    int v;

    bool operator < (const niu&b)const
    {
        return v < b.v;
    }

}moo[20100];

int tree[2][20100]; //0:ά������ֵ�ܺͣ�1:ά��ţ������

int lowbit(int t)
{
    return t&-t;
}

int getsum(int op , int pos)
{
    int t=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        t += tree[op][pos];
    return t;
}

void modify(int op ,int pos , int delta)
{
    for( ; pos <= 20100 ; pos += lowbit(pos))
        tree[op][pos] += delta;
}

int main()
{
    //FR;
    while(~scanf("%d",&n))
    {
        memset(tree,0,sizeof tree);
        for(int i = 1 ; i <= n ; i++)
            scanf("%d%d",&moo[i].v , &moo[i].x);
        sort(moo+1,moo+1+n);

        LL res=0;
        for(int i = 1 ; i <= n ; i++)
        {
            LL lsum=getsum(0,moo[i].x),lcnt=getsum(1,moo[i].x);     //�ȵ�ǰţ����ֵС��ţ������ֵ�ܺ�,ţ������
            LL rsum = getsum(0,20010)-lsum,rcnt=i-1-lcnt;           //�ȵ�ǰţ����ֵ���ţ������ֵ�ܺ�,ţ������
            res += ((lcnt*moo[i].x-lsum) + (rsum-rcnt*moo[i].x))*moo[i].v;
            modify(0,moo[i].x,moo[i].x);        //�������µ�delta��1����ô����ֵ��ֱ�Ӽ�������ֵ����
            modify(1,moo[i].x,1);
        }

        printf("%I64d\n",res);
    }

    return 0;
}
