/*
 * 题意：
 * 有一面长n的墙，每单位长度上有一个防御盾，它们的冷却时间都是cd，当成功防御一次以后必须经过cd时间后才能再次防御
 * 现在有q个命令，分两种：
 * 1：Attack l r 攻击(l,r)的墙
 * 2：Query cur 询问cur这个位置受到了几次攻击，被防御住的不算
 * 每攻击一次时间+1，询问不花时间
 *
 * 思路：
 * 用树状数组维护每个单位被攻击的次数，这次是树状数组的单点询问，区间计数(更新)，原理和差分数组完全一样
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
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 200000+100;
const int inf = 522133279;

int t;
int n,q,cd;
char com[20];
int tree[21000];
int can[21000];         //can[i]表示在这个时间，i的防御盾能够进行防御，他们一开始就可以防御，故可以初始化为0
int protect[21000];     //protect[i] 表示截止当前时间i的防御盾一共防御成功的次数

struct node
{
    int l,r;
}att[21000];

int getsum(int pos)
{
    int tt=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        tt += tree[pos];
    return tt;
}

void modify(int pos , int delta)
{
    for( ; pos <= n ; pos += lowbit(pos))
        tree[pos]+= delta;
}

int main()
{
    //FR;
    scanf("%d",&t);

    for(int ka = 1 ; ka <= t ; ka++)
    {
        scanf("%d%d%d",&n,&q,&cd);
        int time=0;
        clr(tree,0); clr(can,0); clr(protect,0);

        printf("Case %d:\n",ka);
        for(int i = 1 ; i <= q ; i++)
        {
            scanf("%s",com);
            if(com[0] == 'A')
            {
                time++;
                int l,r;
                scanf("%d%d",&l,&r);
                att[time].l=l;att[time].r=r;
                modify(l , 1);
                modify(r+1,-1);
            }
            else                            //每次询问都针对一个点计数
            {
                int cur;
                scanf("%d",&cur);

                // i表示cur的防御盾可以在这个时间点进行防御，i从最远一次未被处理过的可以防御的时间点开始，避免重复计数
                for(int i = can[cur] ; i <= time ; i++)
                {
                    if(cur >= att[i].l && cur <= att[i].r)  //如果cur在当前这个可以防御的时间点的攻击区间内
                    {
                        protect[cur]++;
                        can[cur] = i + cd;          //冷却
                        i = can[cur]-1;             //i推进到下一个可以防御的时间点，注意-1，因为紧接着i++
                    }
                }
                printf("%d\n",getsum(cur)-protect[cur]);
            }
        }
    }

    return 0;
}
