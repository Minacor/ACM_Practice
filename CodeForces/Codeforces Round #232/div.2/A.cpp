/*
 * ���⣺
 * ����n���߶ε����Ҷ˵㣬��һ����(a,b)
 * ���һ���߶���δ�������߶θ��ǵĳ���
 *
 * ˼·��
 * ֱ�ӱ�����Ǳ����ǵĵ�Ϊ1
 * �����󳤶ȣ�ע���߶����˵�ֻ�ܱ��һ��
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
//const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int x[110];
int main()
{
    int n;
    cin >> n;
    int a,b;
    cin >> a >> b;
    for(int i = 0 ; i < n-1 ; i++)
    {
        int aa,bb;
        cin >> aa >> bb;
        for(int i = aa ; i < bb ; i++)
            x[i]=1;
    }
    int cnt=0;
    for(int i = a ; i < b ; i++)
        if(!x[i]) cnt++;

    cout << cnt << endl;
    return 0;

}
