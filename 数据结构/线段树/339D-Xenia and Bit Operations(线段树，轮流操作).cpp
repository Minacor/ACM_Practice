/*
 * ���⣺
 * ����n��m���ٸ���1<<n������m�����
 * ���е�ֵ������Ϊ��
 * �����ڵ�������|��������a,b,c,d -> a|b,c|d���õ����ָ���Ϊ1<<(n-1)��������
 * Ȼ�������������^����
 * ����������������ֱ��ֻʣ��һ���������������ԭ���е�ֵ
 *
 * ����ÿһ��ѯ��pos��v����ԭ����posλ�õ�����Ϊv������������е�ֵ�����б�Ŵ�1��ʼ
 *
 * ˼·��
 * ��Ȼ�߶���ά������������ͬһ�㣬�������һ���ģ��������ڲ�Ĳ�����ͬ
 * ����ÿһ�����ʲô��������aim��ȷ����aim�ĳ�ֵ�������ϲ����ͨ��n����ż��ȷ��
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

int n,m;
int tot;
int a[140000];

struct seg
{
    int l;
    int r;
    int v;
}tree[3*140000];

int build(int root , int l , int r ,bool aim)
{
    tree[root].l=l;
    tree[root].r=r;

    if(l == r)
        return tree[root].v = a[l];

    int mid = MID(l,r);

    if(aim)
        return tree[root].v = build(lson(root),l,mid,!aim)^build(rson(root),mid+1,r,!aim);
    else
        return tree[root].v = build(lson(root),l,mid,!aim)|build(rson(root),mid+1,r,!aim);
}

int modify(int root , int pos , int v , bool aim)
{
    if(tree[root].l == pos && tree[root].r == pos)
        return tree[root].v = v;

    int mid = MID(tree[root].l,tree[root].r);

    if(pos <= mid)
        modify(lson(root),pos,v,!aim);
    else
        modify(rson(root),pos,v,!aim);
    if(aim)
        return tree[root].v = tree[lson(root)].v^tree[rson(root)].v;
    else
        return tree[root].v = tree[lson(root)].v|tree[rson(root)].v;
}

int main()
{
    FR;
    cin >> n >> m;
    tot = 1<<n;
    for(int i = 1 ; i <= tot ; i++)
        cin >> a[i];

    build(1,1,tot,(n&1)==0);

    while(m--)
    {
        int pos,v;
        cin >> pos >> v;
        cout << modify(1,pos,v,(n&1)==0) << endl;
    }
    return 0;
}
