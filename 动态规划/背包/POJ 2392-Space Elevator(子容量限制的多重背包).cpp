/*
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

int dp[40100];

int main()
{
    FR;
    int k;
    while(~scanf("%d",&k))
    {
        memset(dp , 0 , sizeof dp);

        for(int i = 0 ; i < k ; i++)
        {
            scanf("%d%d%d",&block[i].h,&block[i].mh,&block[i].num);
        }
        sort(block,block+k);

        for(int i = 0  ;i < k ; i++)
        {
            if(block[i].num*block[i].h >= block[i].mh)
            {
                for(int j = block[i].h ; j <= block[i].mh ; j++)
                        dp[j] = max(dp[j],dp[j-block[i].h]+block[i].h);
            }
            else
            {
                int x = 1;
                while(x < block[i].num)
                {

                    for(int j = block[i].mh ; j >= x*block[i].h ; j--)
                            dp[j] = max(dp[j] , dp[j-x*block[i].h] + x*block[i].h);

                    block[i].num -= x;
                    x *= 2;
                }

                 for(int j = block[i].mh ; j >= block[i].num*block[i].h ; j--)
                        dp[j] = max(dp[j] , dp[j-block[i].num*block[i].h] + block[i].num*block[i].h);

            }

        }

        printf("%d\n",*max_element(dp,dp+MAX));     //ע����������������Ѱ����ֵ
    }

    return 0;
}
