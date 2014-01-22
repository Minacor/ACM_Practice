
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
int tree[1000000+100];
int ok=0;

struct node
{
    int v;
    int id;

    bool operator < (const node & b)const
    {
        if(!ok)
            return v < b.v;
        else
            return id < b.id;
    }
}num[1000000+100];

int lowbit(int t)
{
    return t & -t;
}

int getsum(int pos)
{
    int t=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        t += tree[pos];
    return t;
}

void modify(int pos , int delta)
{
    for( ; pos <= n ; pos += lowbit(pos))
        tree[pos] += delta;
}


int main()
{

    while(~scanf("%d",&n))
    {
        LL ans=0;
        ok=0;
        memset(num,0,sizeof num);
        memset(tree , 0 , sizeof tree);

        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d",&num[i].v);
            num[i].id = i;
        }
        sort(num+1,num+1+n);

        num[1].v=1;
        for(int i = 2 ; i <= n ;i++)
        {
            if(num[i].v != num[i-1].v)
                num[i].v=i;
        }
        ok=1;
        sort(num+1,num+1+n);

        for(int i = 1 ; i <= n ; i++)
        {
            ans += getsum(n) - getsum(num[i].v);
            modify(num[i].v,1);
        }

        printf("%I64d\n",ans); 
    }

    return 0;
}
