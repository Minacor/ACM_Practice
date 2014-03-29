/*
 * ����:
 * ��һ�и���������������̨��n�����ֱ��ͨѶ����d
 * ������n�и������е��Ե����꣬��̨����ֻ�о��벻����d�����߶����޺��˲���ֱ��ͨѶ��ͨѶ���д�����
 * ������ֱ�������������һЩ����������������:
 * 1: O num���޺ñ��Ϊnum�ĵ���
 * 2��S a b��ѯ��ab�Ƿ���ͨѶ
 *
 * ˼·��
 * ���鼯�����ܹ�ͨѶ����̨���Լӵ�ͬһ������
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
#define mkp make_pair
using namespace std;
typedef long long LL;
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int n,d;

struct node
{
    int x;
    int y;
    int state;
}p[1010];

double dis(node a , node b)
{
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int f[1010];
int find(int x)
{
    return x != f[x] ? f[x] = find(f[x]) : x;
}

void merger(int x , int y)
{
    x = find(x);
    y = find(y);

    if(x!=y)
        f[x]=y;
}

int main()
{
    while(cin >> n >> d)
    {
        for(int i = 0 ; i <= n ; i++)
            f[i]=i;
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> p[i].x >> p[i].y;
            p[i].state=0;
        }

        char op;
        while(cin >> op)
        {
            if(op == 'O')
            {
                int num;
                cin >> num;
                p[num].state=1;

                for(int i = 1 ; i <= n ; i++)
                {
                    if(i != num && p[i].state && dis(p[i],p[num]) <= d)
                        merger(i,num);
                }
            }
            else
            {
                int a,b;
                cin >> a >> b;
                cout << (find(a)==find(b) ? "SUCCESS":"FAIL") << endl;
            }
        }
    }
    return 0;
}

