/*
 * ���⣺
 * ��һ��1~n���������У�����෭ת2n-3�εĲ���ʹ��������������
 * ��ת�ķ����ǣ�pos��ÿ�η�תǰpos����
 *
 * ˼·��
 * ��������Ѱ��n~1,�ѵ�ǰ���ŵ�����Ȼ��ת�������Լ���λ��
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
#include "cstdlib"
#include "ctime"
#define lson(x) (x<<1)
#define rson(x) (x<<1|1)
#define MID(x,y) ((x+y)>>1)
#define FR (freopen("in.txt","r",stdin))
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long ll;
const int MAX = 50;
const int inf = 522133279;
const int mod = 1000000007;

int lis[MAX];
int n;
vector<int> out;

int _find(int aim)
{
    for(int i = 1 ; i <= n ; i++)
        if(lis[i] == aim)
            return i;
}

int main()
{
    while(scanf("%d",&n),n)
    {
        out.clear();
        int aim=n;
        for(int i = 1 ; i <= n ; i++)
            scanf("%d",&lis[i]);

        for(int i = n; i >= 1 ; i--)
        {
            int pos=_find(i);
            if(pos == i)
                continue;
            else if(pos != i && pos != 1)
            {
                out.push_back(pos);
                reverse(lis+1,lis+pos+1);
                out.push_back(i);
                reverse(lis+1,lis+1+i);
            }
            else if(pos != i && pos == 1)
            {
                out.push_back(i);
                reverse(lis+1,lis+1+i);
            }
        }

        printf("%d",out.size());
        for(int i = 0 ; i < out.size() ; i++)
            cout << ' ' << out[i];
        cout << endl;
    }
    return 0;
}
