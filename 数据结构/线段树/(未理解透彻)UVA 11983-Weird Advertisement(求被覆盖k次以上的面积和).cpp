/*
 * 题意：
 * 求被n个矩形覆盖k次以上的面积
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
const int MAX = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int t,n;
struct LINE
{
    int x,y1,y2;
    int flag;

    LINE(){}
    LINE(int a,int b,int c,int d)
    :x(a),y1(b),y2(c),flag(d)
    {}

    bool operator < (const LINE& b)const
    {
        return x < b.x;
    }
};
vector<LINE> line;
vector<int> y;
map<int,int> mir;
int k;

struct seg
{
    int l,r;
    int ll,rr;
    int lazy;
    int len[12];    //len[i]表示被覆盖恰好i次的区间长度，若i==k，则表示覆盖k次以上的区间长度

}tree[4*60000];

void build(int root , int l , int r)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].ll = y[l],tree[root].rr=y[r];
    tree[root].len[0]=tree[root].rr-tree[root].ll;      //len[0]储存的是区间长度

    if(l==r-1)
        return;

    int mid(MID(l,r));
    build(lson(root),l,mid);
    build(rson(root),mid,r);
}

void pushup(int root)
{
    if(tree[root].lazy >= k)        //如果延迟标记已经累加到k以上了，直接更新len[k]为区间长度
    {
        int tmp = tree[root].len[0];
        clr(tree[root].len,0);
        tree[root].len[k]=tree[root].len[0]=tmp;
    }
    else if(tree[root].lazy)
    {
        int tmp = tree[root].len[0];
        int cur = tree[root].lazy;
        clr(tree[root].len,0);
        tree[root].len[0]=tree[root].len[cur]=tmp;  //这个时候len[cur]表示的是至少被覆盖cur次的长度

        if(tree[root].r-tree[root].l==1) return ;

        for(int i = 1 ; i <= k ; i++)
        {
            if(i+cur >= k)      //累加上这个标记以后能够达到覆盖k次以上
                tree[root].len[k] += tree[lson(root)].len[i]+tree[rson(root)].len[i];   //注意是累加而非覆盖
            else                //否则仅更新当前累加区间
                tree[root].len[i+cur] = tree[lson(root)].len[i]+tree[rson(root)].len[i];
        }
        LL sum=0;
        for(int i = cur+1;i<=k;i++)             //去掉覆盖次数>cur次的长度
            sum += tree[root].len[i];
        tree[root].len[cur]=tree[root].len[0]-sum;
    }
    else            //累加标记为0的话，直接向上更新
    {
        int tmp = tree[root].len[0];
        clr(tree[root].len,0);
        tree[root].len[0]=tmp;

        if(tree[root].r-tree[root].l==1) return ;

        for(int i = 1 ; i <= k ; i++)
            tree[root].len[i] = tree[lson(root)].len[i]+tree[rson(root)].len[i];
    }
}

void modify(int root , int l , int r , int v)
{
    if(tree[root].l >= l && tree[root].r <= r)
        tree[root].lazy+=v;
    else
    {
        int mid = MID(tree[root].l,tree[root].r);
        if(mid > l)
            modify(lson(root),l,r,v);
        if(mid < r)
            modify(rson(root),l,r,v);
    }
    pushup(root);
}

int main()
{
    //FR;
    int t;
    scanf("%d",&t);
    for(int ka = 1 ; ka <= t ; ka++)
    {
        mir.clear(),line.clear(),y.clear();
        scanf("%d%d",&n,&k);
        int x1,x2,y1,y2;
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            x2++,y2++;              //建的树维护对象是线段，令竖直线段覆盖下端点，则需要扩大矩形
            line.push_back(LINE(x1,y1,y2,1));
            line.push_back(LINE(x2,y1,y2,-1));
            y.push_back(y1),y.push_back(y2);
        }
        sort(y.begin(),y.end());
        sort(line.begin(),line.end());
        y.erase(unique(y.begin(),y.end()),y.end());

        for(int i = 0 ; i < y.size() ; i++)
            mir[y[i]]=i;
        build(1,0,y.size()-1);

        LL res=0;
        for(int i = 0 ; i < line.size() ; i++)
        {
            if(i)res += 1LL*(line[i].x-line[i-1].x)*tree[1].len[k];
            modify(1,mir[line[i].y1],mir[line[i].y2],line[i].flag);
        }
        printf("Case %d: %lld\n",ka,res);
    }
    return 0;
}
