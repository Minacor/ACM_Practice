/*
 * ���⣺
 * ���룺
 * ��һ����t������
 * ÿ�����ݵ�һ�����������ܼ��ɵĲ�������n �󲼵ĳ��Ϳ�X,Y
 * ������n��ÿ���������� �ܼ��ɵĲ��ĳ��Ϳ�x��y����鲼�ļ�ֵc
 * ��󲼼���С���ܻ�õ�����ֵ
 *
 * ˼·��
 * һ����ܼ��ɲ���������С����������һ����ȫ��������
 * dp���̱�ʾҪ�����ã�Ҫ���������ֲ÷�
 * ���ֲ÷���ͼʾ http://www.2cto.com/kf/201303/198648.html
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
const int MAX = 1000;
const int inf = 522133279;

struct node
{
    int x,y,c;
}a[20];

int dp[1100][1100];
int n,X,Y;

int main()
{
    FR;
    int t;
    scanf("%d",&t);

    while(t--)
    {
        memset(dp,0,sizeof dp);
        scanf("%d%d%d",&n,&X,&Y);

        for(int i = 0 ; i < n ; i++)
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);

//        for(int i = 1 ; i <= n ; i++)       ע�������ص���ȫ�������ѭ�����ڲ�ѭ��˳����Ե����������ﲻ����
//        {
            for(int tx = 0 ; tx <= X ; tx++)        //����С���ǿ�����ת�ģ�Ҳ��i*j���Ե���j*i���㣬�����������Դ�0��ʼ�����ڲ���ϸ�ж�
                for(int ty = 0 ; ty <= Y ; ty++)
                {
                    for(int i = 0 ; i < n ; i++)
                    {
                        if(tx >= a[i].x && ty >= a[i].y)    //�����ǰö�ٵ��Ĳ��ܹ��ó�С��a[i]��
                            dp[tx][ty] = max(dp[tx][ty],max(dp[tx-a[i].x][ty]+dp[a[i].x][ty-a[i].y]+a[i].c , dp[tx-a[i].x][a[i].y]+dp[tx][ty-a[i].y]+a[i].c));
                        if(tx >= a[i].y && ty >= a[i].x)    //�����ǰö�ٵ��Ĳ��ܹ��ó�a[i]��ת90����С����
                            dp[tx][ty] = max(dp[tx][ty],max(dp[tx-a[i].y][ty]+dp[a[i].y][ty-a[i].x]+a[i].c , dp[tx-a[i].y][a[i].x]+dp[tx][ty-a[i].x]+a[i].c));
                    }
                }
//        }

        printf("%d\n",dp[X][Y]);
    }

    return 0;
}
