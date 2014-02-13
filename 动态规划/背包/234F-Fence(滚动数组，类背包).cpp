/*
 * ���⣺
 * ��������ɫ��Ϳ�������a,b��һȺ���x1~xn��ÿ����ʵĿ�Ϊ1,��Ϊxi,ÿ�����Ϳһ����ɫ
 * ������ʼ���һ��ֵans���������������ɫ��ͬ��Ϊ0������Ϊmin(xi,xj)
 * ���ʹans����С�Ĵ𰸣�����Ϳ�����-1
 *
 * ˼·��
 * dp[i][j][k] :ǰi���������j���a��ɫ���ҵ�ǰ��ɫ��k(0:a 1:b)��ɫʱ����Сans��
 * ����i<=200,j<=40000,k<2 �ҵ��Ʒ���ֻ��ǰһ״̬�йأ���ʹ�ù�������
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
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int n;
int dp[2][40000][2];
int a,b;
int lis[210];
int sum;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n;
    cin >> a>>b;
    for(int i = 1 ; i <= n ; i++)
        cin >> lis[i],sum+=lis[i];

    clr(dp[0],-1);  //��ʼ��Ϊ���ɴ�״̬-1
    dp[0][0][0] = dp[0][0][1]=0;    //0�����0 a��ɫ����ʱans�;���0
                                    //������lis[0]=0,��min(lis[0],lis[1])=0,����Ҫ��ʼ��1�����ʱ��dpֵ
    int gun=0;
    for(int i = 1 ; i <= n ; i++)
    {
        gun=1-gun;
        clr(dp[gun],-1);        //ע��ÿ��ʹ�ö�Ҫ��ʼ��Ϊ���ɴ�״̬

        for(int j = 0 ; j <= a ; j++)       //�౳������Ҫע����ͬ��ɫʱans������㣬��ͬ��ɫʱ��Ҫ����min(xi,xj)
        {
            if(dp[1-gun][j][0] != -1)
            {
                if(dp[gun][j+lis[i]][0] == -1 || dp[gun][j+lis[i]][0]>dp[1-gun][j][0])
                    dp[gun][j+lis[i]][0] = dp[1-gun][j][0];
                if(dp[gun][j][1] == -1 || dp[gun][j][1]>dp[1-gun][j][0]+min(lis[i],lis[i-1]))
                    dp[gun][j][1]=dp[1-gun][j][0]+min(lis[i],lis[i-1]);
            }

            if(dp[1-gun][j][1] != -1)
            {
                if(dp[gun][j][1] == -1 || dp[gun][j][1]>dp[1-gun][j][1])
                    dp[gun][j][1] = dp[1-gun][j][1];
                if(dp[gun][j+lis[i]][0] == -1 || dp[gun][j+lis[i]][0]>dp[1-gun][j][1]+min(lis[i],lis[i-1]))
                    dp[gun][j+lis[i]][0]=dp[1-gun][j][1]+min(lis[i],lis[i-1]);
            }
        }
    }

    int ans=-1;
    //��ʱ��gunΪĩ״̬
    for(int i = 0 ; i <=a ; i++)
        if(sum-i <= b)
        {
            if(dp[gun][i][0] != -1 && (ans==-1 || ans > dp[gun][i][0]))
                ans = dp[gun][i][0];
            if(dp[gun][i][1] != -1 && (ans==-1 || ans > dp[gun][i][1]))
                ans = dp[gun][i][1];
        }
    cout << ans << endl;
    return 0;
}
