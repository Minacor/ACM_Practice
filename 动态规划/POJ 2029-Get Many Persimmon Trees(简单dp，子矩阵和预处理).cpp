/*
 * ���⣺
 * ��һ��w*h�ľ���������һЩ������һ��s*t�Ŀ�ȥ���������
 * �����п�����Ӿ�����������������ֵ
 *
 * ˼·��
 * ��dp��Ԥ���������(1,1,x,y)�ڵ�����������Ȼ�������Ӿ�����������������Ҳ����״����汾
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
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;
const int inf = 1e15;

int g[110][110];
int dp[110][110];       //��ʾ����(1,1,x,y)����������
int n;
int w,h;

int main()
{
    //FR;
    while(~scanf("%d", &n) && n)
    {
        memset(g,0,sizeof g);
        memset(dp,0,sizeof dp);
        scanf("%d%d",&w,&h);
        for(int i = 0 ; i < n ; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a][b]=1;
        }
        for(int i = 1 ; i <= w ; i++)
            for(int j = 1 ; j <= h ; j++)       //ת�Ʒ��̻���ͼ��������
                dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+g[i][j];
        int maxc=-1;
        int sx,sy;
        scanf("%d%d",&sx,&sy);
        for(int i = 0 ; i+sx<= w ; i++)
            for(int j = 0 ; j+sy <= h ; j++)    //�Ӿ������������ͬ�ڶ�ά��״������Ӿ������
                maxc = max(maxc , dp[i+sx][j+sy]-dp[i][j+sy]-dp[i+sx][j]+dp[i][j]);
        printf("%d\n",maxc);
    }
    return 0;
}
