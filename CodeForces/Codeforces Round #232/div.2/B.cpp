/*
 * ���⣺
 * ��n,l,r ���ܷ��l~r��ȡ��������ʹ�üӺ�Ϊn��ÿ��������������ȡ
 *
 * ˼·��
 * ����ȡk�ξ�����������
 * ��ôӦ����l*k <= n <= r*k
 * �� n/l >= n/r ,ע�����������ֵ����ʵ��
 * �����Ļ�����ֻ��ȡ>
 * ���ڵ�����£�ֻ��n��l��r����
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

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int x,a,b;
        cin >> x >> a >> b;
        int ok=0;
        if(x/a>x/b||x%b==0||x%a==0)ok=1;
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}
