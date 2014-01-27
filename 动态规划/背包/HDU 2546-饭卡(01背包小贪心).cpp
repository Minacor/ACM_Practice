/*
 * ���⣺
 * ��������
 *
 * ˼·��
 * 0,1�����⣬���ص�����ι��챳��
 * ����һ���Ǹ�����һ�ֲ���5Ԫ
 * ���Ա�����������m-5����ʣ��Ĳ˾����������������
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
int a[1100];
int dp[MAX+100];

int main()
{
    //FR;
    while(~scanf("%d",&n) && n)
    {
        memset(dp,0,sizeof dp);
        int maxc=0,pos;

        for(int i = 0 ; i < n &&scanf("%d",a+i) ; i++)
            if(a[i] > maxc)
            {
                maxc=a[i],pos=i;
            }

        scanf("%d",&m);

        if(m < 5)
        {
            printf("%d\n",m);
            continue;
        }

        for(int i = 0 ; i < n ; i++)
        {
            if(i == pos) continue;
            for(int j = m-5 ; j >= a[i] ; j--)
                dp[j] = max(dp[j],dp[j-a[i]]+a[i]);
        }

        printf("%d\n",m-(maxc+dp[m-5]));
    }

    return 0;
}
