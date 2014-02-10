
  题意：
  一个平面坐标系上有若干炸弹，有这样的操作：
  1 k dir 向dir方向走k步，方向定义为：U上 D下 L左 R右 ，途中不能有炸弹当道
  2 拿起炸弹
  3 清除炸弹，必须回到0点才能操作
 
  求出清除所有炸弹最少的执行步数
 
  思路：
  必须回到0点才能清除炸弹使得题目大大简化
  每一个炸弹的清除，其最少步数一定是直线到达或直角到达
  这里就要保证执行的时候中途没有炸弹了，很方便，排一下序就行了
  要注意坐标可能为负数，所以排序判断稍微有点麻烦
 

#include iostream
#include cstring
#include algorithm
#include cmath
#include cstdio
#include sstream
#include queue
#include vector
#include string
#include stack
#include cstdlib
#include deque
#include fstream
#include map
#include set
#define lson(x) (x1)
#define rson(x) (x11)
#define MID(x,y) ((x+y)1)
#define FR (freopen(in.txt,r,stdin))
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 200000+100;
const int inf = 522133279;
const int mod = 1000000007;

char mir[100];
int cnt=0;

struct node
{
    int x,y;
    由于不同象限的点肯定不会相互影响
    那么只要加绝对值，映射成第一象限的点来处理就行了
    bool operator(const node&b)const
    {
        if(abs(x)==abs(b.x))
            return abs(y)  abs(b.y);
        return abs(x)  abs(b.x);
    }
}p[100000+100];

void init()
{
    mir['U'] ='D';
    mir['D'] = 'U';
    mir['R'] = 'L';
    mir['L'] = 'R';
}

void walk(int x , int y)
{
    char c1=0,c2=0;
    if(x  0) c1 = 'R';
    else if( x  0) c1 = 'L';
    if(y  0) c2 = 'U';
    else if(y  0) c2 = 'D';

    if(c1)
        cout  1   abs(x)   c1  endl;
    if(c2)
        cout  1   abs(y)   c2  endl;
    cout  2  endl;

    if(c2)
        cout  1   abs(y)   mir[c2]  endl;
    if(c1)
        cout  1   abs(x)   mir[c1]  endl;
    cout  3  endl;
}

int main()
{
    int n;
    cin  n;
    init();

    for(int i = 0 ; i  n ; i++)
    {
        cin  p[i].x  p[i].y;
        cnt += 2(p[i].x!=0) + 2(p[i].y!=0) + 2;
    }
    sort(p,p+n);
    cout  cnt  endl;
    for(int i = 0 ; i  n ; i++)
        walk(p[i].x,p[i].y);

    return 0;
}
