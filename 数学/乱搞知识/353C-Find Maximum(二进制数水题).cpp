/*
 * ���⣺
 * ��n�������ٸ�һ��nλ��������m(ע��������Ƿ��ģ�������ߵ������λ)
 * sum���󷨣����ݶ�����������λ�����iλ��1�ͼ���a[i],0�Ͳ���
 * ��0~m�еĶ����������������
 *
 * ˼·��
 * ̰�ĺ����ԣ����ڶ������������ʣ�10000>01111Ҳ����˵�ѵ�ǰλ��1��Ϊ0���ѽϵ�λȫ��Ϊ1��������һ����ԭ��С
 * ����ö��m��ÿһλ���������1�Ͱ�����ʱ��0������������нϵ�λ��a[i]
 * ֱ�Ӽӻᳬʱ��֮ǰ����һ�����Ԥ����
 * ����a��m���Ƿ��Ÿ����ģ�����ö�ٵ�ʱ��ҲҪ�Ӻ���ǰö��
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

int a[100000+100];
int sum[100000+100];
int n;

int getsum(int pos)
{
    int ans=0;
    for( ; pos < n ; pos++)
        ans += a[pos];
    return ans;
}

int main()
{
    string s;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        if(i)
            sum[i] = sum[i-1]+a[i];
        else sum[i]=a[i];
    }
    cin >> s;
//    reverse(a,a+n);
//    reverse(s.begin(),s.end());

    int maxc=0,tmp=0;
    for(int i = s.size()-1 ; i >= 0 ; i--)
    {
        if(s[i] == '1')
        {
            maxc = max(tmp+sum[i]-a[i],maxc);
            tmp += a[i];
        }
    }
    cout << max(maxc,tmp) << endl;
    return 0;
}
