/*
 * ���⣺
 * �������ݣ�ÿ�����ݵ�һ�������ʼ�ʽ�money��Ͷ������year
 * �ڶ��п�ѡ�Ĺ�Ʊ��n
 * n�У�ÿ�ɹ�Ʊ�Ĺ����ʽ�c��һ���ܻ�õ�����w
 *
 * ��year����ܻ�õ�������󣬺�һ��ı�����ǰһ��ı���+�������
 *
 * ˼·��
 * ��Ʊ���������޹ɣ�����һ����ȫ�������⣬����������ÿ������ı���
 *
 * �ر�ע����ǹ�Ʊ�۸���1000�ı��������Կ��Խ�ÿ���ʼ�ʽ�v�͹�Ʊ�۸񶼳���1000��dp�������T
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
const int inf = 50000000;

int dp[50000+100];
int t,n;

struct node
{
    int c;
    int w;
}pro[15];

int cptpack(int v)
{
    v/=1000;
    for(int i = 0 ; i < n ; i++)
        for(int j = pro[i].c/1000 ; j <= v ; j++)               //ע�����j+=1000�Ǵ�ģ���
            dp[j] = max(dp[j] , dp[j-pro[i].c/1000] + pro[i].w);
    return dp[v];
}

int main()
{
    int t;
    scanf("%d",&t);

    int money,year;
    while(t--)
    {
        memset(dp,0,sizeof dp);
        scanf("%d%d",&money,&year);
        scanf("%d",&n);

        for(int i = 0 ; i < n ; i++)
            scanf("%d%d",&pro[i].c,&pro[i].w);
        while(year--)
        {
            money += cptpack(money);
        }

        printf("%d\n",money);
    }

    return 0;
}
