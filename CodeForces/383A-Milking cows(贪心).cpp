/*
 * ���⣺��nͷţ�ų�һ�У�0��ʾ����1��ʾ���ҿ���ÿһͷţ�ܿ�������Է��������ţ
 * ���ڶ�ţ���̣�ÿ��һͷţ���ܿ�������ţ������Ϊ���Ŷ��ٲ�һ���̣������̵Ĳ��ټ���
 *
 * ����������˳��ѡ���ʹ����������С�������С��ʧ����
 *
 * ˼·���ȼ�¼0�ĸ�����1�ĸ���������ţ�پ��ȼ�����ţ������֮��ʣ�µ�ţ����һ�����򣬲������м���
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
const int INF = 0xfffffff;

int n;
int a[200000+100];

int main()
{
    int num0=0 , num1=0;
    int tmp;

    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        num0 += !a[i];
        num1 += a[i];
    }

    LL ans=0;

    if(num0 > num1)
    {
        for(int i = 0 ; i < n ; i++)
        {
            if(!a[i]) num0--;
            else ans += num0;
        }
    }
    else
    {
        for(int i = n-1 ; i >= 0; i--)
        {
            if(a[i]) num1--;
            else ans += num1;
        }
    }

    cout << ans << endl;
    return 0;

}
