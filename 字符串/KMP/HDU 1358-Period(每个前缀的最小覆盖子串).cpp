/*
 * ���⣺
 * ��һ���ַ���a
 * ����a��ÿһ�����ȴ���1��ǰ׺s,�������ѭ����������1��ѭ���������s�ĳ��Ⱥ����ѭ������
 *
 * ˼·��
 * kmpѰ��ÿ��ǰ׺����С�����Ӵ�,�������Ӵ�ǡ����ѭ�������Ӵ�!=ǰ׺�������
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

char a[1000000+100];
int next[1000000+100];
int n;

void getnext()
{
    clr(next,0);
    for(int i = 1 ; i < n ; i++)
    {
        int j=i;
        while(j)
        {
            j=next[j];
            if(a[i]==a[j])
            {
                next[i+1]=j+1;
                break;
            }
        }

        int tmp = i+1-next[i+1];
        if( tmp != i+1&& (i+1)%tmp==0)  //(i+1)%tmp==0��ʾ�޶����׺����ǰ׺Ϊѭ����
            cout << i+1 << ' ' << (i+1)/tmp<<endl;
    }
}

int main()
{
    int ka=1;
    while(scanf("%d",&n),n)
    {
        scanf("%s",a);
        printf("Test case #%d\n",ka++);
        getnext();
        puts("");
    }
    return 0;
}
