/*
 * 题意：
 * 给一个序列，定义f(p) = 这个序列中能被p整除的数的个数
 * 给一组询问，令p取遍l,r中每一个素数，得到一堆f(p),输出f(p)的和
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
    for(int i = 2 ; i < 10000005 ; i++)     //p[i] = x != 0 , 表示i能被素数x整除
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

        while(x > 1)        //a[i]表示能被i整除的序列中数字的个数
        {
            a[p[x]] += tmp != p[x]; //tmp的目的是防止重复计数，由于x一定是递减的，所以不用管很前面的数
            tmp = p[x];
            x/=p[x];
        }
    }

    for(int i = 1 ; i < 10000005 ; i++)     //现在a[i]表示序列中能被1~i中的素数整除的数字个数
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



//做法二

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
                if(has[j]) a[i]+=has[j];    //直接计数，不过要注意重复的数
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
