/*
 * ���⣺��һȺ���ǵ����꣬�������ǵȼ���x��y������������������ǵĸ�����������ȼ������ǵĸ���
 *
 * ˼·�����߶�������״���飬
 * �����ǰ�y��������������ģ� �����¼���һ����ֻ���ж�����[1��x]���ж��ٸ��㣬 �����º������������ĵ�ĸ���
 * tree[i]��ʾx��������[1,x]�е����ǵĸ���(��״����Ĺ�������ͣ������ǵ�Ȩֵ��Ϊ1���൱�ڼ�����)
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
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;

int tree[32100];
int cnt[15100];
int n;

int lowbit(int x)
{
    return (-x)&x;
}

int getsum(int pos)
{
    int t=0;
    for(; pos > 0 ; pos -= lowbit(pos))
        t += tree[pos];

    return t;
}

void modify(int pos , int delta)
{
    for( ; pos <= 32010 ; pos += lowbit(pos))   //���ϸ��£��Ժ���ֵ�x��pos��Ķ�����ǰ����lv��ע����״����ά������ʲô����Χ��Ҫ��д��n
        tree[pos] += delta;
}

int main()
{
    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        a++;                //��״�����1��ţ�λ��������Ҫ

        int lv = getsum(a);
        cnt[lv]++;
        modify(a,1);

    }

    for(int i = 0 ; i < n ; i++)
    {
        printf("%d\n",cnt[i]);
    }

    return 0;
}
