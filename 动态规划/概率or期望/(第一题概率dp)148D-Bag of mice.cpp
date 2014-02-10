/*
 * ���⣺
 * ԭ����������wֻ�����bֻ����
 * �������������Ӵ�����ץ����˭��ץ����ɫ����˭��Ӯ��
 * ����ÿ��ץһֻ���󲻻��������ܳ�����ÿ��ץ��һֻ����֮�����һֻ�����ܳ�����
 * ÿ��ץ������ܳ���������������ġ�
 * ��������˶�û��ץ����ɫ��������Ӯ��������ץ��
 * ������Ӯ�ĸ��ʡ�
 *
 * ����dp
 * һ���������˳�ƣ�������������
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
#define MID(x,y) ((x+y)>>1)
#define FR (freopen("in.txt","r",stdin))
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 200000+100;
const int inf = 522133279;
const int mod = 1000000007;

int w,b;
double dp[1010][1010]; //dp[i][j]�ֵ�����ʱʣ��iֻ������jֻ������

int main()
{
    cin >> w >> b;
    clr(dp,0);
    for(int i = 1 ; i <= w ; i++)
        dp[i][0]=1;

    //dp���������
    //����Ӯ�ĸ��� = �������Ӯ�ĸ���+�´�����Ӯ�ĸ���+���´�...
    //��Ȼÿһ��ת��ֱ���������+�´�
    //�����´ε����������,d[i][j-3],dp[i-1][j-2]Ҳ�������ǵ��´�Ӯ�ĸ���ת��������
    //��Ϊ����ÿһ��dp[i][j]����+�˱���Ӯ�ĸ���
    //�������һ����û��*û��*...*Ӯ��
    //��Ӯ�� = ����Ӯ��+(����û�� * (�´�Ӯ�� + �´�û�� * (���´�Ӯ�� + ���´�û�� * (... * ���Ӯ��)))) <-> �ܾ�Ӯ�� = ����Ӯ��+����û��*�Ӿ�Ӯ��
    for(int i = 1 ; i <= w ; i++)
        for(int j = 1 ; j <= b ; j++)
        {
            //ץ���˰�����
            dp[i][j] += 1.0*i/(i+j);
            //ץ���˺�������һ����ץ���˺��������˺�����
            if(j >= 3) dp[i][j] += 1.0*j/(i+j)*dp[i][j-3]*(1.0*(j-2)/(i+j-2))*(1.0*(j-1)/(i+j-1));
            ////ץ���˺�������һ����ץ���˺��������˰�����
            if(j >= 2) dp[i][j] += 1.0*j/(i+j)*dp[i-1][j-2]*(1.0*i/(i+j-2))*(1.0*(j-1)/(i+j-1));
        }
    printf("%.9lf\n",dp[w][b]);
    return 0;
}
