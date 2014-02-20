/*
 * ���⣺
 * ��һ������a��һȺѯ�ʣ�ÿһ��ѯ��(l,r)������������ڵ�Ԫ�غ�
 * �����������������ʹ������ѯ�ʵĽ��֮�����
 *
 * ˼·��
 * ��Ȼ��ѯ�ʵ�Խ��ĵ����Խ�������~
 * ����Ҫ���ľ������1~n������λ�õı�ѯ�ʴ�������b[i]��¼
 * Ȼ���С��������a��b���𰸾��ǡ�(a[i]*b[i])
 * Ȼ��Ϊ�˿�������ʱ���ڣ����߶����Ż��������
 * ��Ȼ������и�������.......ʮ������........��
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

int n,q;
LL a[MAX],b[MAX];

struct node
{
    int l;
    int r;
    LL sum;
    LL delta;

    void ca(LL tmp)
    {
        delta += tmp;
        sum += (r-l+1)*tmp;
    }

}tree[3*MAX];

LL build(int root , int l , int r)
{
    tree[root].l=l;
    tree[root].r=r;

    if(l == r)
        return tree[root].sum=0;
    int mid = (l+r) >> 1;

    return tree[root].sum = build(lson(root) , l,mid) + build(rson(root),mid+1,r);
}

void modify(int root , int l ,int r , LL delta)
{
    if(tree[root].r <= r && tree[root].l >= l)
    {
        tree[root].ca(delta);
        return;
    }

    if(tree[root].delta)
    {
        tree[root<<1].ca(tree[root].delta);
        tree[root<<1|1].ca(tree[root].delta);
        tree[root].delta=0;
    }

    int mid = (tree[root].l + tree[root].r)>>1;

    if(mid >= l)
        modify(root << 1 , l , r , delta);
    if(mid < r)
        modify(root << 1|1 , l , r , delta);

    tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
}

LL getsum(int root , int l , int r)
{
    if(tree[root].l == l && tree[root].r == r)
        return tree[root].sum;

    if(tree[root].delta)
    {
        tree[root<<1].ca(tree[root].delta);
        tree[root<<1|1].ca(tree[root].delta);
        tree[root].delta=0;
    }

    int mid = (tree[root].l+tree[root].r) >> 1;

    if(mid < l)
        return getsum(root << 1|1 , l,r);
    else if(mid >= r)
        return getsum(root << 1 , l,r);
    else
        return getsum(root << 1 , l , mid) + getsum(root << 1|1 , mid+1,r);
}

int main()
{
    FR;
    clr(tree,0);
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    build(1,1,n);
    for(int i = 0 ; i < q ; i++)
    {
        int x,y;
        cin >>x>>y;
        modify(1,x,y,1); //[x,y]������λ�õļ�����+1
    }
    for(int i = 1 ; i <= n ; i++)
        b[i] = getsum(1,i,i);       //ȡ��iλ�õļ�������
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    LL ans=0;
    for(int i = 1 ; i <= n ; i++)
        ans += a[i]*b[i];
    cout << ans << endl;
    return 0;
}
