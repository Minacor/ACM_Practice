/*
 * ���⣺
 * ����������Ϸ����һ��n���ɿ���(һ������),�д��ұ߳Ե���ߣ�Ů������
 * ÿ�����ִ�������ɿ�������ʱ�䣬һ���˲���ͬʱ�������ɿ������ұ������һ��֮����ܳ���һ��
 * ������˽�Ҫͬʱ��ʼ��һ���ɿ���������Ů��
 * ��� cout << Ů�Ե��ɿ������� << ' ' << �п���
 *
 * ˼·��
 * ���͵Ĳ��ģ�ƽ�ⲩ�ģ���һ��balance��ʾ��ƽ
 * balance > 0��ʾ�з�����һ���ɿ���ʱŮ�����ڳԣ���֮ͬ��,=0��ʾ���˽�ͬʱ����һ�飬������ô�ʱ��ֻʣһ��������Ů
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

int a[100000+100];
int n;

int main()
{
    cin >> n;
    int sum=0;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    int l=0,r=n-1,balance=0;
    int cnt1=0;
    while(l <= r)
    {
        if(balance > 0)
            balance-=a[r--];
        else
            balance+=a[l++];
    }
    cout << l << ' ' << n-l << endl;
    return 0;
}
