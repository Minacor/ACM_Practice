/*
 * ���ر�����Чģ��
 *
 * ���⣺
 * ��һ��ש����ǽ��ÿһ��ש���и߶�h������num����λ����ߵ�ש�鲻�ܳ���mh
 * ������������ߵ�ǽ
 *
 * ˼·��
 * ���ȶ��ر�������
 * ÿһ��ש�鶼�������Ƹ߶ȣ����Զ�ÿһ��ש���䱳������������߶�����mh
 * ����ֻҪ���ö��ر���ģ��ʱ��̬�ı䱳������������
 * ��������dp��ǰһ״̬�������ԣ�ש��Ӧ�ø���mh��С��������
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

struct node
{
    int h,mh,num;
    bool operator < (const node& b)const
    {
        return mh < b.mh;
    }

}block[410];

int dp[40100],sum[40100];       //dp[i] != 0��ʾ�Ѿ���i�ռ䱻ʹ�ù�

int main()
{
    //FR;
    int k;
    while(~scanf("%d",&k))
    {
        memset(dp , 0 , sizeof dp);

        for(int i = 0 ; i < k ; i++)
        {
            scanf("%d%d%d",&block[i].h,&block[i].mh,&block[i].num);
        }
        sort(block,block+k);

        dp[0]=1;
        int maxc=0;
       for(int i = 0 ; i < k ; i++)
       {
            memset(sum,0,sizeof sum);
            for(int j = block[i].h ;j <= block[i].mh ; j++) //����
            {
                if(!dp[j] && dp[j-block[i].h] && sum[j-block[i].h] < block[i].num)
                {
                    dp[j]=1;
                    sum[j] = sum[j-block[i].h]+1;
                    maxc = max(maxc,j);
                }
            }

       }

       printf("%d\n",maxc);
    }

    return 0;
}
