/*
 * ���⣺
 * ��һ�����18λ��n��<=100��m�����м���������x:
 * 1, �ܹ�������������õ�n
 * 2, û��ǰ����
 * 3, x%m==0
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
const int MAX = 100+100+2*100+100;
const int inf = 522133279;
const int mod = 1000000007;

LL dp[1<<18][110];  //dp[i][j],��ǰѡ��״̬������Ϊj������
LL re=1;            //ȥ�أ�������ͬ����ȫ����
int cnt[10];        //��¼�ظ�����
LL jiecheng[20];    //A(n,n)Ԥ����

int main()
{
    jiecheng[0]=1;
    for(int i = 1 ; i < 20 ; i++)
        jiecheng[i]=jiecheng[i-1]*i;

    string line;
    int m;
    cin >> line >> m;
    int len = line.size();

    for(int i = 0 ; i < len ; i++)
        cnt[line[i]-'0']++;
    for(int i = 0 ; i < 10 ; i++)
        re *= jiecheng[cnt[i]];

    dp[0][0]=1;     //ʲô����ûѡʱ0%m����Ϊ0��һ�����
    int up = 1<<len;
    for(int i = 1 ; i < up ; i++)
        for(int j = 0 ; j < len ; j++)
            if(i & (1 << j))
            {
                int last = i - (1 << j);        //ע��ö��j��ʱ���Ѿ��涨˳����
                if((last==0&&line[j]!='0')||last)   //��һ״̬Ϊ0�Ļ�����״̬��������Ƿ���������Ϊû��ǰ����
                    for(int k = 0 ; k < m ; k++)    //ö����һ״̬������
                        dp[i][(k*10+(line[j]-'0'))%m] += dp[last][k];
            }
    cout << dp[up-1][0]/re << endl;
    return 0;
}
