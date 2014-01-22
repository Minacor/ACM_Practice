/*
 * 题意：给一组区间[s,e]，问所有区间中包含它的区间数，s,e相同不算
 *
 * 思路: star的变体，由于题目要求是包含(s1>=s2 && e1<=e2 && e1-s1 < e2-s2)，所以要考虑去重
 * 排序时先按e大到小，e相同时s小到大
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

int n;
int tree[100000+100] , out[100000+100];

struct node
{
    int l,r,id;

    bool operator < (const node &b)const
    {
        if(r != b.r)
            return r > b.r;
        return l < b.l;
    }
}cow[100000+100];

int lowbit(int t)
{
    return t&(-t);
}

int getsum(int pos)
{
    int t=0;

    for(;pos > 0 ; pos -= lowbit(pos))
        t += tree[pos];

    return t;
}

void modify(int pos , int delta)
{
    for(; pos <= 100000+10 ; pos += lowbit(pos))
        tree[pos] += delta;
}

int main()
{
    while(~scanf("%d",&n) && n)
    {
        memset(tree,0,sizeof tree);
        memset(out , 0 ,  sizeof out);

        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d%d",&cow[i].l,&cow[i].r);
            cow[i].l++;cow[i].r++;
            cow[i].id=i;
        }

        sort(cow+1,cow+n+1);

        out[cow[1].id] == getsum(cow[1].l);
        modify(cow[1].l,1);

        for(int i = 2 ; i <= n ; i++)
        {
            if(cow[i].l == cow[i-1].l && cow[i].r == cow[i-1].r)    //去重
                out[cow[i].id] = out[cow[i-1].id];
            else
                out[cow[i].id] = getsum(cow[i].l);
            modify(cow[i].l , 1);                   //注意无论去不去重，都是有新点加入了，所以都要更新

        }

        printf("%d",out[1]);
        for(int i = 2 ; i <= n ; i++)
            printf(" %d" , out[i]);
        puts("");
    }

    return 0;
}
