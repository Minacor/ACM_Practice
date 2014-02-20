/*
 * 题意：
 * 给一个括号序列，和m个询问，求出询问区间中括号对数*2
 *
 * 思路：
 * http://blog.csdn.net/syjh_1026/article/details/18219301
 *
 * 题型：
 * 一个序列，有tot组点对，固定不变，m次查询[l，r]这个区间上能够完全覆盖多少组点对。
 * 由于这些点对是固定不变的，不支持任何的插入，修改，删除，所以我们采取离线操作。
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
int totpair;        //点对总数
int q;              //询问数
//treel[i]表示有多少点对的小的点在[0,i]内，即维护[0,i]内的左点个数
//treer[i]表示有多少点对的大的点在[0,i]内，即维护[0,i]内的右点个数
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
        return r-l < b.r-b.l;       //区间长度排序，避免点对距离>询问距离的点对的处理
    }
}query[100000+100],Pair[1000000+100];   //询问和点对

stack<int> sk;

void init()
{
    cin >> s;
    //把括号序列转化成点对，用栈操作，每一个')'匹配最近的'('
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
    for(int i = 0 ; i < q ; i++)        //对于每一个询问，计算其中包含多少点对
    {
        //询问和区间都是按长度从小到大排序，保证了每次更新和计数不会有长度大于询问的点对被误计算
        while(pos < totpair && Pair[pos].r-Pair[pos].l <= query[i].r - query[i].l)
        {
            modify(treel,Pair[pos].l,1);
            modify(treer,Pair[pos].r,1);
            pos++;
        }
        query[i].cnt = getsum(treer,query[i].r) - getsum(treel,query[i].l-1);
    }

    //原序输出
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
