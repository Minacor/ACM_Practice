/*
 * ���⣺
 * ����m���صĵ�K����
 *
 * ˼·��
 * �м����ص�
 * 1:�����ǻ���˼�룬��Ŀ��k>m
 *   ����ŷ��������gcd(a,m)=gcd(a+k*m,m),��֪����[1,m],[m+1,m+m]...[(n-1)m+1,nm]����m���ص����ĸ�������ͬ��
 *   ���������ΪPHI
 *   ��������ֻҪ���[1,m]�е���m���ص���������,����ֱ��gcd�ж�������ÿһ����
 *   ���ǽ�������������ֻ����2400+������Ҫ�Ż�
 * 2:�Ż�1��
 *   ����PHI�������и�ģ�����
 *   �ڼ���PHIʱ����ʵ�Ѿ���m���зֽ⣬�����m������������
 *   ���룬������m�����ص�������������m��һ������������
 *   ���ǣ����ǿ�����ÿ���ҵ�һ��m�������Ӻ󣬽�������������ǣ�����������ö�ٵ�ʱ��Ϳ�����O(1)��ʱ���ж���
 *   �������ܵ�300+ms
 * 3:�Ż�2��
 * ��Ϊm <= 1000000 �������sqrt(m)��Ҳ����1000���ڵ������Ϳ����ˣ��������ܵ���ʮms���󹦸��
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

int gcd(int x , int y)
{
    if(y == 0)
        return x;
    return gcd(y,x%y);
}

int p[1000000+100],isp[1000000+100];
int ishuzhi[1000000+100];
int len,pnum;       //PHI,1000������������
int huzhi[1000000+100]; //��ǻ�����

void prime()        //��ȡ1000���ڵ�����
{
    for(int i = 2 ; i <= 1000 ; i++)
        if(!isp[i])
        {
            p[pnum++]=i;
            for(int j = i*2 ; j <= 1000 ; j+=i)
                isp[j]=1;
        }
}

void init(int x)        //��PHIģ��
{
    len=1;
    clr(ishuzhi,0);

    int xx = x;
    for(int i = 0 ; i < pnum ; i++)
    {
        if(xx%p[i]==0)      //�����������m�����ӣ��Ͱ��Ż�1��������m�г�ȥ�������
        {
            len *= p[i]-1;
            xx/=p[i];

            for(int j = p[i] ; j <= x ; j += p[i])
                ishuzhi[j]=1;

            while(xx%p[i]==0)
                xx/=p[i],len*=p[i];
        }
    }
    if(xx > 1)
    {
        len *= xx-1;
        for(int j = xx ; j <= x ; j += xx)
            ishuzhi[j]=1;
    }
    /*for(int i = 1 ; i <= x; i++)      PHIҲ������ô��huzhi�ڴ��滥����,�����Ͳ���д�����getcur��
        if(!ishuzhi[i]) huzhi[len++]=i;*/
}

int getcur(int aim,int x)       //��ô�����ĵ�aim+����
{
    int cnt=0;
    for(int i = 1 ; i <= x ;i++)
    {
        if(!ishuzhi[i]) cnt++;
        if(cnt == aim)  return i;
    }
}

int main()
{
    int a,b;
    prime();

    while(~scanf("%d%d",&a,&b))
    {
        init(a);
        if((b%len)==0)
            printf("%d\n", a*(b/len-1)+getcur(len,a));
        else
            printf("%d\n",a*(b/len)+getcur(b%len,a));
    }

    return 0;
}
