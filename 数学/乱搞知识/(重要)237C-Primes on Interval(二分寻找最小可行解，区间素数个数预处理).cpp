/*
 * ���⣺
 * ����������a��b��k
 * ����С��lʹ������[a,b]�����г���Ϊl�������������ٰ���k������
 *
 * ˼·��
 * ��Ԥ���������[1,n]�������ĸ�����Ȼ�������l
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

int a,b,k;
int p[1000000+100];

void init()     //Ԥ���������[1,n]�������ĸ���
{
    for(int i = 2 ; i <= 1000000 ; i++)
        if(!p[i])
            for(int j = i+i ; j <= 1000000 ; j+=i)
                p[j]=1;

    for(int i = 2 ; i <= 1000000 ; i++)
        p[i] = p[i-1] + !p[i];
}

int main()
{
    cin >> a >> b >> k;
    init();

    int l = 1 , r = b-a+1;

    do
    {
        int mid = MID(l,r);
        int ok=1;
        for(int i = a ; i <= b-mid+1 ; i++)
            if(p[i+mid-1]-p[i-1] < k)   //ע�������Ҷ���i+l-1 ����©��-1 debug�˺ܳ�ʱ��
            {
                ok=0;
                break;
            }
        if(ok)
            r = mid-1;
        else
            l = mid+1;

    }while(l <= r);

    if(l > b-a+1) l=-1;
    cout << l << endl;
    return 0;
}
