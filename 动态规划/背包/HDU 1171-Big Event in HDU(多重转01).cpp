/*
 * ���⣺
 * ��һ�Ѷ����и��Ե�ֵ��������Ҫ�����Щ�����ֳ����ѣ�ʹ�����ǵ���ֵ�����ܽӽ�
 *
 * ˼·:
 * ���������涨����Ʒ����ȫ����
 * ���ڴ���������С������ֱ��ת����01���������Ӷ�O(V��Mi)
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
int a[5100];
int dp[25000*20+1000];

int main()
{
    int v,m;
    FR;
    while(~scanf("%d",&n) && n >= 0)
    {
        int pos=0;
        int sum=0;
        memset(dp , 0  ,sizeof dp);

        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d%d",&v,&m);
            sum += v*m;
            while(m--) a[pos++] = v;
        }

        for(int i = 0 ; i < pos ; i++)
            for(int j = sum/2 ; j >= a[i] ; j--)
                dp[j] = max(dp[j],dp[j-a[i]]+a[i]);

        printf("%d %d\n" , sum - dp[sum/2] , dp[sum/2]);

    }

    return 0;
}
