/*
 * ��һ���ַ���s
 * ����s�������ִ�s[0],s[0,1],s[0...2],...,s[0...n](������ǰ׺��)
 * ������Щ�Ӵ�a����a^n == s ����s = ababab ��a = ab �� ��a^3 == s,n==3
 * �������n
 *
 * ˼·��
 * next���������ʣ�
 * ����S�ĳ���Ϊlen����S����ѭ���Ӵ������ҽ�����len���Ա�len - next[len]���������ѭ���Ӵ�ΪS[len - next[len]]
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

char s[1000000+100];
int next[1000000+100];
int len;

void getnext()
{
    clr(next,0);
    for(int i = 1 ; i <= len ; i++)
    {
        int j = i;
        while(j)
        {
            j = next[j];
            if(s[i] == s[j])
            {
                next[i+1]=j+1;
                break;
            }
        }
    }
}

int main()
{
    while(scanf("%s",s),s[0]!='.')
    {
        len = strlen(s);
        getnext();
        int o = len%(len-next[len]) ? 1 : len/(len-next[len]);
        printf("%d\n",o);
    }
    return 0;
}
