/*
 * ���⣺
 * ���˹�Ҫ��m�����������ſΣ���Щ�λ���ͬ�����в�ͬ������
 * ���Ҫ���������
 *
 * ˼·��
 * ͬһ�ſ�ֻ����һ�Σ�Ҳ����˵�����ſεĲ�ͬʱ�������ֻ��ѡһ��ʱ��
 * ���鱳��
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

int n,m;
int v[110][110];
int dp[110];

int main()
{
    //FR;
    while(~scanf("%d%d",&n,&m) && (n||m))
    {
        memset(dp,0,sizeof dp);

        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= m ; j++)
                scanf("%d",&v[i][j]);

        for(int k = 1 ; k <= n ; k++)           //�ֳɵ�����
            for(int i = m ; i >= 0 ; i--)       //�������� ����ע��
                for(int j = i ; j >= 1; j--)        //��ǰ���е�ÿһ��Ԫ�أ�����ע��ᳬ���������ľͲ�Ҫ����ѭ�����ˣ�����j��i��ʼ
                    dp[i] = max(dp[i],dp[i-j]+v[k][j]);

        printf("%d\n",dp[m]);
    }

    return 0;
}
