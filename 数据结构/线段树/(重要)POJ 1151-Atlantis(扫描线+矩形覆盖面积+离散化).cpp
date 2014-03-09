/*
 * ���⣺
 * ������Ϊ��x�᷽������Ϊ��y�᷽��������ϵ
 * ����n�����Σ�ÿ���ĸ���x1,y1,x2,y2��(x1,y1)�������Ͻǵĵ�,(x2,y2)�������½ǵĵ�
 * ����Щ���θ��ǵ�ƽ�����
 *
 * ˼·��
 * ɨ����ģ���⣬�����ɨ���������Ŵ�����ɨ��,����ά������������ֱ�߶�
 *
 * ɨ����˼�룺
 * ���Ƚ����е���ɢ�����Էָ�ƽ���2n*2n�ĳ�Ԫƽ��(���������깹�ɵ�С����)���õ����ɳ�Ԫ�߶�(����������֮����߶�)
 * Ȼ�������ɨ�������Ԫ�߶Σ���������ɨ����֮��ĳ�Ԫ�߶εĳ��ȶ���һ���ģ���Ϊdy��ΪĿ����
 * ��ôɨ�赽��Ŀ�곤���ж��٣����ǰ�ɨ�赽��Ŀ���߶�(�����ڸ������ε��߶�)ӳ�䵽y�ᣬ��Ȼ��y�ᱻ���ǵĳ���dx���ǳ���
 * ����������һ�������dx*dy��Ȼ��ѭ������ۼӾͿ�����
 *
 * y�ᱻ���ǵĳ������߶���ά��
 * ÿ����ֱ�߶��и����flag��1��ʾɨ����ɨ���������߶������ľ��Σ�Ҫ��ʼ��������ˣ�����Ҫ����һ���߶�ӳ�䵽y����
 * ��-1��ʾɨ���߼���ɨ��������Σ���ʱ��Ҫ�������߶δ�y�����Ƴ�
 * �������¹��̺����Ʋ������
 *
 * ��������ֵ��doubleֵ������Ҫ��ɢ������y����
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

struct LINE
{
    double x,y1,y2;
    int flag;   //1 ���� -1 ��������
    LINE(){}
    LINE(double _x,double _y1,double _y2,int _flag)
    {
        x=_x;y1=_y1;y2=_y2;flag=_flag;
    }
    bool operator < (const LINE &b)const
    {
        return x < b.x;
    }
};

struct seg
{
    int l,r;                    //l,r��ʾ���Ǳ�ʾ��l��y���굽��r��y�����������Ԫ�߶���
    double ll,rr,len;           //ll,rr��ʾ���������꣬����l��y���������ֵ�͵�r��y���������ֵ��len��������������
    int lazy;       //lazy��0ֵ��ʾ���߶θ��ǵ�������
}tree[8*110];

vector<double> y;       //����Ԫ��y[i]-y[i-1]����һ����ֱ��Ԫ�߶εĳ���
vector<LINE> line;
map<double,int> mir;        //ӳ�䣬mir[x]��ʾӵ��xֵ��y�����ǵ�mir[x]��y����

void build(int root , int l , int r)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].lazy=tree[root].len=0;
    tree[root].ll = y[l],tree[root].rr = y[r];

    if(r-l==1)              //�ж����������仮�ֶ���ͬ�ˣ���ΪҶ�ӽڵ��ǵ�λ�߶ζ���һ����
        return ;

    int mid = MID(l,r);
    build(lson(root),l,mid);
    build(rson(root),mid,r);        //��mid����mid+1
}

void pushup(int root)
{
    if(tree[root].lazy)
        tree[root].len = tree[root].rr-tree[root].ll;
    else if(tree[root].r==tree[root].l+1)
        tree[root].len=0;
    else
        tree[root].len = tree[lson(root)].len+tree[rson(root)].len;
}

void modify(int root, int l,int r,int v)
{
    if(tree[root].r <= r && tree[root].l >= l)
    {
        tree[root].lazy+=v;
        pushup(root);
        //tree[root].len = tree[root].lazy?(tree[root].rr-tree[root].ll):0;   //ע��lazy*(rr-ll)�ͻ��ظ������ˣ���Ϊ���ܶ�θ��ǣ�lazy��ֵ����>1
        return ;
    }
    int mid = MID(tree[root].l,tree[root].r);

    if(mid > l)                 //��> ���� >=
        modify(lson(root),l,r,v);
    if(mid < r)
        modify(rson(root),l,r,v);
    pushup(root);
}

int main()
{
    //FR;
    int n;
    int tt=0;
    while(scanf("%d",&n),n)
    {
        y.clear(),mir.clear(),line.clear();
        double x1,y1,x2,y2;

        for(int i = 0 ; i < n ; i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            //�Ѿ�����ߵ��߶α��Ϊ1���ұߵı��Ϊ-1
            line.push_back(LINE(x1,y1,y2,1));
            line.push_back(LINE(x2,y1,y2,-1));
            //������ѹ��vector�Ա���������ͬһ���εĳ�Ԫ�߶�һ���ǽ��ڵģ�����û��Ҫ���Ķϵ�����������
            y.push_back(y1),y.push_back(y2);
        }
        sort(line.begin(),line.end());
        sort(y.begin(),y.end());
        y.erase(unique(y.begin(),y.end()),y.end());     //ȥ�أ���ӳ��Ļ���ʵû��Ҫ

        for(int i = 0 ; i < y.size() ; i++) mir[y[i]]=i;
        build(1,0,y.size()-1);

        double area=0;
        for(int i = 0 ; i < line.size() ; i++)
        {
            if(i) area += (line[i].x-line[i-1].x)*tree[1].len;
            modify(1,mir[line[i].y1],mir[line[i].y2],line[i].flag); //����˵������y��id����y��id
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",++tt,area);
    }
    return 0;
}
