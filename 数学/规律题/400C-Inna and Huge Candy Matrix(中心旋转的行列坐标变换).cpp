/*
 * ����:
 * �и������������ɸ���װ���ǹ������Ͻ�����Ϊ(1,1)��������˳ʱ����ת90��x�Σ��پ���y��Գ�y�Σ�����ʱ����ת90��z��
 * �������֮��ĸ����ǹ�������
 *
 * ˼·��
 * ֱ��ģ����ת
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
const int MAX = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int n,m,x,y,z,p;
int xx,yy;

void shunzhuan(int v)
{
    int x=xx,y=yy;
    //int mm=m,nn=n;
    for(int i = 0 ; i < v ; i++)
    {
        xx=y,yy=n+1-x;
        x=xx,y=yy;
        swap(m,n); //ע��һ����ת֮��m��n�ı���
    }
}

void jingmian(int v)
{
    if(v)
        xx = xx,yy=m+1-yy;
}

void nizhuan(int v)
{
    int x=xx,y=yy;
    //int mm=m,nn=n;
    for(int i = 0 ; i < v ; i++)
    {
        xx= m+1-y, yy=x;
        x=xx,y=yy;
        swap(n,m);
    }
}

int main()
{
    //FR;
    cin >> n>>m>>x>>y>>z>>p;

    x = x%4;
    z = z%4;
    y = y%2;

    for(int i = 0 ; i < p ; i++)
    {
        int tm=m,tn=n;
        cin >> xx >> yy;
        shunzhuan(x);
        jingmian(y);
        nizhuan(z);
        m=tm,n=tn;
        cout << xx << ' ' << yy << endl;;
    }
    return 0;
}
