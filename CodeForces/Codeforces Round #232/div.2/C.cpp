/*
 * 题意：
 * 给n个数a1,a2...an,令m=a1*a2*a3*...*an
 * 求将m分解成n个数的乘积共有多少分法，只要对应位置的数不同，就被认为是不同方法
 *
 * 思路：
 * 统计每种素因子的个数，然后对每种素因子的个数cnt，将它分成x1+x2+...+xn=cnt
 * 然后把它们分配到最后的乘积对应的每个数，就构成了一种解
 * 这个解中第i个元素的因式分解式就是(2^xi)*(3^yi)*(5^zi)...
 * 重点就是如何求cnt的分解方法有多少种，即有多少组非负实数解
 * 这里用到插板法，将cnt分成cnt个1，然后往中间的空中插入n-1个+号，就能得到一组解
 * 显然，cnt个1之间有cnt-1个空位，往里面插入n-1个+号，共有C(n-1,cnt-1)种方法，这是插板法的最朴素公式
 * 但是本题是非负解，所以要考虑到0的情况，这时就要小改一下插板法
 * 改法很简单，只需要首先插入n个1，利用插板法求出，最后每个数中减去一个1就行了
 * 这样一共有C(n-1,cnt+n-1)种方法
 * 最后答案就是这些组合数相乘%mod
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

	if(x > 1)       //这步千万不能漏....且由于>sqrt(a)的素数可能会很大，所以要用map计数，数组就会爆了
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
		LL tmp = comb(it->second+n-1,n-1);      //插板法公式
		sum = (sum*tmp)%mod;
	}
	cout << sum << endl;
	return 0;
}
