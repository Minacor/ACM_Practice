/*
 * ���⣺
 * ��һ����Ϊh����Ϊw�ľ��Σ���n����Ϊ1����Ϊwi��С����
 * ����Ҫ����Щ���ΰ�����˳������ڴ�����ڣ�����ѡ����˵Ŀɷ�λ�ã�Ȼ������ѡ������ɷ�λ�õ�����˵Ŀɷ�λ��
 * ����ܷ������С���Σ������������һ�У��������-1
 *
 * ˼·��
 * ���ݷ��ù������߶���ά���߶�(l,r)�ڵ�ÿһ�пɷų��ȵ����ֵ��Ȼ�����ұ���������������û�п��԰��ŵ�
 * �еĻ������
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
const int MAX = 200000+100;
const int inf = 522133279;
const int mod = 1000000007;

int t;
int h,w;
int n;
int rr;
int ok;

struct seg      //v��ʾ��l�е���r�е������е����ɷų���
{
    LL l;
    LL r;
    LL v;
}tree[3*MAX];

LL build(int root , int l , int r)
{
    tree[root].l=l;
    tree[root].r=r;

    if(l==r)
        return tree[root].v=w;

    int mid =MID(l,r);

    return tree[root].v = max(build(lson(root),l,mid),build(rson(root),mid+1,r));

}

void query(int root,LL v)
{
    if(tree[root].l == tree[root].r && tree[root].v >= v)
    {
        ok=1;
        printf("%I64d\n",tree[root].l);
        tree[root].v -= v;
        return ;
    }

    if(tree[root].v < v)
        return ;

    if(!ok) query(lson(root),v);
    if(!ok) query(rson(root),v);

    tree[root].v = max(tree[lson(root)].v,tree[rson(root)].v);  //�����Ǹ������ֵ�������T��
}

int main()
{
    while(~scanf("%d%d%d",&h,&w,&n))
    {
        clr(tree,0);
        rr = min(h,n);
        build(1,1,rr);

        for(int i = 0 ; i < n ; i++)
        {
            int v;
            scanf("%d",&v);
            ok=0;
            query(1,v);
            if(!ok) puts("-1");
        }
    }

    return 0;
}
