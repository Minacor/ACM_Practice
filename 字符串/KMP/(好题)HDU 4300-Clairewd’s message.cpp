/*
 * 题意：
 * 每组两个字符串
 * 第一个字符串S是一个小写字母表映射,S[i]表示第i个小写字母的密文对应字母
 * 第二个字符串y是密文+明文，密文保证完整，但明文有可能没打完全，甚至没有打
 * 事实上明文长度=密文长度
 * 现在的任务就是补全第二个字符串,补到最短可能长度
 *
 * 思路：
 * 先把第二个字符串按照映射S转换成字符串mir，这样，原本后缀可能的明文就转换成了密文
 * 然后mir的后缀与S的前缀匹配，若能成功匹配，说明这时mir的后缀就是(可能没打全的)明文对应的密文了
 * 设匹配点是pos，那么y之前的就是完整的密文了，我们要做的就是输出完整密文+完整明文
 * 字符串匹配用扩展kmp,注意b的起始匹配点：由题意，y中密文长度>=明文，故应从一半处开始寻找匹配
 * 由于输出的是原文件，所以得用完整密文得到明文,密文->明文的映射用mir2实现
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
