/*
 * ���⣺
 * ���ά��״����
 * ���������
 * 0������һ��s*s��0����(���Ϊ(0,0))
 * 1��������Ϊ(x,y)������+a
 * 2�����Ӿ����Ԫ�غ�:���Ͻ�(l,b)�����½�(r,t)
 * 3����ֹ
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

int tree[1050][1050];
int s;

int lowbit(int t)
{
    return t & -t;
}

int getsum(int x , int y)
{
    int t=0;
    for( int i = x ; i > 0 ; i -= lowbit(i))
        for( int j = y ; j > 0 ; j -= lowbit(j))
        {
            t += tree[i][j];
        }
    return t;
}

void modify(int x , int y , int delta)
{
    for(int i = x ; i <= s ; i += lowbit(i))
        for(int j = y ; j <= s ; j += lowbit(j))
            tree[i][j] += delta;
}

int main()
{
    //FR;
    int op;
    while(~scanf("%d",&op))
    {

        while(op != 3)
        {
            if(op == 0)
            {
                scanf("%d",&s);
                memset(tree , 0 , sizeof tree);
            }
            if(op == 1)
            {
                int x,y,a;
                scanf("%d%d%d",&x,&y,&a);
                x++,y++;                //ע���ά��״�������Ǵ�(1,1)��ʼ��
                modify(x,y,a);
            }
            if(op == 2)
            {
                int l,b,r,t;
                scanf("%d%d%d%d",&l,&b,&r,&t);
                l++,b++,r++,t++;
                printf("%d\n" , getsum(r,t)-getsum(l-1,t)-getsum(r,b-1)+getsum(l-1,b-1)); //�Ӿ���͵���
            }
            scanf("%d",&op);
        }
    }

    return 0;
}
