/*
 * ���⣺
 * ���ݣ�
 * ��һ����������
 * ÿ�����ݵ�һ�У��մ�Ǯ�޵�������װ������Ǯ�������
 * �ڶ���Ǯ������
 * ֮��������ÿһ��Ǯ��(��������)��Ǯ����ֵ Ǯ������
 * ���Ƿ���װ��������Ǯ��ʹ�ô�Ǯ��ǡ���Ǹ���������������ܣ������С��ֵ�ܺ�
 *
 * ˼·��
 * ��ȫ����������
 * �����������ռ����ģ�Ŀ��������������������Ǯ����ֵ������ֵ�������һ���жϱ��������ԣ���������С��ֵ�ļ�����
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

int t;
int dp[11000];

int main()
{
    //FR;
    scanf("%d",&t);
    while(t--)
    {
        int tx,ty;
        scanf("%d%d",&tx,&ty);
        int up = ty-tx;
        int n;
        scanf("%d",&n);

        //����С��ֵ�ĳ�ʼ������
        memset(dp,0x1f,sizeof dp);
        dp[0]=0;

        for(int i = 0 ; i < n ; i++)
        {
            int c,w;
            scanf("%d%d",&w,&c);
            for(int j = c ; j <= up ; j++)
                dp[j] = min(dp[j],dp[j-c]+w);
        }

        //���Ŀ������δ�����£���Ȼ��ʾ��״̬���ɴ�
        if(dp[up] != inf)
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[up]);
        else
            puts("This is impossible.");
    }

    return 0;
}
