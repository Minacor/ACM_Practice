/*
 * ���⣺
 * �����һ�и�һ����n����ʾ��n����
 * ������n�У�ÿһ�п�ͷһ����k����ʾ�������k���ƣ������ҷֱ����ƶѵ�top��bottom
 * ��������k������ʾÿ���Ƶ���ֵ
 * ������������a,bҪȡ�ƣ�aֻ���ÿ���Ƶ�topȡ��bֻ���bottomȡ
 * ���˶������ž���
 * ��������˸��Ի�õĵ���
 *
 * ˼·��
 * ����ÿһ���ƣ����������������ţ��Ͱ��м����Ŵ浽����mid���ݲ�����
 * Ȼ��ÿ���Ƴ��м����⣬��ߵ���һ����a�ģ��ұߵ���һ����b��
 * ��Ϊ���˶������ž��ߣ����a�ܹ�Խ���м���ȡ���ұߵ���x��˵����x�㹻�ţ�b���������������ƣ�����a�õ�������Խ�粻�ᷢ��
 * ����Ԥ�Ȱ������ƶѵ�����Ƽӵ�a���ұ��Ƽӵ�b��Ȼ������м��Ƶļ���mid��
 * ����a���ã���aһ����ȡmid�����ģ�Ȼ��b��ʣ�µ�����....���Խ�mid�����Ժ󽻴�ӵ�a��b�Ϳ�����
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

int mid[110];
int midcnt;
int n,k;
int a[110];
int l,r;
int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> k;
        for(int j = 1 ; j <= k ; j++)
            cin >> a[j];
        if(k&1) mid[midcnt++] = a[(k+1)>>1];
        for(int i = 1 ; 2*i <= k ; i++)
            l += a[i] , r += a[k-i+1];
    }
    sort(mid,mid+midcnt);
    bool cur=0;
    for(int i = midcnt-1 ; i>=0 ; i--)
    {
        if(!cur) l+=mid[i];
        else r += mid[i];
        cur=!cur;
    }
    cout << l <<' ' << r << endl;
    return 0;
}
