/*
 * ���⣺
 * ������N����ĸ��ɵ����������硾abcdef��ÿһλ��ĸ������ת����ת������ĸʱ�������������һ����ĸ��
 * �确a'ת������b,xת������y,
 * ���Ÿ���M�����䣬ÿ��ת�����������ڵ�������ĸ��
 * ����������abcdef�����������䡾1,3��ת���������һ�κ��Ϊ��bcddef��
 * ���һ������������ת���ܱ����һ��������������������Ϊ����ͬ��
 * ���ж��ٲ�ͬ����
 *
 * ˼·��
 * ���û�������ʱ�������26^n��ÿ����һ������(���۳��Ⱥ�λ��)�������Ҫ��ȥ26�������26^(n-1)��
 * ��Ϊ����һ�����䣬���λ�ò�������������һ��
 * ����Ҫע�⣬�������������[1,2],[3,6],��ô������[1,6]ʱ��Ӧ�����������䣬��Ϊ�ܹ�ͨ��ǰ������ϳɵ�����
 * ����[1,2],[2,6]����Ӧ�ð�[1,6]����������
 * ���ǲ��鼯�����þ��ǣ��жϵ�ǰ�����ܷ�֮ǰ��������ϳ���
 * ���������ǣ�ÿ������һ���µ����䣬�ͺϲ�[l,r+1]��ͬʱn-=1
 * �������n�����ر����Ҫ��������
 */

//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define mkp make_pair
using namespace std;
typedef long long LL;
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int t;
int f[10000000+100];
int n,m;

int find(int x)
{
    return x==f[x]?x:f[x]=find(f[x]);
}

int merger(int x , int y)
{
    x = find(x);
    y = find(y);

    if(x!=y)
    {
        f[x]=y;
        return 1;
    }
    return 0;
}

LL mi(int n)            //�������ݵ�����
{
    LL ans=1,tmp=26;
    while(n)
    {
        if(n&1)
            ans=(ans*tmp)%mod;
        tmp = (tmp*tmp)%mod;
        n/=2;
    }
    return ans%mod;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i = 0 ; i <= n+1 ;  i++)        //��ʼ��ע�⣡������r+1������������n+1����
            f[i]=i;
        for(int i = 0 ; i < m ; i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            n-=merger(l,r+1);
        }
        printf("%I64d\n",mi(n));
    }
    return 0;
}
