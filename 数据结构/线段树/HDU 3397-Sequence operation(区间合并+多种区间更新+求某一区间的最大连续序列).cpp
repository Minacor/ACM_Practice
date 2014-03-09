/*
 * ���⣺
 * ��һ��������n,m
 * �ڶ���n����������0����1��λ�ô�0��ʼ��
 * ������m��ѯ�ʣ�������ѯ�ʷ�ʽ
 * 1) 0 a b ��������[a,b]�е�����Ԫ�ظ�Ϊ0
 * 2) 1 a b : ������[a,b]�е�����Ԫ�ظ�Ϊ1
 * 3) 2 a b : ������[a,b]�е�0��1,1��0
 * 4) 3 a b �����[a,b]�е�1�ĸ���
 * 5) 4 a b : ���[a,b]�е��������1�ĳ���
 *
 * ˼·��
 * ���߶���
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

int n,m;
int t;
struct seg
{
    int l;
    int r;
    int sum;
    int lsum;
    int rsum;
    int msum;
    int lazy;       //1��ʾ��һ����Ҫȫ��Ϊ1,0��֮
}tree[10*MAX];

void pushdown(int root)
{
    if(tree[root].lazy!=-1)
    {
        tree[lson(root)].lazy= tree[rson(root)].lazy=tree[root].lazy;
        tree[lson(root)].sum=tree[lson(root)].lsum = tree[lson(root)].rsum = tree[lson(root)].msum = tree[root].lazy ? tree[lson(root)].r-tree[lson(root)].l+1 : 0;
        tree[rson(root)].sum=tree[rson(root)].lsum = tree[rson(root)].rsum = tree[rson(root)].msum = tree[root].lazy ? tree[rson(root)].r-tree[rson(root)].l+1 : 0;
        tree[root].lazy=-1;
    }
}

void pushup(int root)
{
    tree[root].sum = tree[lson(root)].sum + tree[rson(root)].sum;
    tree[root].lsum = tree[lson(root)].lsum;
    tree[root].rsum = tree[rson(root)].rsum;

    if(tree[root].lsum == tree[lson(root)].r-tree[lson(root)].l+1)
        tree[root].lsum += tree[rson(root)].lsum;
    if(tree[root].rsum == tree[rson(root)].r-tree[rson(root)].l+1)
        tree[root].rsum += tree[lson(root)].rsum;
    tree[root].msum = max(tree[lson(root)].rsum+tree[rson(root)].lsum , max(tree[lson(root)].msum , tree[rson(root)].msum));
}

void build(int root , int l , int r)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].lazy=-1;

    if(l==r)
    {
        int tmp;
        scanf("%d",&tmp);
        tree[root].lsum = tree[root].rsum = tree[root].msum=tmp;
        tree[root].lazy=tree[root].sum=tmp;
        return ;
    }

    int mid(MID(l,r));
    build(lson(root),l,mid);
    build(rson(root),mid+1,r);
    pushup(root);                   //����֮ǰ�г�ʼֵ��ֻҪupһ�¾Ϳ�����
}

void modify(int root , int l , int r , int type)
{
    if(tree[root].l >= l && tree[root].r <= r)
    {
        if(type==0||type==1)
        {
            tree[root].sum = tree[root].lsum = tree[root].rsum = tree[root].msum = type*(tree[root].r-tree[root].l+1);
            tree[root].lazy=type;
            return;
        }
        else
        {
            if(tree[root].lazy!=-1) //ע�������д����������ʱ�ǲ�ֱ��return��
            {
                tree[root].lazy=1-tree[root].lazy;
                tree[root].sum = tree[root].lsum = tree[root].rsum = tree[root].msum = (tree[root].lazy ? tree[root].r-tree[root].l+1 : 0);
                return ;
            }
        }
    }

    if(tree[root].l==tree[root].r)
        return ;

    pushdown(root);
    int mid = MID(tree[root].l,tree[root].r);

    if(mid >= l)
        modify(lson(root),l,r,type);
    if(mid < r)
        modify(rson(root),l,r,type);
    pushup(root);
}


int query_sum(int root , int l , int r)
{
    if(tree[root].l >= l && tree[root].r <= r)
        return tree[root].sum;

    pushdown(root);
    int mid = MID(tree[root].l,tree[root].r);

    int res=0;
    if(mid >= l)
        res += query_sum(lson(root),l,r);
    if(mid < r)
        res += query_sum(rson(root),l,r);
    return res;
}

int query_01(int root , int l , int r)  //���������������1������
{
    if(tree[root].l == l && tree[root].r == r)
        return tree[root].msum;

    pushdown(root);
    int mid = MID(tree[root].l,tree[root].r);

    if(mid >= r)//��������û�н���
        return query_01(lson(root),l,r);
    if(mid < l)//��������û�н���
        return query_01(rson(root),l,r);

    int tmp = max(query_01(lson(root),l,mid),query_01(rson(root),mid+1,r));
    return max(tmp,min(tree[lson(root)].rsum,tree[lson(root)].r-l+1)+min(tree[rson(root)].lsum,r-tree[rson(root)].l+1));
}

int main()
{
    //FR;
    scanf("%d",&t);

    while(t--)
    {
        clr(tree,0);
        scanf("%d%d",&n,&m);
        build(1,0,n-1);

        while(m--)
        {
            int op,x,y;
            scanf("%d%d%d",&op,&x,&y);

            if(op <= 2)
                modify(1,x,y,op);
            else
                if(op==3)
                    cout << query_sum(1,x,y) << endl;
                else
                    cout << query_01(1,x,y) << endl;
        }
    }
    return 0;
}
