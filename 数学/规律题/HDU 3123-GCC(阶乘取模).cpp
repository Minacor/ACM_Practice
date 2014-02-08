/*
 * ���⣺
 * �������ݣ�ÿ������һ�У���������n��m
 * Ҫ�����(0! + 1! + ... + n!) % m�Ľ��
 *
 * ˼·��
 * ����ѧ������
 * ע�⵽n�������m��С������һ��n>=m , n!%m����0�ˣ������ļ����û����
 * ���Ե�n >= mʱֻҪ����m�͹���
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

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        double n;
        int m;
        scanf("%lf%d",&n,&m);

        /*if(n==0&&m==1)
        {
            puts("0");
            continue;
        }*/

        int up = n > m ? m : (int)n;

        LL ans=1;
        LL tmp=1;
        for(int i = 1 ; i <= up ; i++)
        {
            tmp = (tmp*i)%m;
            ans = (ans+tmp)%m;
        }

        printf("%I64d\n",ans%m);        //�ر�ע��ľ�����������%m������ע�ʹ������������1�����´���
    }

    return 0;
}
