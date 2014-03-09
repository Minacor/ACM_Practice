/*
 * ��n�����θ���������������ܳ�
 *
 * ע�����㷨û�п��ǵ���ֱ�����رߵ�����
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
    int lazy;   //���䱻���Ǵ���
    int len;
    bool isl,isr;   //��������Ҷ˵���û�б�����
    int cnt;    //��ǰӳ�䵽y���ϵ��߶εĶ�������ˮƽ����ǰ��Ԫ�߶ε��ܳ���Ϊ2*cnt*��x

    void ca(int v)
    {
        lazy+=v;cnt+=v;
        if(lazy)
        {
            isl=isr=true;   //�����ǰ�����Ǳ����ǵģ���ô���Ҷ˵�һ���Ǳ����ǵ�
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
    if(tree[root].lazy) //��ǰ���䱻����
    {
        tree[root].cnt=1;
        tree[root].len = tree[root].rr-tree[root].ll;
        tree[root].isl=tree[root].isr=1;
    }
    else if(tree[root].r-tree[root].l==1)   //�Ѿ����뵽��Ԫ�߶���
    {
        tree[root].isl=tree[root].isr=tree[root].cnt=tree[root].len=0;
    }
    else
    {
        tree[root].len = tree[lson(root)].len+tree[rson(root)].len; //���Ⱦ���������ĳ��Ⱥ�
        tree[root].cnt = tree[lson(root)].cnt+tree[rson(root)].cnt;
        if(tree[rson(root)].isl&&tree[lson(root)].isr)  //ע���������������Ҷ˺������������˶������ǣ�˵�������������������ģ�cnt--
            tree[root].cnt--;
        tree[root].isl = tree[lson(root)].isl;  //���¸���������Ҷ˵㸲�Ƕ�
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
            if(i) res += 2*tree[1].cnt*(line[i].x-line[i-1].x); //��ˮƽ�ܳ�����
            modify(1,mir[line[i].y1],mir[line[i].y2],line[i].flag);
            res += abs(curlen-tree[1].len); //ǰһ״̬�ĳ��Ⱥ͵�ǰ״̬���ǳ��ȵĲ����ֵ���������ӵ���ֱ�����ϵ��ܳ�
            curlen = tree[1].len;
        }
        printf("%d\n",res);
    }

    return 0;
}
