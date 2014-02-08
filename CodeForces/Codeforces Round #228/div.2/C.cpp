/*
 * ���⣺
 * ÿ��������һ��ֵx����ʾ�����Ϸ��������x�����ӣ����ɸ����ӵ���һ�н���"һ��"
 * �����ٿ��԰ڼ���
 *
 * ˼·��
 * ��С�Ŀ�ʼ�ã����˵�����ѹ��һ��vector�У������ǰvector��sizeС�ڵ��������жϵ����ӵ�x������x���Է������ڵ�����£��ͼ���
 * ֱ�����ܼ���Ϊֹ������vector���ظ�����ֱ���������ӱ�����
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

int a[110];
int cnt[110];
vector<int> cur;

int main()
{
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    sort(a,a+n);

    int ans=0;
    int ok=1;
    while(ok)
    {
        ok=0;
        cur.clear();
        for(int i = 0 ; i < n ; i++)
            if(a[i] != -1)
            {
                if(a[i] >= cur.size())
                    cur.push_back(a[i]),a[i]=-1;
                ok=1;
            }
        ans++;
    }
    cout << ans-1 << endl;
    return 0;
}
