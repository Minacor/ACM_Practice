/*
 * ���⣺
 * ��n���ַ�������Ϊm���ַ���
 * ��һ�ֲ�����ѡ��������i��j��k ������i���͵�j���ַ�����ǰk���ַ�
 * ���ܹ���ϳ����ٸ��͵�һ���ַ�����ͬ���ַ���
 *
 * ˼·��
 * ���ڲ����ɵ��ӣ����Կ�����ô������
 * ѡ��i��j����һ�ν���k���ڶ��ν���k-1���������൱�ڽ����˵�k���ַ�
 * �ɴ˿�֪�ܹ���ɵ��ַ���������cnt1*cnt2*...*cntn��cnti��ʾ��iλ���ж��ٲ�ͬ���ַ�
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

int n,m;
string g[110];
map<char , int> tongji;

int main()
{
    LL sum=1;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        cin >> g[i];
    for(int i = 0 ; i < m ; i++)
    {
        tongji.clear();
        for(int j = 0 ; j < n ; j++)
            tongji[g[j][i]]++;
        sum = (sum*tongji.size())%1000000007;
    }
    cout << sum%1000000007 << endl;
    return 0;
}
