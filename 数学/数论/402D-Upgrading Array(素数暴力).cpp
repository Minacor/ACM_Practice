/*
 * ���⣺
 * ��������n��m
 * ��n��������ʾa����
 * ��m����������Щ��������"bad prime"����������m������������"good prime"
 *
 * ������a����һ��beautyֵ��beauty = ��f(a[i]),f(x)�ļ��㷽�����£�
 * f(1)=0;
 * ����p���ܹ�����s����С��������f(s) = f(s/p) +(p is bad prime ? -1 : 1)
 *
 * Ȼ��Ҳ���Զ�a������������Ĳ�����
 * ѡ��a�����ǰr��Ԫ����gcd��Ȼ����r����ȫ�� /= gcd�����������ޣ�����Ϊ0
 * ������ܵõ�������beauty
 *
 * ˼·��
 * ��������׿��� f(x) = x��������������good prime������ - x��������������bad prime������
 * ��ô˼·����ȷ����Ҫͨ������aʹ�þ����ܵ��ų����bad prime
 * ����Ԥ�����ǰr������gcd�������������У���Ϊgcd[r]
 * �����ƶ�һ�����last=1��������¼�������ȥ���Ǹ�gcdֵ��Ȼ������ö��ÿ��gcd��
 * ���f(gcd/last) <= 0 ˵��x=gcd/last������л����������ʹ����ֵ��С������Ҫ��ǰr������ȥ���gcd
 * ��֮�򲻳�ȥ
 * Ȼ��f(int x)������ȫ������ģ�������ɸѡ��������
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
#define FO (freopen("out.txt","w",stdout))
#define clr(a,b) memset(a,b,sizeof(a))
#define mkp make_pair
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 1000000;
const int inf = 522133279;
const int mod = 1000000007;

int n,m;
map<int ,int> bad;
int a[5010],gcd[5010];

int g(int x , int y)
{
    if(y==0)return x;
    return g(y,x%y);
}

int f(int x , int lastprime)
{
    int res=0;
    if(x == 1)
        return 0;

    for(int i = lastprime ; i*i <= x ; i++)
        if(x%i==0)
        {
            if(bad[i]) res += f(x/i,i)-1;
            else res += f(x/i,i)+1;
            return res;
        }
    return bad[x] ? -1 : 1;
}

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    gcd[1]=a[1];
    for(int i = 2 ; i <= n ; i++)
        gcd[i] = g(gcd[i-1],a[i]);

    for(int i = 0 ; i < m ; i++)
    {
        int tmp;
        cin >> tmp;
        bad[tmp]++;
    }

    int ans=0;
    int last=1;
    for(int i = n ; i >= 1 ; i--)
    {
        int ok = f(gcd[i]/last,2);
        if(ok <= 0)
        {
            last = gcd[i];
            ans += f(a[i]/last,2);
        }
        else
            ans += f(a[i]/last,2);
    }
    cout << ans << endl;
    return 0;
}
