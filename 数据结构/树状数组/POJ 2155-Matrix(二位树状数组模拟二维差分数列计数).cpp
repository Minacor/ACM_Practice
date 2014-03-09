/*
 * ���⣺
 * ��һ��n*n��0������m��ѯ��
 * ѯ����������ʽ
 * 1��C x1 y1 x2 y2 �����Ͻ�Ϊ(x1,y1),���½�Ϊ(x2,y2)���Ӿ��������0��1,1��0
 * 2��Q x y ���(x,y)��ֵ
 *
 * ˼·��
 * ��ά��״����ģ��������ά��(x,y)�����˶��ٴΣ�������������������Σ���ô�����1����֮���0
 *
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
#include "cstdlib"
#include "ctime"
#define lson(x) (x<<1)
#define rson(x) (x<<1|1)
#define MID(x,y) ((x+y)>>1)
#define FR (freopen("input.txt","r",stdin))
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long ll;
const int MAX = 1010;
const int inf = 522133279;
const int mod = 1000000007;

int t;
int tree[1010][1010];
int n,m;

void modify(int x , int y , int delta)
{
    for(int i = x ; i <= n ; i+=lowbit(i))
        for(int j = y ; j <= n ; j+=lowbit(j))
            tree[i][j] += delta;
}

int getsum(int x , int y)
{
    int t=0;
    for(int i = x ; i > 0 ; i-=lowbit(i))
        for(int j = y ; j > 0 ; j-=lowbit(j))
            t += tree[i][j];
    return t;
}

int main()
{
    //FR;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        clr(tree,0);
        scanf("%d%d",&n,&m);
        getchar();
        int x1,x2,y1,y2;
        while(m--)
        {
            char op;
            op = getchar();

            if(op == 'C')
            {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                modify(x1,y1,1);
                modify(x2+1,y2+1,1);
                modify(x1,y2+1,-1);
                modify(x2+1,y1,-1);
            }
            else
            {
                scanf("%d%d",&x1,&y1);
                printf("%d\n",getsum(x1,y1)%2);
            }
            getchar();

        }

        if(t)
            cout << endl;
    }
    return 0;
}
