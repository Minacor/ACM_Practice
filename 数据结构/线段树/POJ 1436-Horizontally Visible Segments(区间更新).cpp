/*
 * ���⣺
 * ��n���߶Σ���Щ�߶ζ��Ǵ�ֱx��ģ�y1,y2,x�ֱ����߶ε���y���꣬��y���꣬x����
 * ���ڶ���ɴ�����߶�a(y����[ay1,ay2])��b([by1,by2]) ,�����ǵĽ�����ȡһ��y�����߶�(x1,y),(x2,y)����ab�ཻ����ôab���໥�ɴ�
 * ������ȡ�����߶����������ɴ�������߶ζ��ж���
 *
 * ˼·��
 * �Ȱ���x���߶�������һ����
 * Ȼ���߶���ά������l��r�ڵ��߶�id��ÿһ���߶ζ����Լ���id������ֵ=id�ͱ�ʾ������䱻id����ֱ�߸�����
 * Ȼ�����query , �����ѯ��һ�������ֵΪv��˵����ǰ�����߶���v�����߶��ǿɴ��
 *
 * ����Ҫע����ǣ��߶ζ˵��ܹ�������һ���߶Σ�Ҳ���ǿɴ����Ҫ��y����*2���Դ�������[3,4],[2,4]��[5,4]�������
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
const int MAX = 8000+10;
const int inf = 522133279;
const int mod = 1000000007;

struct seg
{
    int x;
    int y1,y2;

    bool operator <(const seg& b)const
    {
        return x<b.x;
    }
}s[MAX];

struct
{
    int l;
    int r;
    int v;
}tree[MAX*8];

int n;
int rr;
bool g[MAX][MAX];

void build(int root , int l , int r)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].v=0;

    if(l==r) return ;

    int mid(MID(l,r));

    build(lson(root),l,mid);
    build(rson(root),mid+1,r);
}

void modify(int root , int l , int r , int v)
{
    if(tree[root].l >= l && tree[root].r <= r)
    {
        tree[root].v=v;
        return ;
    }

    if(tree[root].v)
    {
        tree[lson(root)].v = tree[rson(root)].v = tree[root].v;
        tree[root].v=0;
    }

    int mid = (MID(tree[root].l,tree[root].r));

    if(l <= mid)
        modify(lson(root),l,r,v);
    if(r > mid)
        modify(rson(root),l,r,v);
}

void query(int root , int l, int r , int id)
{
    if(tree[root].v)        //��ѯ�������ֵ��˵�������ֵΪid���߶β�δ����ǰ���߶θ��ǣ��ǿɴ��
    {
        g[tree[root].v][id]=g[id][tree[root].v] = true;
        return;
    }

    if(tree[root].l==tree[root].r)
        return ;

    int mid = (MID(tree[root].l,tree[root].r));

    if(l<=mid)
        query(lson(root),l,r,id);
    if(r>mid)
        query(rson(root),l,r,id);
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        clr(tree,0);
        clr(g,false);
        rr=0;

        scanf("%d",&n);
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d%d%d",&s[i].y1,&s[i].y2,&s[i].x);
            s[i].y1*=2;
            s[i].y2*=2;
            s[i].y1++;
            s[i].y2++;
            rr=max(rr,s[i].y2);
        }

        sort(s+1,s+1+n);
        build(1,1,rr);

        for(int i = 1 ; i <= n ; i++)
        {
            query(1,s[i].y1,s[i].y2,i);
            modify(1,s[i].y1,s[i].y2,i);
        }

        int cnt=0;
        for(int i = 1 ; i <= n ; i++)
            for(int j = i+1 ; j <= n ; j++)
                if(g[i][j])
                    for(int k = j+1; k <= n ; k++)
                        if(g[j][k]&&g[k][i])
                            cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
