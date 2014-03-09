/*
 * ���⣺
 * ��һ��������n��q����ʾ������n�������q��ѯ��
 * ������q��ѯ�ʣ�ѯ����������ʽ
 * 1����1 d ��������d�����˰��Ž��ͷ���Ҫ��ͷ��������ˣ����Ҵ�����˿�ʼ���ţ����ܹ����ţ�������ĸ����俪ʼ���ŵģ��������0
 * 2����2 a b �� ��a~a+b-1�����еĿ������
 *
 * ˼·��
 * ������߶�������ϲ�
 * ����һ������[l,r]
 * lsum:����������˿�ʼ�ܹ��������ſ��˵��������
 * rsum:���������Ҷ˿�ʼ(����)�ܹ��������ſ��˵��������
 * msum:�����������ܹ��������ſ��˵��������
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
const int MAX = 50000+10;
const int inf = 522133279;
const int mod = 1000000007;

int n,q;

struct seg  //������ÿһ���㣬����1��ǰ�����ǿյģ���0��ʾ��ǰ�����п�
{
    int l,r;
    int lsum , rsum , msum;
    int has;    //�ӳٱ��has:����ֵ(-1,0,1)��-1��ʾ����Ҫ�������䣬0��ʾ��Ҫ�ѵ�ǰ�����ÿգ�1��ʾ��Ҫ�ѵ�ǰ���䰲��������
}tree[8*MAX];

void build(int root , int l , int r)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].lsum = tree[root].rsum = tree[root].msum = r-l+1;    //��ʼʱ���䶼�ǿյ�
    tree[root].has=-1;      //��ʼ�ӳٱ��

    if(l==r) return;

    int mid = MID(l,r);

    build(lson(root),l,mid);
    build(rson(root),mid+1,r);
}

void pushdown(int root)//���¸���
{
    if(tree[root].has!=-1)  //�����ǰ������Ҫ������
    {
        tree[lson(root)].has = tree[rson(root)].has=tree[root].has; //������ҲҪ����ͬ�ĸ��ģ�������ӳٱ��
        // ������Ӧ�����䣬���hasΪ0������Ҫ�ѷ�����գ�Ҳ�����������ʾ�ķ��䶼��ס���ˣ��������������sumȫ�ĳ������䳤�ȣ���֮��Ϊ0
        tree[lson(root)].lsum = tree[lson(root)].msum = tree[lson(root)].rsum = tree[root].has? tree[lson(root)].r-tree[lson(root)].l+1:0;
        tree[rson(root)].lsum = tree[rson(root)].msum = tree[rson(root)].rsum = tree[root].has? tree[rson(root)].r-tree[rson(root)].l+1:0;
        tree[root].has=-1;  //����ǰ�����Ϊ���ɲ���״̬
    }
}

void pushup(int root)   //���ϸ���
{
    //�����ø������lsum=���������lsum���������rsum=���������rsum������Ȼһ������
    tree[root].lsum = tree[lson(root)].lsum;
    tree[root].rsum = tree[rson(root)].rsum;

    //Ȼ�󿴿��ܲ�����չ(����)�����������sumֵ
    //��������䷿��ȫ�ǿյģ���ô�Ϳ��Խ����������lsum
    if(tree[root].lsum == tree[lson(root)].r-tree[lson(root)].l+1)
        tree[root].lsum += tree[rson(root)].lsum;
    //ͬ�����������ķ���ȫ�ǿյģ���ô�Ϳ��Խ����������rsum
    if(tree[root].rsum == tree[rson(root)].r-tree[rson(root)].l+1)
        tree[root].rsum += tree[lson(root)].rsum;
    //������������ɰ��ŷ���msum��ֵ����max(�������rsum+�������lsum(�����û���������),�������msum���������msum)
    tree[root].msum = max(tree[lson(root)].rsum+tree[rson(root)].lsum,max(tree[lson(root)].msum,tree[rson(root)].msum));
}

void modify(int root , int l , int r , int state)       //��ͨ�ĸ��²���
{
    if(tree[root].l >= l && tree[root].r <= r)
    {
        //Ŀ�����������ǰ���䣬�ѵ�ǰ���䰴state��ջ�������
        tree[root].lsum=tree[root].rsum=tree[root].msum = (state? tree[root].r-tree[root].l+1:0);
        //�ӳٱ�ǣ�����������ͬ����
        tree[root].has=state;
        return ;
    }

    //�����¸���һ�㣬Ȼ������һ�㣬Ȼ�󷵻�����ʱ���¸�����
    pushdown(root);
    int mid = MID(tree[root].l,tree[root].r);
    if(mid >= l)
        modify(lson(root),l,r,state);
    if(mid < r)
        modify(rson(root),l,r,state);
    pushup(root);
}

int query(int root , int d)     //Ѱ������˵Ŀɰ���λ��
{
    if(tree[root].msum < d)     //�����ǰ��������ɰ�������������С��Ŀ��ֵ����ôһ�����Ų��ˣ�������ĿҪ���0ֵ
        return 0;
    if(tree[root].l==tree[root].r)  //�����Ҷ�ӽڵ��ˣ��ҿɰ��ţ���ô������һ���ڵ��λ��
        return tree[root].l;

    //�������Ҷ�ӽڵ㣬������pushdown���¸���һ��
    pushdown(root);

    //Ѱ�ҵ�˳�򣺵�ǰ���������ˣ����еĻ����ҵ�ǰ������м�Σ��ٲ��еĻ���Ѱ�����Ҷ�
    if(tree[root].lsum >= d)        //����ˣ����еĻ��ͷ���l
        return tree[root].l;
    if(tree[lson(root)].msum >= d)  //���еĻ����͵ݹ���"�������м�����������"
        return query(lson(root),d);
    if(tree[lson(root)].rsum+tree[rson(root)].lsum >= d)    //���������β��еĻ��������������νӶ�
        return tree[lson(root)].r-tree[lson(root)].rsum+1;
    return query(rson(root),d);             //�����еĻ��������������ͬ���Ĳ���
}

int main()
{
    //FR;
    while(~scanf("%d%d",&n,&q))
    {
        clr(tree,0);
        build(1,1,n);
        while(q--)
        {
            int op;
            scanf("%d",&op);

            if(op == 1)
            {
                int d,res;
                scanf("%d",&d);
                printf("%d\n",res=query(1,d));
                if(res) modify(1,res,res+d-1,0);    //���һ������state��0��ʾ�������䱻��������
            }
            else
            {
                int a,b;
                scanf("%d%d",&a,&b);
                modify(1,a,a+b-1,1);    //1��ʾ��������ȫ�����
            }
        }
    }
    return 0;
}
