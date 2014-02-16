/*
 * ���⣺
 * ��һ���ַ����������ǰ׺==��׺�����ƥ��ĳ��ȣ���С�������
 *
 * ��չkmp��next��������
 * next[i]��ʾ�Ӵ�s[i...n]��ǰ׺�ܹ�ƥ��ԭ��ǰ׺����󳤶�(������ǰ׺����),ע��next[0]=0
 * ����������==n-i��˵���Ӵ�����ԭ����ǰ׺��������Ӵ������Ǻ�׺�����Է�������
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
const int MAXN = 400000+10;
const int inf = 522133279;
const int mod = 1000000007;

int next[MAXN];

void extendKMP(string a)
{
    stack<int> st;
    st.push(a.size());

    int m = a.size();
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

    for(i = 0 ; i < a.size() ; i++)
        if(a.size()-i==next[i])
            st.push(next[i]);
    cout << st.top();
    st.pop();
    while(!st.empty())
    {
        cout << ' ' << st.top();
        st.pop();
    }
    cout << endl;
}

int main()
{
    string a;
    while(cin >> a)
    {
        clr(next,0);
        extendKMP(a);
    }
    return 0;
}
