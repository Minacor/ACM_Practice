/*
 * ���⣺
 * ��һ��01����0��ʾ���ǹ�1��ʾû�У���w��ѯ�ʺ�һ��kֵ
 * ����positive����ÿһ��ѯ��l��r������l-1+k,l-1+2k,...,rλ����1������λ����0ʱ��Ϊpositive
 * ����"һ�β���"��������һ���������ó��ǻ��߷Ž���
 * ��ÿһ��ѯ�ʣ����ʹ�������positive�����ٲ�����
 *
 * ˼·��
 * ����ע����һ�ε�ѯ�ʲ���Ӱ����һ�Σ���Ҳ����˵����һ�Σ��Ǿ�ȫ����ԭ��
 * ����k�������Ƕ�k�����(0~k)Ԥ����
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
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int dp[15][100000+100];
int cha[100000+100];

int main()
{
    int n,k,w;
    string line;

    cin >> n >> k >> w;
    cin >> line;

    for(int i = 0 ; i < k ; i++)    //i��ʾ��i+1λ�ÿ�ʼ����
    {
        for(int j = i+1 ; j <= n ; j++)     //ע�⿪ʼλ�õİ��ţ�ÿ��������ͷλ����Ҫ��0��
        {
            dp[i][j] = dp[i][j-1];
            if((j-i)%k && line[j-1]=='1') dp[i][j]++;
            if((j-i)%k==0 && line[j-1]=='0') dp[i][j]++;
        }
    }

    for(int i = 0 ; i < w ; i++)
    {
        int l,r;
        cin >> l >>r;
        int st = (l-1)%k;
        cout << dp[st][r]-dp[st][l-1] << endl;
    }
    return 0;
}
