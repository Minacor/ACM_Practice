
  ���⣺
  һ��ƽ������ϵ��������ը�����������Ĳ�����
  1 k dir ��dir������k����������Ϊ��U�� D�� L�� R�� ��;�в�����ը������
  2 ����ը��
  3 ���ը��������ص�0����ܲ���
 
  ����������ը�����ٵ�ִ�в���
 
  ˼·��
  ����ص�0��������ը��ʹ����Ŀ����
  ÿһ��ը��������������ٲ���һ����ֱ�ߵ����ֱ�ǵ���
  �����Ҫ��ִ֤�е�ʱ����;û��ը���ˣ��ܷ��㣬��һ���������
  Ҫע���������Ϊ���������������ж���΢�е��鷳
 

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
    ���ڲ�ͬ���޵ĵ�϶������໥Ӱ��
    ��ôֻҪ�Ӿ���ֵ��ӳ��ɵ�һ���޵ĵ������������
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
