/*
 * ���⣺
 * ��ð������һ�����б��������Ҫ����ans��
 * �������⽻��һ����(���Բ�����)���õ�һ���µ����к�һ���µ�ans
 * ����С��ans �Ϳ��Եõ����ans�Ľ�����(i,j)������
 *
 * ˼·��
 * �ȵõ�ԭ���е�ans����������״�������
 * Ȼ������һ��dp���飬dp[i][j]��ʾmin(i,j)~max(i,j)�б�jС�����ĸ���
 *
 * ��Ϊ�����������Ժ�ԭ�����������м������������ı�������򣬷�֮��Ȼ�����Ժܺ��Ƴ���ʽ
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
const int MAX = 100000+100;
const int inf = 522133279;

int n;
int a[5100];
int tree[5100];
int dp[5100][5100];

int getsum(int pos)
{
    int t=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        t += tree[pos];
    return t;
}

void modify(int pos , int delta)
{
    for( ; pos <= n ; pos += lowbit(pos))
        tree[pos] += delta;
}

map< int , int > out;

int main()
{
    FR;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        a[i]++;
    }

    for(int i = 1 ; i <= n ; i++)
    {
        dp[i][i]=0;
        for(int j = i-1 ; j >= 1 ; j--)
            dp[j][i] = dp[j+1][i] + (a[j]<a[i]);
        for(int j = i+1 ; j <= n ; j++)
            dp[j][i] = dp[j-1][i] + (a[j]<a[i]);
    }

    int ans=0;
    for(int k = 1 ; k <= n ; k++)
    {
        ans += getsum(n)-getsum(a[k]);
        modify(a[k],1);
    }

    for(int i = 1 ; i <= n ; i++)
        for(int j = i+1 ; j <= n ; j++)
        {
            if(a[i] > a[j])
            {
                int tmp = (ans - 2*dp[j-1][i] + 2*dp[i+1][j])-1;    //�����Ĺ�ʽ�����ͷβ�������м����������ϵ���������Ҫ����ͷβ�����������������1�������-1
                out[tmp]++;
            }
        }

    map<int , int> :: iterator it = out.begin();
    cout << it->first << ' ' << it -> second << endl;

    return 0;
}
