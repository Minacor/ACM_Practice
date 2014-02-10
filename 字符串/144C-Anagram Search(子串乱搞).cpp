/*
 * ���⣺
 * ����Anagram:���a�ܹ�������ĸ���ŵõ�b�����aΪb��Anagram
 * �ָ�һ���ַ���a�����а�����'?'�ܹ����κ�Сд��ĸ����
 * ��һ���ַ���b����a����b��Anagram���Ӵ���
 * ��ͬλ�þ��㲻ͬ�Ӵ�
 *
 * ˼·��
 * ������b�ĳ��ȴ���a�϶�����
 * ��cnt���浱ǰ�ж��ִ�����ĸ�����ͣ�mir����b����ĸ������
 * ��a��ͷ��ʼö�ٳ���Ϊb.size()���Ӵ�
 * �����Ӵ���b�ĳ�����ͬ��ֻҪcnt[i] <= mir[i]�ͱض�����?����ȫi��ĸ
 * ��������������ĸcnt[i] <= mir[i]���Ӵ��ͷ�������
 * ��Ȼcnt���鲻��ÿ�ζ�������¼��㣬ֻҪ���Ƴ�����ĸ��1���ƽ�������ĸ��1������
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

string a,b;
int cnt[150],mir[150];

int can()
{
    for(int i = 'a' ; i <= 'z' ; i++)
        if(cnt[i] > mir[i])
            return 0;
    return 1;
}

int main()
{
    cin >> a >> b;

    if(a.size() < b.size())
    {
        cout << 0 << endl;
        return 0;
    }

    for(int i = 0 ; i < b.size() ; i++)
    {
        mir[b[i]]++;
        if(isalpha(a[i])) cnt[a[i]]++;
    }

    int ans = can();
    for(int i = 1 ; i+b.size()-1<a.size() ; i++)
    {
        if(isalpha(a[i-1])) cnt[a[i-1]]--;
        if(isalpha(a[i+b.size()-1])) cnt[a[i+b.size()-1]]++;
        ans += can();
    }

    cout << ans;
    return 0;
}