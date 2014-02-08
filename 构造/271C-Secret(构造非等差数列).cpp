/*
 * ���⣺
 * ��k���˷ֵ�n����(1~n)��ÿ�����õ����������ظ����������ʣ�࣬��ÿ�����õ��������в����ǵȲ�����
 * ���һ�ַ��䷽ʽ����i����output[i]��ʾoutput[i]���������i�����
 *
 * ˼·��
 * ������ֻ֪Ҫ��һ�����õ���<=2��һ�������ԣ���n/k<=2ʱֱ�����-1����ʾ����������һ���ò���������
 * �������·������죺
 * 1:�������1~n
 * 2:���ڱ�֤ÿ���õ���>=3��֮���������1~n
 * ʣ��n-3*k���������и���һ����
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
const int mod = 1000000007;

int main()
{
    int n,k;
    cin >> n>> k;
    int len;

    if(n/k <= 2)
    {
        cout << -1 << endl;
    }
    else
    {
        for(int i = 1 ; i <= k ; i++)
            cout << i << ' ';
        for(int j = 1 ; j <= k ; j++)
            cout << j << ' ' << j << ' ';
        n-=3*k;
        while(n--)
            cout << 1 << ' ';
    }
    return 0;
}
