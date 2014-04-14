/*
 * 题意:
 * 第一行给定两个数：电脑台数n和最大直接通讯距离d
 * 接下来n行给出所有电脑的坐标，两台电脑只有距离不超过d且两者都被修好了才能直接通讯，通讯具有传递性
 * 接下来直到输入结束都是一些操作，操作有两种:
 * 1: O num：修好编号为num的电脑
 * 2：S a b：询问ab是否能通讯
 *
 * 思路：
 * 并查集，把能够通讯的两台电脑加到同一个集合
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

