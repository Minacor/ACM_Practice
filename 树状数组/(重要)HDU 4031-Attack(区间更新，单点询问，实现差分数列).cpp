/*
 * ���⣺
 * ��һ�泤n��ǽ��ÿ��λ��������һ�������ܣ����ǵ���ȴʱ�䶼��cd�����ɹ�����һ���Ժ���뾭��cdʱ�������ٴη���
 * ������q����������֣�
 * 1��Attack l r ����(l,r)��ǽ
 * 2��Query cur ѯ��cur���λ���ܵ��˼��ι�����������ס�Ĳ���
 * ÿ����һ��ʱ��+1��ѯ�ʲ���ʱ��
 *
 * ˼·��
 * ����״����ά��ÿ����λ�������Ĵ������������״����ĵ���ѯ�ʣ��������(����)��ԭ��Ͳ��������ȫһ��
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
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 200000+100;
const int inf = 522133279;

int t;
int n,q,cd;
char com[20];
int tree[21000];
int can[21000];         //can[i]��ʾ�����ʱ�䣬i�ķ������ܹ����з���������һ��ʼ�Ϳ��Է������ʿ��Գ�ʼ��Ϊ0
int protect[21000];     //protect[i] ��ʾ��ֹ��ǰʱ��i�ķ�����һ�������ɹ��Ĵ���

struct node
{
    int l,r;
}att[21000];

int getsum(int pos)
{
    int tt=0;
    for( ; pos > 0 ; pos -= lowbit(pos))
        tt += tree[pos];
    return tt;
}

void modify(int pos , int delta)
{
    for( ; pos <= n ; pos += lowbit(pos))
        tree[pos]+= delta;
}

int main()
{
    //FR;
    scanf("%d",&t);

    for(int ka = 1 ; ka <= t ; ka++)
    {
        scanf("%d%d%d",&n,&q,&cd);
        int time=0;
        clr(tree,0); clr(can,0); clr(protect,0);

        printf("Case %d:\n",ka);
        for(int i = 1 ; i <= q ; i++)
        {
            scanf("%s",com);
            if(com[0] == 'A')
            {
                time++;
                int l,r;
                scanf("%d%d",&l,&r);
                att[time].l=l;att[time].r=r;
                modify(l , 1);
                modify(r+1,-1);
            }
            else                            //ÿ��ѯ�ʶ����һ�������
            {
                int cur;
                scanf("%d",&cur);

                // i��ʾcur�ķ����ܿ��������ʱ�����з�����i����Զһ��δ��������Ŀ��Է�����ʱ��㿪ʼ�������ظ�����
                for(int i = can[cur] ; i <= time ; i++)
                {
                    if(cur >= att[i].l && cur <= att[i].r)  //���cur�ڵ�ǰ������Է�����ʱ���Ĺ���������
                    {
                        protect[cur]++;
                        can[cur] = i + cd;          //��ȴ
                        i = can[cur]-1;             //i�ƽ�����һ�����Է�����ʱ��㣬ע��-1����Ϊ������i++
                    }
                }
                printf("%d\n",getsum(cur)-protect[cur]);
            }
        }
    }

    return 0;
}
