/*
 * ���⣺
 * ��һ����,ֻ�ܴ�ͷ����β������ĸ��������Ҫ�Ӷ�����ĸ����ʹ��������ѭ������>1��ѭ������
 * ��abcabcabc��һ��ѭ������ѭ������abc,ѭ������Ϊ3
 *
 * ˼·��
 * �����˽�һ���ر���Ҫ������:
 * ����һ������Ϊlen���ַ���a,��len-next[len]������С�����Ӵ��ĳ���
 * ��С�����Ӵ����Ǿ������ɴθ��ƺ��ܹ�����ԭ����"ԭ�����Ӵ�"
 * ��ô�������������ʵ�Ӧ���ˡ�����С�����Ӵ�s�ĳ���Ϊl�����len%l==0��˵������Ǹ���sΪѭ���ڵ�ѭ����
 * �����������˵���в������ĺ�׺����ʱֻҪ��ȫ��׺�����γ�ѭ������
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

int next[100000+100];
char a[100000+100];
int len;

int getnext()
{
    clr(next,0);
    for(int i = 1 ; i < len ; i++)
    {
        int j = i;
        while(j)
        {
            j=next[j];
            if(a[i] == a[j])
            {
                next[i+1]=j+1;
                break;
            }
        }
    }

    return len-next[len];
}

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(a);
        len = strlen(a);
        int x = getnext();
        int out=0,l=len%x;
        if(l||len==x)
            out=x-l;    //��ȫ��׺
        printf("%d\n",out);
    }
    return 0;
}
