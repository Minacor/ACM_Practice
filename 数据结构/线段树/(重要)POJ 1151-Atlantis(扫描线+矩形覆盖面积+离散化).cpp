/*
 * 题意：
 * 以右向为正x轴方向，下向为正y轴方向建立坐标系
 * 给出n个矩形，每行四个数x1,y1,x2,y2，(x1,y1)代表左上角的点,(x2,y2)代表右下角的点
 * 求这些矩形覆盖的平面面积
 *
 * 思路：
 * 扫描线模板题，本题的扫描线是竖着从左到右扫的,所以维护的是所有竖直线段
 *
 * 扫描线思想：
 * 首先将所有点离散化，以分割平面成2n*2n的超元平面(相邻两坐标构成的小矩形)，得到若干超元线段(相邻两坐标之间的线段)
 * 然后从左到右扫描各个超元线段，夹在两条扫描线之间的超元线段的长度都是一样的，设为dy，为目标宽度
 * 那么扫描到的目标长度有多少？我们把扫描到的目标线段(即属于给定矩形的线段)映射到y轴，显然，y轴被覆盖的长度dx就是长了
 * 这样就求到了一部分面积dx*dy，然后循环求解累加就可以了
 *
 * y轴被覆盖的长度用线段树维护
 * 每条竖直线段有个标记flag，1表示扫描线扫到了这条线段所属的矩形，要开始计算面积了，所以要把这一条线段映射到y轴上
 * 而-1表示扫描线即将扫出这个矩形，这时就要把这条线段从y轴上移除
 * 整个更新过程很类似差分数列
 *
 * 本题由于值是double值，所以要离散化处理y坐标
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
    int flag;   //1 覆盖 -1 撤销覆盖
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
    int l,r;                    //l,r表示这是表示第l个y坐标到第r个y坐标的连续超元线段组
    double ll,rr,len;           //ll,rr表示真正的坐标，即第l个y坐标的坐标值和第r个y坐标的坐标值，len就是真正长度了
    int lazy;       //lazy非0值表示有线段覆盖到本区间
}tree[8*110];

vector<double> y;       //相邻元素y[i]-y[i-1]就是一个竖直超元线段的长度
vector<LINE> line;
map<double,int> mir;        //映射，mir[x]表示拥有x值的y坐标是第mir[x]个y坐标

void build(int root , int l , int r)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].lazy=tree[root].len=0;
    tree[root].ll = y[l],tree[root].rr = y[r];

    if(r-l==1)              //判断条件和区间划分都不同了，因为叶子节点是单位线段而非一个点
        return ;

    int mid = MID(l,r);
    build(lson(root),l,mid);
    build(rson(root),mid,r);        //是mid而非mid+1
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
        //tree[root].len = tree[root].lazy?(tree[root].rr-tree[root].ll):0;   //注意lazy*(rr-ll)就会重复计算了，因为可能多次覆盖，lazy的值可能>1
        return ;
    }
    int mid = MID(tree[root].l,tree[root].r);

    if(mid > l)                 //是> 而非 >=
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
            //把矩形左边的线段标记为1，右边的标记为-1
            line.push_back(LINE(x1,y1,y2,1));
            line.push_back(LINE(x2,y1,y2,-1));
            //纵坐标压入vector以便排序，由于同一矩形的超元线段一定是紧邻的，所以没必要担心断档计数的问题
            y.push_back(y1),y.push_back(y2);
        }
        sort(line.begin(),line.end());
        sort(y.begin(),y.end());
        y.erase(unique(y.begin(),y.end()),y.end());     //去重，搞映射的话其实没必要

        for(int i = 0 ; i < y.size() ; i++) mir[y[i]]=i;
        build(1,0,y.size()-1);

        double area=0;
        for(int i = 0 ; i < line.size() ; i++)
        {
            if(i) area += (line[i].x-line[i-1].x)*tree[1].len;
            modify(1,mir[line[i].y1],mir[line[i].y2],line[i].flag); //区间端点就是左y的id和右y的id
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",++tt,area);
    }
    return 0;
}
