/*

���⣺�ձ������������������ֱ���N��M�����У������޸��ٹ�·���Ӷ��������ĳ��У��󽻵������
��������ÿ�����߹�·Ϊ(x,y), �������ĵ�x�������������ĵ�y��������һ��·��������·�н���ʱ�����㣨x1-x2��*��y1-y2�� < 0��
���ԣ���ÿ��·��x��С����������x��ͬ����y��С�������� Ȼ�������Ĺ�·����״������£���y��������֮�ͼ�Ϊ���������
����˵�Ŀ����е�����⣬��ϸ˵�����¡�
�ǵ�i���ߵĶ˵�ֱ�Ϊxi,yi��
����x�Ǵ�С��������ģ����赱ǰ�����ڴ����k���ߣ���ô��1~k-1���ߵ�x��Ȼ��С�ڣ�����ʱ�����Ҳ����ۣ���k���ߵ� x �ģ���ôǰk-1�����У����k�����ཻ�ıߵ�yֵ��Ȼ����yk�ģ�
���Դ�ʱ����ֻ��Ҫ�����ǰk-1�������ж������ߵ�yֵ������[yk, M]����,Ҳ������yk����������MΪ�������и�������y�����ֵ�� ���Ծͽ�����ת����������͵����⣬��״��������
�������ߵ�x��ͬʱ�����Ǽ��������ߵ�yֵ�ֱ�Ϊya��yb��ya<yb),�����ȴ���x��ya�����ٴ���x��yb����ԭ������ԣ���Ϊ��x��ͬʱ��������������Ϊû�н���ģ�
���ȴ���x��yb������ô�´δ���x��ya��ʱ����x��ya���ͻ����x��yb������һ������Ҳ���ǽ������������ཻ�����ˡ�

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

struct node
{
    int x;
    int y;

    bool operator < (const node& b)const
    {
        if(x == b.x)
            return y < b.y;
        return x < b.x;
    }

}p[1000000+100];

int tree[1050];                         //��״����ά�����Ǹ���yֵ�ĸ���
int n,m,k;

int lowbit(int t)
{
    return t&-t;
}

void modify(int pos , int delta)
{
    for(;pos <= 1010 ; pos += lowbit(pos))
        tree[pos] += delta;
}

int getsum(int pos)
{
    int t=0;

    for(;pos > 0 ; pos -= lowbit(pos))
        t += tree[pos];

    return t;
}

int main()
{
    //FR;
    int t;
    scanf("%d",&t);

    for(int ka =1 ; ka <= t ; ka++)
    {
        memset(tree , 0 , sizeof tree);

        scanf("%d%d%d",&n,&m,&k);

        for(int i = 0 ; i < k ; i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        sort(p,p+k);

        LL ans=0;

        for(int i = 0 ; i < k ; i++)
        {
           int tmp = getsum(m) - getsum(p[i].y); //��ǰ��yֵ�ĸ��� - <=��ǰyֵ�ĸ������ȴ���С��y�Ļ���������ʽ�����涼�ǰ������ӵ����ģ����Ե�����
           ans += tmp;
           modify(p[i].y,1);                     //��Ӧ��yֵ����+1
        }

        printf("Test case %d: %I64d\n",ka,ans);
    }

    return 0;
}
