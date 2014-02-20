/*
 * ���⣺
 * ��һ���������У���m��ѯ�ʣ����ѯ�����������Ŷ���*2
 *
 * ˼·��
 * http://blog.csdn.net/syjh_1026/article/details/18219301
 *
 * ���ͣ�
 * һ�����У���tot���ԣ��̶����䣬m�β�ѯ[l��r]����������ܹ���ȫ���Ƕ������ԡ�
 * ������Щ����ǹ̶�����ģ���֧���κεĲ��룬�޸ģ�ɾ�����������ǲ�ȡ���߲�����
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

int ok;
string s;
int totpair;        //�������
int q;              //ѯ����
//treel[i]��ʾ�ж��ٵ�Ե�С�ĵ���[0,i]�ڣ���ά��[0,i]�ڵ�������
//treer[i]��ʾ�ж��ٵ�ԵĴ�ĵ���[0,i]�ڣ���ά��[0,i]�ڵ��ҵ����
int treel[1000000+100],treer[1000000+100];

struct seg
{
    int l;
    int r;
    int id;
    int cnt;

    bool operator < (const seg& b)const
    {
        if(ok) return id < b.id;
        return r-l < b.r-b.l;       //���䳤�����򣬱����Ծ���>ѯ�ʾ���ĵ�ԵĴ���
    }
}query[100000+100],Pair[1000000+100];   //ѯ�ʺ͵��

stack<int> sk;

void init()
{
    cin >> s;
    //����������ת���ɵ�ԣ���ջ������ÿһ��')'ƥ�������'('
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] == '(')
            sk.push(i+1);
        else
        {
            if(!sk.empty())
            {
                int cur = sk.top();
                sk.pop();
                Pair[totpair].l = cur;
                Pair[totpair++].r = i+1;
            }
        }
    }

    cin >> q;
    for(int i = 0 ; i < q ; i++)
        cin >> query[i].l >> query[i].r,query[i].id=i;

    sort(Pair,Pair+totpair);
    sort(query,query+q);
    ok=1;
}

int getsum(int *tree , int pos)
{
    int t=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        t += tree[pos];
    return t;
}

void modify(int* tree , int pos , int delta)
{
    for( ; pos <= s.size() ; pos += lowbit(pos))
        tree[pos] += delta;
}

void gao()
{
    clr(treel,0);
    clr(treer,0);

    int pos=0;
    for(int i = 0 ; i < q ; i++)        //����ÿһ��ѯ�ʣ��������а������ٵ��
    {
        //ѯ�ʺ����䶼�ǰ����ȴ�С�������򣬱�֤��ÿ�θ��ºͼ��������г��ȴ���ѯ�ʵĵ�Ա������
        while(pos < totpair && Pair[pos].r-Pair[pos].l <= query[i].r - query[i].l)
        {
            modify(treel,Pair[pos].l,1);
            modify(treer,Pair[pos].r,1);
            pos++;
        }
        query[i].cnt = getsum(treer,query[i].r) - getsum(treel,query[i].l-1);
    }

    //ԭ�����
    sort(query,query+q);

    for(int i = 0 ; i < q ; i++)
        cout << query[i].cnt*2 << endl;
}

int main()
{
    init();
    gao();
    return 0;
}
