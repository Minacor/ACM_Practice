/*
 * ���⣺
 * ��һ��һ������4^n ����Ҫ����һ��2^n * 2^n������
 * ������4^n������Ҫ�����������
 * һ�������������1*1�ģ���ôΨһ��һ�������Ǵ�
 * �����2^i * 2^i�ģ���ô�ҵ������е����ֵ������������ֵ
 * Ȼ����������ֳ��ĸ�2^(i-1) * 2^(i-1)�����󣬼��������������ж�
 * ��������Դﵽ�Ĵ�
 *
 * ˼·��
 * ��������ͼ�����׿�������������������n�Σ�������ǰ3�����������n-1�Σ�����
 * ����ֻҪ�������Ÿ������μ���Ϳ�����
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

LL a[2000000+100];

LL pow(int n)
{
    if(n==-1)
        return 0;
    LL ans=1;
    for(int i = 1 ; i <= n ; i++)
        ans *= 4;
    return ans;
}

int main()
{
    int n=0;
    LL num;
    cin >> num;
    while(pow(n) != num) n++;

    for(int i = 0 ; i < num ; i++)
        cin >> a[i];

    sort(a,a+num);

    LL pos = num-1;
    LL ans=0;
    LL x=0;

    while(pos >= 0)
    {
        LL up = pow(x)-pow(x-1);
        for( ; up>0 && pos>=0  ; pos--,up--)
            ans += a[pos]*(n+1-x);
        x++;
    }
    cout << ans << endl;

    return 0;
}
