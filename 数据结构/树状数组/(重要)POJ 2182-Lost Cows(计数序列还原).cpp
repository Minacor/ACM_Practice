/*
 * ���⣺һȺţ��1-N��ź��������У������ǵ�ǰţǰ���ŵı������С��ţ������һͷţ������0�ʺ��ԣ�
 * ����������е�ţ�ı��
 *
 * ˼·���Ӻ���ǰ�ƣ�������������һͷţ�������С������Ϊa����ô���ı�ű�ȻΪa+1����Ϊǰ����������е�1~a����(����1)
 * ���ǰѱ��Ϊa+1����ͷţɾ�����������ڵ����ڶ���һͷţ�������С������Ϊb����ô��ţ��Ϊɾ����ź�ʣ��ţ�еĵ�b+1ͷţ�����ǿ����մ�˼·��ȥ...
 * ����Ϳ���ת��Ϊ�������ڵ�kλ����Ϊ����
 *
 * ����״����⣺
 * �����ơ��տ�ʼ��ʱ���n��λ�ö�׼���ã�Ȼ����ţ����һͷ�Ͱ���ص�λ�ü�1����ʾ֮ǰ��վ�ĵط�����һ����
 * Ȼ������λ�õ�ʱ���õ��Ƕ��ֲ��ҡ���Ϊ��״����ĺ��������
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
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;

int n;
int tree[8100];         //��״����ģ���������һ������:0 1 0 1 1 ... ����1��ʾ���λ�ÿ�����ţ��0��ʾ�����ԡ�
                        //��Ϊ�����������õ�һ�����ڵ�ǰ�жϵĺ��棬����Ӱ�����
int out[8100];
int order[8100];

int lowbit(int t)
{
    return t&(-t);
}

void modify(int pos , int delta)
{
    for( ;  pos <= n ; pos += lowbit(pos))
        tree[pos] += delta;
}

int getsum(int pos)
{
    int t=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        t += tree[pos];
    return t;
}

int Bsearch(int aim)      //�ҵ�һ��λ�ã�ʹ������֮ǰ(�����Լ�)�Ŀ���λ�ú�Ϊaim�����ݹ���һ�����λ�ñ�űض���aim
{
    int mid , l = 1 , r = n;

    while(l <= r)
    {
        mid = (l+r) >> 1;
        if(getsum(mid) >= aim)
            r = mid-1;
        else
            l = mid+1;
    }

    return l;
}

int main()
{
    freopen("in.txt" , "r" , stdin);

    scanf("%d",&n);

    for(int i = 1 ; i <= n ; i++)
    {
        if(i > 1)
            scanf("%d",order+i);
        modify(i,1);                                    //������λ��׼���ã���ʾ������վţ����(1,1,1,1...)
    }

    for(int i = n ; i >= 1 ; i--)
    {
        out[i] = Bsearch(order[i]+1);                   //���ݹ���1������Ѱ��������a+1��λ��
        modify(out[i],-1);                              //�Ѱ������λ��ȥ��(����0)
    }

    for(int i = 1 ; i <= n ; i++)
        printf("%d\n",out[i]);

    return 0;
}

/* ��һ��caseִ�й���:
 ��ʼ : 1 1 1 1 1
 һ   : order[i]+1=1����getsum(1)=1,�ʷ���1,1λ���㣬��� 0 1 1 1 1
 ��   : order[i]+1=2, ��getsum(3)=2,�ʷ���3,3λ���㣬��� 0 1 0 1 1
 ...
 */
