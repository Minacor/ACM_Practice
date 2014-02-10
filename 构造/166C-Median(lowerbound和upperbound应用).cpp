/*
 * ���⣺
 * ����һ��n��Ԫ�ص����к�һ����x���ж�����Ҫ���Ӽ�����ʹ�������Ժ��x�������м�
 * �м�Ķ��壺(n+1)/2����ȡ��
 *
 * ˼·��
 * �����ж�x�Ƿ���ԭ�����У���������룬�ǳ���Ҫ��һ������ʹ�������
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

int l,r;
int a[1000];
int n,x;

int main()
{
    cin >> n >> x;
    int ans=1;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        if(a[i]==x)
            ans=0;
    }
    if(ans)     //������ھͼ���
        a[++n]=x;
    sort(a+1,a+n+1);

    //l:��һ�γ���x��λ��;r:���һ��x��λ��
    l = lower_bound(a+1,a+1+n,x)-a; //lower_bound,����һ����������ָ���һ��>=x��Ԫ��
    r = upper_bound(a+1,a+1+n,x)-a-1;//upper_bound������һ����������ָ���һ��>x��Ԫ��

    // 1 2 3 4 5 6 7
    int mid = (n+1)/2;
    if(l <= mid && mid <= r)        //x���������м�
        cout << ans << endl;
    else if(l > mid)                //��һ��x�������м��ұߣ���Ҫ����Ԫ�ظ�������l��ߵ�-l�ұߵģ�������±��뽫���в���������
        cout << (l-1)-(n-l)+ans << endl;
    else if(r < mid)                //���һ��x�������м���ߣ����Ʋ�����Ҫע����ǽ����в��㵽ż�������Ϳ�����
        cout << (n-r)-r+ans << endl;
    return 0;
}
