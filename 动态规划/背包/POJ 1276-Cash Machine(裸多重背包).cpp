/*
 * ���⣺
 * ���룺
 * ��Ҫ��Ǯ���� ���õ���ֵ����n (��ֵi������ ��ֵi����ֵ , i -> 1~n)
 * �������ܴճ���Ǯ��������Ҫ��Ǯ����Ϊ����
 *
 * ˼·��
 * ����Ķ��ر���
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
const int MAX = 40000;
const int inf = 522133279;

int up,n;
int dp[100000+100],sum[100000+100];

int main()
{
    //FR;
    while(~scanf("%d%d",&up,&n))
    {
        memset(dp,0,sizeof dp);
        dp[0]=1;
        int maxc = 0;
        for(int i = 0 ; i < n ; i++)
        {
            int num,v;
            scanf("%d%d",&num,&v);
            memset(sum , 0 , sizeof sum);

            for(int j = v ; j <= up ; j++)
            {
                if(!dp[j] && dp[j-v] && sum[j-v]<num)
                {
                    dp[j]=1;
                    sum[j] = sum[j-v]+1;
                    maxc = max(maxc,j);
                }
            }
        }

        printf("%d\n",maxc);
    }

    return 0;
}
