/*
 * ���⣺��������n��m��k����һ��n*m�ľ���ÿһ�д���һ�����С�
 * ���ڸ�������(i,j) �� ѡ������i��j��������������ÿ�������е�����Ԫ�أ����������������xulie[i]>xulie[j]���ͽ�����������
 * Ҫ�����ɴβ������������а������������(��k������k=0����=1����)
 * ���ĳ�������������֣�������������
 *
 * ˼·��m���100��ֱ�ӱ�ö��������ѭ��ö�������жԣ�����ÿ���ж���ö��ÿһ������(n��)���ܽ����ľͽ���
 * �������Ĳ������ٽ�������Ϊ�����漰�������е�����һ��Ԫ�صĽ�������ʹ��ֵ����
 *
 * �����ر�ע����Ƕ�һ�����ԣ�ǰ�ߴ��ں��߲��ܽ����������������Ļ�������ĵ��Ҫ��һ��
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

struct node
{
    int x;
    int y;
};

int n,m,order;
int lis[1010][110];
vector<node> out;

int main()
{
    cin >> n >> m >> order;

    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
        {
            cin >> lis[i][j];
        }

    int ok=0;
    for(int i = 1 ; i <= m ; i++)
        for(int j = i+1 ; j <= m ;j++)
        {
            ok=0;
            for(int k = 1 ; k <= n ; k++)
            {
                if(!order && lis[k][i] > lis[k][j])
                {
                    ok=1;
                    swap(lis[k][i],lis[k][j]);
                }
                else if(order && lis[k][i] < lis[k][j])
                {
                    ok=1;
                    swap(lis[k][i],lis[k][j]);
                }
            }

            if(ok)
            {
                node tmp;
                if(!order)
                    tmp.x=i,tmp.y=j;
                else if(order)          //�������Ҫ��һ��
                    tmp.y=i,tmp.x=j;
                out.push_back(tmp);
            }
        }

    cout << out.size() << endl;
    for(int i = 0 ; i < out.size() ; i++)
        printf("%d %d\n",out[i].x,out[i].y);

    return 0;
}
