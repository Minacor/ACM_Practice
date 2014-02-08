/*
 * ���⣺
 * ��һ��ҩˮ���У�ţֻ�ܰ�˳��ȣ�����������ĳЩҩˮ����
 * ��1��ʼ�����������κȵ�ʱ����������Ծ������ż���μ���
 * ��ʼ��Ծ����0��������ܵõ�����Ծ����
 *
 * ˼·��
 * ����������
 * odd[i]��ʾǰiƿҩˮ��ѡ���������ܴﵽ�����ֵ
 * eve[i]��ʾǰiƿҩˮ��ѡ��ż�����ܴﵽ�����ֵ
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

int a[150000+100];
int odd[150000+100],eve[150000+100];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++ )
        scanf("%d",a+i);

    for(int i = 1 ; i <= n ; i++)
    {
        odd[i] = max(odd[i-1] , eve[i-1]+a[i]); //ǰi-1��Ҳѡ������ƿҩˮ����β�ѡ �� ǰi-1��ѡ��ż��ƿҩˮ�����ѡ�ˣ���Ծ��������
        eve[i] = max(eve[i-1] , odd[i-1]-a[i]); //ǰi-1��Ҳѡ��ż��ƿҩˮ����β�ѡ �� ǰi-1��ѡ������ƿҩˮ�����ѡ�ˣ���Ծ��������
    }

    printf("%d\n",max(odd[n],eve[n]));

    return 0;
}
