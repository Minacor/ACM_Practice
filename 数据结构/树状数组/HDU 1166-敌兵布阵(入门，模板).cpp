/*
 * ���⣺��������
 *
 * ˼·����״�������ţ�ģ����
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
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;

tree[50010];            //ע����״�����Ǵ�1��ʼ��ŵģ���
int n;

int lowbit(int t)
{
    return t&(t^(t-1));  //���߸��򵥵� (-t)&t;
}

int getsum(int pos)     //���1~pos�ĺ�
{
    int t;

    for(t=0 ; pos>0 ; pos -= lowbit(pos))
        t += tree[pos];

    return t;
}

void modify(int pos , int delta)   //����posλ���Ժ����ֵ �� �仯��Ϊdelta��ע�������ϸ��£���get�����²���
{
    for( ; pos <= n ; pos += lowbit(pos))
        tree[pos] += delta;
}

int main()
{
    int t;
    scanf("%d",&t);

    for(int ka = 1 ; ka <= t ; ka++)
    {
        memset(tree,0,sizeof tree);
        scanf("%d",&n);

        for(int i = 1 ; i <= n ; i++)           //��״����Ĺ��췽��
        {
            int tmp;
            scanf("%d",&tmp);
            modify(i,tmp);
        }


        string cmd;

        printf("Case %d:\n",ka);

        while(cin >> cmd && cmd != "End")
        {
            int a,b;
            scanf("%d%d",&a,&b);

            if(cmd == "Query")
            {
                cout << getsum(b) -getsum(a-1) << endl;
            }
            else if(cmd == "Sub")
            {
                modify(a,-b);
            }
            else
            {
                modify(a,b);
            }

        }
    }

    return 0;
}




