/*
 * ���⣺
 * ��n����Ա���1~n������Ҫ����m��������ʹ��ÿ���˶������������ٽ��ֹ�һ��
 * ÿ���������ӣ���ͬ����������˾����ǽ��ֹ�һ��
 * �����С����m��m�е�ÿ��������Ϣ
 * ������Ϣ��һ����Ϊ����һ�ӵ�������֮�󼸸���Ϊ��Ա���
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

int n;

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    cin >> n;
    int r=0;

    while((1<<r) < n) r++;  //log(n)�Ĺ��취
    cout << r <<endl;

    for(int i = 0 ; i < r ; i++)
    {
        int cnt=0;
        //����0~n�������ԣ����ڵ�������(��ȷ��˵������������)�ض������һ��0һ��1�����
        //��ζ�������������Աһ�����ٽ���һ����
        for(int j = 0; j < n ; j++)     //����ÿһ����λi��ֻҪ���λ����1���ͼ��뵱ǰ�Ķ���
            if(j & (1 << i)) cnt++;
        cout << cnt << ' ';
        for(int j = 0 ; j < n ; j++)
            if(j & (1 << i)) cout << j+1 << ' ';
        cout << endl;
    }
    return 0;
}
