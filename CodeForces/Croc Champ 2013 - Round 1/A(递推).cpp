/*
 * ���⣺
 * ÿһ����������Ϣ�����ʱ�����Ϣ����
 * ÿ��ֻ�ܴ���һ����Ϣ
 * ����ʱ���Լ���Ϣ�ۻ���������
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
int dis[2000000+100];

int main()
{
    cin >> n;
    int leiji,maxsize; //leiji��¼�����굱ǰ����������������ʱ�䣬maxsize��¼��Ϣ����ʱ�������Ϣ��

    for(int i = 0 ; i < n ; i++)
    {
        int a,b;
        cin >> a >> b;
        if(!i)
        {
            leiji = a+b;
            maxsize = b;
        }
        else
        {
            if(leiji > a)
            {
                maxsize = max(maxsize,leiji-a+b);   //���ۼ�ʱ��-��ǰʱ�䣩���ǿ��ڶ��������Ϣ����������˲������b��
                leiji = leiji+b;

            }
            else
            {
                maxsize = max(maxsize,b);       //���������û�б�������Ϣ
                leiji = a+b;
            }
        }

    }
    cout << leiji << ' ' << maxsize << endl;
    return 0;
}
