/*
 * ���⣺
 * ������һ��������������t
 * Ȼ��ÿ��������n p ��Ҫ����������ͼ��
 * 1 ĸͼǡ����2n+p����
 * 2 û���Ի����ر�
 * 3 �������ⶥ����Ϊk(1<=k<=n)����ͼ������� <= 2k+p
 * �������2n+p���ߵ������˵�
 *
 * ˼·��
 * ��ſ�ܣ�
 * ����ͼk=2��ʼ���죬�ܹ�������ȫͼ�ľ͹�����ȫͼ
 * ֱ�����ܹ�����ȫͼ�Ժ�ÿ�����м�һ����x���ͼӱ�(1,x),(2,x)...(x-1,x)���ӵ��������mk <= min( k(k-1)/2 , 2k+p) Ϊֹ
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

int n,p;
int mir[30];

map< pair<int,int> , int> out;

int main()
{
    int t;
    for(int i = 5 ; i <= 24 ; i++)
        mir[i] = (i*i-5*i)/2;       //��������Ϊiʱ����p < mir[i]ʱ�Ͳ��ܹ�����ȫͼ�ˣ�ֻ�ܹ������Ϊk*(k-1)/2 - (mir[k]-p)��ͼ

    cin >> t;
    while(t--)
    {
        out.clear();
        cin >> n >> p;

        for(int x = 1 ; x <= 5 ; x++)
            for(int y = x+1 ; y <= 5 ; y++)
                out[mkp(x,y)]++;

        for(int k = 6 ; k <= n ; k++)
        {
            int full = k*(k-1)/2 - (mir[k]-p);

            for(int x = 1 ; x < k ; x++)
                if(out.size() < full)
                    out[mkp(x,k)]++;
            if(out.size() == 2*n+p)
                break;
        }

        map< pair<int,int> , int> ::iterator it = out.begin();
        for( ; it != out.end() ; it++)
            cout << (it->first).first << ' ' << (it->first).second << endl;
    }

    return 0;
}
