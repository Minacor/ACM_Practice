/*
 * ���⣺
 * ��һ������������n������������m������ϵ�У��ҳ�Ԫ�������������㼯
 * ʹ�õ㼯�е��κ�������ľ��벻������
 *
 * ˼·��
 * ����Ȼ��һ��ƽ�����������ֱ���ϲ����ܳ����������ϵĵ㣬���Լ���Ԫ�����Ϊmin(n,m)
 * �������ݽ�С�ı߰���һ�������εĶԽ��߾Ϳ����ˣ��������ܱ�֤�κε�֮��ľ���Ϊn*sqrt(2)
 * �Ҽ���Ԫ��ȡ�����ֵ
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
#define FR (freopen("in.txt","r",stdin))
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = (1<<15)+100;
const int inf = 522133279;

int main()
{
    int n,m;
    cin >> n >> m;
    int ok=0;
    if(n<m)
        swap(n,m);

    cout << m+1 << endl;
    int j=0;
    for(int i = m ; i >= 0 ; i--)
        cout << j++ << ' ' << i << endl;

    return 0;
}
