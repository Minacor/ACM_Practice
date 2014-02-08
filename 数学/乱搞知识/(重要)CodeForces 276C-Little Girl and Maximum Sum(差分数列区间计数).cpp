/*
 * ���⣺
 * ��һ������a��һȺѯ�ʣ�ÿһ��ѯ��(l,r)������������ڵ�Ԫ�غ�
 * �����������������ʹ������ѯ�ʵĽ��֮�����
 *
 * ˼·��
 * ��Ȼ��ѯ�ʵ�Խ��ĵ����Խ�������~
 * ����Ҫ���ľ������1~n������λ�õı�ѯ�ʴ�������b[i]��¼
 * Ȼ���С��������a��b���𰸾��ǡ�(a[i]*b[i])
 * Ȼ��Ϊ�˿�������ʱ���ڣ��ò�����м���
 *
 * ��������ܹ���Ч������[l,r]�ڵĵ�+delta��Ȼ��ͨ���ۼӵõ�ÿ����ı���������
 * �����������������Ǹ��ܺõĹ���
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

LL a[MAX],cnt[MAX];
int main()
{
    int n,q;
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    for(int i = 0 ; i < q ; i++)
    {
        int x,y;
        cin >> x >> y;
        cnt[x]++;cnt[y+1]--;    //�������ۼӵ�ʱ�������������+1 -1�����ˣ��ﵽ����Ŀ��
    }
    for(int i = 1 ; i <= n ; i++)
        cnt[i] += cnt[i-1];
    sort(a+1,a+n+1);
    sort(cnt+1,cnt+1+n);
    LL ans=0;
    for(int i = 1 ; i<= n ; i++)
        ans += cnt[i]*a[i];
    cout << ans << endl;
    return 0;
}
