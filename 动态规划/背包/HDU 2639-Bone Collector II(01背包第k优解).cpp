/*
 * 01������k�Ž�ģ����
 *
 * ���⣺
 * ��һ����������
 * ÿ�����ݵ�һ������������Ʒ����n ����������m ��k�ŵĽ�
 * �ڶ��и���Ʒ�ļ�ֵ
 * �����и���Ʒ�Ĵ�С
 *
 * ���k�Ž⣬��������������k�����0������һ���Ľ���ͬһ���
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

int t;
int dp[1100][35];           //dp[i][j]��ʾ����Ϊi�ı����еĵ�k�Ž�
int que1[35],que2[35];      //�ϲ��ã����СΪk
int c[110],w[110];

int main()
{
    //FR;
    int n,m,k;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        memset(dp,0,sizeof dp);
        memset(que1,0,sizeof que1);
        memset(que2,0,sizeof que2);

        for(int i = 1 ; i <= n ; i++)
            scanf("%d",w+i);
        for(int j = 1 ;j <= n ; j++)
            scanf("%d",c+j);

        for(int i = 1 ; i <= n ; i++)       //�������ѭ����01����һ��
        {
            for(int j = m ; j >= c[i] ; j--)
            {
                for(int x = 1 ; x <= k ; x++)   //��"��x�Ž�"
                {
                    que1[x] = dp[j][x];
                    que2[x] = dp[j-c[i]][x] + w[i];
                }
                que1[k+1]=que2[k+1]=-1;

                int pos1=1,pos2=1,x=1;
                while(x<=k && (que1[pos1]!=-1 || que2[pos2]!=-1))
                {
                    //�ô�ĸ���
                    dp[j][x] = que1[pos1] > que2[pos2] ? que1[pos1++] : que2[pos2++];

                    if(dp[j][x] != dp[j][x-1])  //��ĿҪ���ϸ��k�Ž⣬������ͬ�Ĳ������µĽ�
                        x++;
                }
            }
        }

        printf("%d\n",dp[m][k]);
    }

    return 0;
}
