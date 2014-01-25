/*
 * ���⣺
 * ��������ֵ��Ǯ�ң�ÿ��Ǯ��һ������
 * ����ЩǮ������ϳɵ�1~m֮�����������
 *
 * ˼·��
 * �տ�ʼ�ö��ر��������Ա��ڴ��ˣ�����һ�ֱȽ������dp
 * dp[i]��ʾi���������û�б���ϳ�����
 * sum[i]��ʾ����ϳ�i��������£���ǰǮ�ұ����˼���
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

int n,m;

struct node
{
    int v;
    int num;
}coin[110];

int dp[100000+10] , num[100000+10];

int can(int m)
{
    memset(dp,0,sizeof dp);

    dp[0] = 1;

    int cnt=0;
    for(int i = 1 ; i <= n ; i++)
    {
        memset(num,0,sizeof num);
        for(int j = coin[i].v ; j <= m ; j++)
        {
            //ֻ��j-c.v��������ѱ���ϳ������п��ܼ��ϵ�ǰ��Ǯ�ҵõ�j
            //�ҵ�ǰ���jû�б���ϳ������ܼ����������ظ�
            //���Ҫ�ж�һ������Ǯ���ڵ�ǰ������Ƿ���ʣ��
            if(!dp[j] && dp[j-coin[i].v] && num[j-coin[i].v] < coin[i].num)
            {
                num[j] = num[j-coin[i].v]+1;
                dp[j] = dp[j-coin[i].v] + coin[i].v;    //��dp[j]Ϊ�����Ϳ�����
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    //FR;
    while(~scanf("%d%d",&n,&m) && (m||n))
    {
        for(int i = 1 ; i <= n ; i++)
            scanf("%d",&coin[i].v);
        for(int i = 1 ; i <= n ; i++)
            scanf("%d",&coin[i].num);

        printf("%d\n",can(m));
    }

    return 0;
}


