/*
 * 求n个矩形覆盖面积的轮廓的周长
 *
 * 注：本算法没有考虑到竖直方向重边的问题
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
const int MAX = 20000+10;
const int inf = 522133279;
const int mod = 1000000007;

struct seg
{
    int l,r;
    int ll,rr;
    int lazy;   //区间被覆盖次数
    int len;
    bool isl,isr;   //区间的左右端点有没有被覆盖
    int cnt;    //当前映射到y轴上的线段的段数，则水平方向当前超元线段的总长度为2*cnt*△x

    void ca(int v)
    {
        lazy+=v;cnt+=v;
        if(lazy)
        {
            isl=isr=true;   //如果当前区间是被覆盖的，那么左右端点一定是被覆盖的
            len=rr-ll;
        }
        else
            isl=isr=false,len=0;
    }
}tree[4*MAX];

struct LINE
{
    int x;
    int y1,y2;
    int flag;

    LINE(){}
    LINE(int _x,int _y1,int _y2 ,int _flag)
    {
        x=_x;y1=_y1;y2=_y2;flag=_flag;
    }
    bool operator < (const LINE&b)const
    {
        return x<b.x;
    }
};

int n;
vector<int> y;
vector<LINE> line;
map<int,int> mir;

void build(int root , int l , int r)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].ll=y[l],tree[root].rr=y[r];
    tree[root].cnt=tree[root].lazy=tree[root].len=0;
    tree[root].isl=tree[root].isr=false;

    if(r-l==1)
        return;

    int mid = MID(l,r);
    build(lson(root),l,mid);
    build(rson(root),mid,r);
}

void pushup(int root)
{
    if(tree[root].lazy) //当前区间被覆盖
    {
        tree[root].cnt=1;
        tree[root].len = tree[root].rr-tree[root].ll;
        tree[root].isl=tree[root].isr=1;
    }
    else if(tree[root].r-tree[root].l==1)   //已经深入到超元线段了
    {
        tree[root].isl=tree[root].isr=tree[root].cnt=tree[root].len=0;
    }
    else
    {
        tree[root].len = tree[lson(root)].len+tree[rson(root)].len; //长度就是子区间的长度和
        tree[root].cnt = tree[lson(root)].cnt+tree[rson(root)].cnt;
        if(tree[rson(root)].isl&&tree[lson(root)].isr)  //注意如果左子区间的右端和右子区间的左端都被覆盖，说明左右子区间是相连的，cnt--
            tree[root].cnt--;
        tree[root].isl = tree[lson(root)].isl;  //更新父区间的左右端点覆盖度
        tree[root].isr = tree[rson(root)].isr;
    }
}

void modify(int root , int l , int r , int v)
{
    if(tree[root].l >= l && tree[root].r <= r)
    {
        tree[root].ca(v);
    }
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
    while(~scanf("%d",&n))
    {
        line.clear(),mir.clear(),y.clear();
        int x1,y1,x2,y2;
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            line.push_back(LINE(x1,y1,y2,1));
            line.push_back(LINE(x2,y1,y2,-1));
            y.push_back(y1);
            y.push_back(y2);
        }
        sort(y.begin(),y.end());
        sort(line.begin(),line.end());
        y.erase(unique(y.begin(),y.end()),y.end());

        for(int i = 0 ; i < y.size() ; i++)
            mir[y[i]]=i;
        build(1,0,y.size()-1);

        int res=0;
        int curlen=0;
        for(int i = 0 ; i < line.size() ; i++)
        {
            if(i) res += 2*tree[1].cnt*(line[i].x-line[i-1].x); //把水平周长加上
            modify(1,mir[line[i].y1],mir[line[i].y2],line[i].flag);
            res += abs(curlen-tree[1].len); //前一状态的长度和当前状态覆盖长度的差绝对值即是新增加的竖直方向上的周长
            curlen = tree[1].len;
        }
        printf("%d\n",res);
    }

    return 0;
}
