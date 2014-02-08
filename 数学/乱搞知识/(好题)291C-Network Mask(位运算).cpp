/*
 * ���⣺
 * ��n��IP��ַ(IP address)
 * ��֪�ܹ�����������(subnet mask)��������ַ(network address)
 * ���������������32λ����������IP��ַ����������
 * ����������һ����111...100...0��������ʽ���������01���ģ�1ռ�ݸ�λ
 * ������������������룬ʹ������n��IP���������ܹ��õ�ǡ��m����ͬ�������ַ
 * ����ж��ֽ�����������1���ٵ�
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

unsigned int g[100000+100];
map<int,int> cnt;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i = 0 ; i < n ; i++)
    {
        int a,b,c,d;
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        g[i] = (a << 24) | (b << 16) | (c << 8) | d;
    }

    unsigned int ok=0;
    for(unsigned int op = 0xFFFFFFFFu ; op ; op <<= 1)  //һ��F����4��1��ע���������op��LL�Ļ������Ʋ��������������λ��1�����´���
    {
        for(int i = 0 ; i < n ; i++)
        {
            int tmp = op&g[i];
            ++cnt[tmp];
        }

        if(m == cnt.size())
            ok=op;

        cnt.clear();
    }

    if(!ok) puts("-1");
    else
    {
        unsigned int a,b,c,d;
        a=(ok>>24)&255,b=(ok>>16)&255,c=(ok>>8)&255,d=ok&255;
        printf("%u.%u.%u.%u\n",a,b,c,d);
    }
    return 0;
}
