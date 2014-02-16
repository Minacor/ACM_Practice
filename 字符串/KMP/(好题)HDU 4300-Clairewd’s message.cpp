/*
 * ���⣺
 * ÿ�������ַ���
 * ��һ���ַ���S��һ��Сд��ĸ��ӳ��,S[i]��ʾ��i��Сд��ĸ�����Ķ�Ӧ��ĸ
 * �ڶ����ַ���y������+���ģ����ı�֤�������������п���û����ȫ������û�д�
 * ��ʵ�����ĳ���=���ĳ���
 * ���ڵ�������ǲ�ȫ�ڶ����ַ���,������̿��ܳ���
 *
 * ˼·��
 * �Ȱѵڶ����ַ�������ӳ��Sת�����ַ���mir��������ԭ����׺���ܵ����ľ�ת����������
 * Ȼ��mir�ĺ�׺��S��ǰ׺ƥ�䣬���ܳɹ�ƥ�䣬˵����ʱmir�ĺ�׺����(����û��ȫ��)���Ķ�Ӧ��������
 * ��ƥ�����pos����ôy֮ǰ�ľ��������������ˣ�����Ҫ���ľ��������������+��������
 * �ַ���ƥ������չkmp,ע��b����ʼƥ��㣺�����⣬y�����ĳ���>=���ģ���Ӧ��һ�봦��ʼѰ��ƥ��
 * �����������ԭ�ļ������Ե����������ĵõ�����,����->���ĵ�ӳ����mir2ʵ��
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

int next[MAXN],ret[MAXN];
char mir2[150];

int extendKMP(string a , string b)
{
    clr(next,0);
    clr(ret,0);
    int m = a.size() , n = b.size();
    int i,j,k;
    for(i = 0 ; i < m-1 && a[i] == a[i+1]; i++);
    next[1]=i;

    k = 1;

    for(i = 2 ; i < m ; i++)
    {
        int len = k+next[k] , L = next[i-k];
        if(L < len-i)
            next[i]=L;
        else
        {
            for(j = max(0,len-i) ; i+j < m && a[j] == a[i+j] ;j++);
            next[i]=j;
            k=i;
        }
    }

    for( j = 0 ; j < n && j < m && a[j] == b[j] ; j++) ;
    ret[0]=j;
    k=0;
    for( i = 1 ; i < n ; i++)
    {
        int len = k+ret[k],L = next[i-k];
        if(L<len-i)
            ret[i]=L;
        else
        {
            for( j = max(0,len-i) ; j < m && i+j<n && a[j] == b[i+j];j++);
            ret[i]=j;
            k=i;
        }
    }

    for(int i = (b.size()+1)/2 ; i < b.size() ; i++)
        if(ret[i] == b.size()-i)
            return i;
    return b.size();
}

int main()
{
   // FR;
    int t;
    cin >> t;
    while(t--)
    {
        string x,y;
        cin >> x >> y;

        for(int i = 0 ; i < x.size() ; i++)
            mir2[x[i]] = i+'a';
        string mir = y;
        for(int i = 0 ; i < mir.size() ; i++)
            mir[i] = x[mir[i]-'a'];

        int pos = extendKMP(y,mir);

        string l = y.substr(0,pos);

        for(int i = 0 ; i < pos ; i++)
            l += mir2[l[i]];
        cout << l << endl;
    }
    return 0;
}
