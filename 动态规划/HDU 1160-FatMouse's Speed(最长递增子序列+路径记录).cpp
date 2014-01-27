/*
 * ���⣺
 * ��һȺ����ÿһ�б�ʾ��������� �ٶ�
 * �ҵ�����һ������ʹ�������ϸ�������ٶ��ϸ�ݼ�
 *
 * ˼·��
 * ���������ȴ�С��������(������ٶȴӴ�С����)�������ݼ������У���¼·��
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
const int MAX = 1000;
const int inf = 522133279;

struct node
{
    int id;
    int w;
    int s;

    bool operator < (const node& b)const
    {
        return w == b.w ? s > b.s : w < b.w;
    }
}mice[10000+100];

int dp[10000+100],pre[10000+100],order[10000+100];//pre��¼���ݼ�������·�����������Ҫ���ԭid����Ҫ����һ��ӳ��order

int main()
{
    //FR;
    int n=1;
    while(~scanf("%d%d",&mice[n].w,&mice[n].s))
        mice[n].id = n,n++;
    sort(mice+1,mice+n);

    int maxc = 0,pos=0;
    fill(dp,dp+10000,1);

    for(int i = 1 ; i < n ; i++)        //���ݼ�������
    {
        for(int j = i ; j >= 1 ; j--)
        //Ҫע����ĿҪ�����߶����ϸ����/�ݼ��ģ������ж��ٶ�ʱ��Ҫ��������ͬ���жϽ�ȥ
            if(mice[j].w < mice[i].w && mice[j].s > mice[i].s && dp[j]+1 > dp[i])
                dp[i]=dp[j]+1 , pre[i]=j;   //��ǰ�������У�j�ǽ���i��ǰ��һ��Ԫ��

        if(maxc < dp[i])
            maxc = dp[i] , pos=i;   //��¼���һ��Ԫ�ص�λ��
    }

    for(int i = 1 ; i <= maxc ; i++) //�����һ��Ԫ�ؿ�ʼ����·����ѹ���������
    {
        order[i] = pos;
        pos = pre[pos];
    }

    printf("%d\n",maxc);
    for(int i = maxc ; i >= 1 ; i--)    //�������ǰ�����Ԫ�ص�id
        printf("%d\n",mice[order[i]].id);

    return 0;
}

