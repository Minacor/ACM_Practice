/*
 * ���⣺
 * ��һ����Ϊn�����У����Խ�����ǰm(m = 0~n)����ƽ�Ƶ�ĩβ�õ�һ�������У�����һ����n����ͬ����
 * ����n�����е���С������
 *
 * ˼·��
 * ����������״������ֻҪ���һ��������ans�����Ľ���һ��Ԫ���Ƶ�ĩβ�õ����Ǹ������е�������Ҳ��ȷ��
 * ���ٵ������Ϊa[i],���ӵ�Ϊn-a[i]-1(��Ϊ������������ϸ�� 0 ~ n-1 )
 * ����һ��ѭ������Сֵ����
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
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;

int n;
int a[5010],tmp[5010];
int tree[5010];

int lowbit(int t)
{
    return t&-t;
}

int getsum(int pos)
{
    int t=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        t+=tree[pos];
    return t;
}

void modify(int pos)
{
    for( ; pos <= n ; pos += lowbit(pos))
        tree[pos]++;
}

int main()
{
    //FR;
    while(~scanf("%d",&n))
    {
        memset(tree,0,sizeof tree);

        for(int i = 1 ; i <= n ; i++)
            scanf("%d",a+i) , a[i]++;

        LL ans=0;
        for(int i = 1 ; i <= n ; i++)
        {
            modify(a[i]);
            ans += getsum(n) - getsum(a[i]);
            a[i]--; //ע������ ��Ȼ����Сֵ�����
        }

        LL minc = ans;

        for(int i = 1 ; i < n ; i++)
        {
            ans = ans-(a[i]) + (n-a[i]-1);
            minc = min(minc,ans);
        }

        cout << minc << endl;

    }
    return 0;
}
