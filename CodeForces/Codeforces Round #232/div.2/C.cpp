/*
 * ���⣺
 * ��n����a1,a2...an,��m=a1*a2*a3*...*an
 * ��m�ֽ��n�����ĳ˻����ж��ٷַ���ֻҪ��Ӧλ�õ�����ͬ���ͱ���Ϊ�ǲ�ͬ����
 *
 * ˼·��
 * ͳ��ÿ�������ӵĸ�����Ȼ���ÿ�������ӵĸ���cnt�������ֳ�x1+x2+...+xn=cnt
 * Ȼ������Ƿ��䵽���ĳ˻���Ӧ��ÿ�������͹�����һ�ֽ�
 * ������е�i��Ԫ�ص���ʽ�ֽ�ʽ����(2^xi)*(3^yi)*(5^zi)...
 * �ص���������cnt�ķֽⷽ���ж����֣����ж�����Ǹ�ʵ����
 * �����õ���巨����cnt�ֳ�cnt��1��Ȼ�����м�Ŀ��в���n-1��+�ţ����ܵõ�һ���
 * ��Ȼ��cnt��1֮����cnt-1����λ�����������n-1��+�ţ�����C(n-1,cnt-1)�ַ��������ǲ�巨�������ع�ʽ
 * ���Ǳ����ǷǸ��⣬����Ҫ���ǵ�0���������ʱ��ҪС��һ�²�巨
 * �ķ��ܼ򵥣�ֻ��Ҫ���Ȳ���n��1�����ò�巨��������ÿ�����м�ȥһ��1������
 * ����һ����C(n-1,cnt+n-1)�ַ���
 * ���𰸾�����Щ��������%mod
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
//const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

long long C[20000][505];

long long comb(int a,int b){
   if(C[a][b])
      return C[a][b];
   if(a == b || b==0)
      return 1;
   return C[a][b]=(comb(a-1,b)+comb(a-1,b-1))%mod;
}

int pp[100010];
map<int , int> cnt;
vector<int> p;

void init()
{
	for(int i = 2 ; i <= 100000 ; i++)
		if(!pp[i])
		{
			p.push_back(i);
			for(int j = i+i ; j<=100000 ; j+=i)
				pp[j]=1;
		}
}

void doit(LL x)
{

	for(int i= 0 ; i < p.size() ; i++)
	{
		if(x%p[i]==0)
		{
			while(x%p[i]==0)
			{
				cnt[p[i]]++;
				x/=p[i];
			}

		}
	}

	if(x > 1)       //�ⲽǧ����©....������>sqrt(a)���������ܻ�ܴ�����Ҫ��map����������ͻᱬ��
        cnt[x]++;
}

int main()
{
	int n;
	cin >> n;
	init();

	for(int i  =0 ;i < n  ;i++)
	{
		LL a;
		cin >> a;
		doit(a);
	}

	LL sum=1;

	for(map<int,int>::iterator it = cnt.begin() ; it!=cnt.end() ; it++)
	{
		LL tmp = comb(it->second+n-1,n-1);      //��巨��ʽ
		sum = (sum*tmp)%mod;
	}
	cout << sum << endl;
	return 0;
}
