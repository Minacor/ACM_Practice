/*
 * ���⣺
 * �����Ǵ�����⣺
 * {
 *     ��n����(0~n-1)��m������
 *     M a b��ʾ����ab��
 *     S a��ʾɾ����a��ֱ�����������б�
 *     ��������ͨ��֧��
 *     ��ʼʱ�����е㲻��ͨ
 * }
 * ��ȷ��⣺
 * {
 *     M a b��ʾ��ab�Ž�ͬһ������
 *     S a��ʾ��a�������ڵļ�����ɾ��
 *     Ҳ����˵M 0 1,M 0 2, S 0֮��1,2,��������ͬһ���ϵ�
 *     ������ж��ٲ�ͬ����
 * }
 *
 * ˼·��
 * ���鼯ɾ��
 * ɾ����ǰ�ڵ㣬׼ȷ��˵�Ǵӵ�ǰ�ڵ㼯�����޳���ǰ�ڵ㣬�����ӽڵ㲻Ҫ����
 * ��ͨ�Ĳ��鼯�ںϲ���ʱ����Щ�ڵ������ӽڵ�ģ����ɾ��������ڵ�Ĺ�ϵ�������ĸ�������Ϊ�Լ�������ô�������ӽڵ�ϲ���ʱ����Ҳ��������ˡ�
 * ����ķ��������֣�����ֱ�ӵģ��������еĽڵ㣬find(x),�鲢��������Ȼ�����ܡ�
 * �����ڲ����ʱ��ÿһ���ڵ㶼��Ҷ�ӽڵ㣬��ôɾ����ʱ��ͺܷ��㣬������û�й鲢�������ӽڵ��ˡ�
 */

//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define mkp make_pair
using namespace std;
typedef long long LL;
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int n,m;
int f[2000000+100];
int vf=1000000+1;

int find(int x)
{
    return x!=f[x] ? f[x] = find(f[x]) : x;
}

void merger(int x , int y)
{
    int tx = find(x);
    int ty = find(y);

    if(tx!=ty)
    {
        if(tx > 1000000)            //�����ӳ�䵽�������ϵ������ͺϲ����ǿ�����
            f[ty] = tx;
        else if(ty > 1000000)
            f[tx] = ty;
        else                        //û�еĻ������½�һ�������������ϲ��������棬��֮���Ǳ�����ʵ���֮�佨����ϵ��
            f[tx]=f[ty] = vf++;
    }
}

void del(int x)                      //ɾ��һ���ڵ�Ļ���ֻ���½�һ����������������ڵ�ӳ�䵽�ǿ����ϾͿ�����
                                     //����ԭ��f[x]=vvf,�����Ļ���ֻ��x����ڵ�����vvf�����������ĵ㻹����vvf���ϣ���ϵû��
{
    f[x] = vf++;
}

bool ok[2000000+100];

int main()
{
    int tot=0;
    while(~scanf("%d%d",&n,&m) && (n||m))
    {
        clr(ok,false);
        getchar();

        for(int i = 0 ; i <= 2000000+10 ; i++)
            f[i]=i;
        for(int i = 0 ; i < m ; i++)
        {
            char op;
            scanf("%c",&op);

            if(op == 'M')
            {
                int a,b;
                scanf("%d%d",&a,&b);
                merger(a,b);
            }
            else
            {
                int a;
                scanf("%d",&a);
                del(a);
            }
            getchar();
        }

        int cnt=0,tt;
        for(int i = 0 ; i < n ; i++)
            if(!ok[tt=find(i)])
            {
                ok[tt]=1;
                cnt++;
            }
        printf("Case #%d: %d\n",++tot,cnt);
    }
    return 0;
}
