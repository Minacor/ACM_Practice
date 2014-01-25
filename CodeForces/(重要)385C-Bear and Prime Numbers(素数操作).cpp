/*
 * ���⣺
 * ��һ�����У�����f(p) = ����������ܱ�p���������ĸ���
 * ��һ��ѯ�ʣ���pȡ��l,r��ÿһ���������õ�һ��f(p),���f(p)�ĺ�
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
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;
const int inf = 1e15;

int p[10000005],a[10000005];
int main()
{
    //FR;
    for(int i = 2 ; i < 10000005 ; i++)     //p[i] = x != 0 , ��ʾi�ܱ�����x����
        if(!p[i])
        {
            p[i]=i;
            for(int j = 2 ; j*i < 10000005 ; j++)
                p[j*i]=i;
        }

    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        int x;
        cin >> x;
        int tmp=0;

        while(x > 1)        //a[i]��ʾ�ܱ�i���������������ֵĸ���
        {
            a[p[x]] += tmp != p[x]; //tmp��Ŀ���Ƿ�ֹ�ظ�����������xһ���ǵݼ��ģ����Բ��ùܺ�ǰ�����
            tmp = p[x];
            x/=p[x];
        }
    }

    for(int i = 1 ; i < 10000005 ; i++)     //����a[i]��ʾ�������ܱ�1~i�е��������������ָ���
        a[i] += a[i-1];

    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        r = min(r,10000004);
        l = min(l,r);
        cout << a[r]-a[l-1] << endl;
    }
    return 0;
}



//������

int p[10000005],has[10000005],a[10000005];
int main()
{
    FR;
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        int tmp;
        cin >> tmp;
        has[tmp]++;
    }

    for(int i = 2 ; i < 10000005 ; i++)
        if(!p[i])
            for(int j = i ; j < 10000005 ; j+=i)
            {
                if(has[j]) a[i]+=has[j];    //ֱ�Ӽ���������Ҫע���ظ�����
                p[j]=1;
            }

    for(int i = 1 ; i < 10000005 ; i++)
        a[i]+=a[i-1];

    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        r = min(r,10000000);
        l = min(l,r);

        cout << a[r]-a[l-1] << endl;
    }
}
