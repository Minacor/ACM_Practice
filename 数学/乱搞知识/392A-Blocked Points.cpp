/*
 * ���⣺
 * ������һ���뾶Ϊn��Բ�ڵĿ��������ĵ�ĸ���
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
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int main()
{
    int n;
    cin >> n;

    if(!n)
    {
        cout << 1 << endl;
        return 0;
    }
    LL cnt=0,last=0;
    for(int i = n-1 ; i >= 1 ; i--) //ö�������㣬����������ƶ�1��λ����Բ����
    {
       LL j = (LL)sqrt(1.0*n*n-1.0*i*i);       //������
       cnt++;
       cnt += (j-last-1) > 0 ? j-last-1 : 0;    //last�����һ���������λ�ã�last~j֮��ĵ�Ҳ��������
                                                //��Щ�������ƶ�1��λ����Բ����
       last=j;
    }
    cout << 4*cnt+4 << endl;
    return 0;
}
