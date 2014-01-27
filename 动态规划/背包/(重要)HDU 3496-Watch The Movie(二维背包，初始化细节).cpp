/*
 * ���⣺
 * ���ݣ�
 * ��һ����������
 * �ڶ����������������n ����Ҫ������򵽵Ĺ����m(���ܶ�Ҳ������) �涨���ܳ�������ʱ��l
 * ������n�У�ÿ����������
 * �������ʱ�� ������ļ�ֵ
 *
 * Ҫ�����ǡ����m�ŵ�ʱ����ʱ�䲻����l�µļ�ֵ���ķ����ļ�ֵ��
 *
 * ˼·��
 * ���͵�01��ά��������ĵ�����ʱ����Ϊ������������
 * ����Ҫע����ǳ�ʼ������
 *
 * �����Ž����ᵽ����Ҫ��ǡ��װ����������ô�ڳ�ʼ��ʱ����F[0] Ϊ0������
 * F[1::V ] ����Ϊ����������Ϳ��Ա�֤���յõ���F[V] ��һ��ǡ��װ�����������Ž⡣
 * �����û��Ҫ�����ѱ���װ��������ֻϣ���۸����󣬳�ʼ��ʱӦ�ý�F[0...V]
 * ȫ����Ϊ0��
 *
 * ����Ҫ�����һ����m��Ҳ����˵ǡ��װ�����������Դ�����������飬��ͷ��ʼ��Ϊ0���������ʼ��Ϊ������
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

int dp[1100][110];

int main()
{
    //FR;
    int t;
    scanf("%d",&t);

    while(t--)
    {
        for(int i = 0 ; i < 1100 ; i++)
        {
            for(int j = 0 ; j < 110 ; j++)
                dp[i][j]= -inf;
            dp[i][0]=0;
        }

        int n,m,l;
        scanf("%d%d%d",&n,&m,&l);

        for(int i = 0 ; i < n ; i++)
        {
            int time,val;
            scanf("%d%d",&time,&val);

            for(int j = l ; j >= time ; j--)
                for(int k = m ; k >= 1 ; k--)
                    dp[j][k] = max(dp[j][k],dp[j-time][k-1]+val);
        }

        printf("%d\n",dp[l][m] > 0 ? dp[l][m] : 0);
    }

    return 0;
}
