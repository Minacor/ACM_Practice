/*
 * ���⣺
 * ��һ���ɿ�����װ��д��һ�����֣��ռ���һ�����ֿ��Ի���Ӧ���ֵĽ�Ʒ�����꽱Ʒ��ֻ�Ǽ򵥵ش��������м�ȥ��Ʒ��Ӧ����
 * ���˹���̰�ģ�ÿ��һ���ɿ����������ǰ�����ֺ��ܹ�����Ʒ�����̻����Ӽ�ֵ�ߵĿ�ʼ����ֱ��������Ϊֹ��Ȼ���ٳ���һ���ɿ���
 * ������ÿ�ֽ�Ʒ��Ӧ�Ļ��õ�������ʣ������
 *
 * ˼·��
 * ���ڶһ��Ǵ���������ֱ�Ӽ���������������������ֽʹ�����ߵ����ֺ�>=��Ʒ���֣��������
 * ֱ��ģ��Ϳ�����
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
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 200000+100;
const int inf = 522133279;

LL jiangpin[10],cnt[10],a[60];
LL v;
int n;

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    for(int i = 1 ; i <= 5 ; i++)
        cin >> jiangpin[i];

    for(int i = 0 ; i < n ; i++)
    {
        v += a[i];
        for(int j = 5 ; j >= 1 ; j--)       //�Ӵ�Ŀ�ʼ����
        {
            int tmp = v/jiangpin[j];        //�ܻ���ǰ��Ʒtmp��
            v -= jiangpin[j]*tmp;
            cnt[j]+=tmp;
        }
    }

    for(int i=1;i<=5;i++)
        cout << cnt[i] << ' ';
    cout << '\n' << v << endl;;
    return 0;
}
