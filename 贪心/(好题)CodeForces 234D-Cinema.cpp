/*
 * ���⣺
 * ��һ������������Ա����n��С��ϲ��������m
 * �ڶ���m���˵ı�ţ���Ա�����Ǵ�1~n��ŵ�
 * ֮��ÿ����һ����Ӱ��Ϣ
 * ��һ�е�Ӱ��
 * �ڶ����м�����Ա�μ����ⳡ��Ӱ
 * ��������Щ��Ա�ı�ţ�0��ʾС���������ı��
 *
 * ����ÿһ����Ӱ�������
 * 0����ʾ��һ����С����ϲ���ĵ�Ӱ 1����ʾ��һ������С����ϲ���ĵ�Ӱ 2���п������п��ܲ���
 * ��ϲ���ĵ�Ӱ���壺û��������Ӱ��������ϲ����Ա���������ⲿ��Ӱ
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

int n,m;
bool fav[110];

struct movie
{
    string name;
    int star;
    bool has[110];
    int surehas;
    int maxhas;
}mov[110];

int main()
{
    freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
    cin >>n >> m;
    for(int i = 0 ; i < m ; i++)
    {
        int a;
        cin >> a;
        fav[a]=1;
    }
    int num;
    cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        cin >> mov[i].name >> mov[i].star;
        int zuiai=0,zero=0,buai=0;
        for(int j = 0 ; j < mov[i].star ;j++)
        {
            int a;
            cin >> a;
            if(fav[a])
                zuiai++;       //��ǰ��Ӱ���е����Ա��
            else if(!a)
                zero++;         //0�ĸ���
            else
                buai++;         //��ǰ��Ӱ���еĲ�ϲ������Ա��
        }

        //�������е���ϲ����Ա = ��ǰ���е������Ա��+�ܹ���ûѡ�����Ա���滻0���������
        mov[i].maxhas = zuiai + (zero > (m-zuiai)?(m-zuiai):zero);
        //����ӵ����=��ǰ���е����Ա��+(zero-����ܹ��滻��0��δѡ�Ĳ�ϲ������Ա����)
        // n-m-buai����ʣ��δѡ�Ĳ�ϲ������Ա���������������ȫ�滻��0����ôʣ���0�����������Ա
        mov[i].surehas = zuiai+((zero-(n-m-buai)) >= 0 ? (zero-(n-m-buai)) : 0);
    }

    for(int i = 0 ; i < num ; i++)
    {
        int ok=0;
        for(int j = 0 ; j < num ; j++)
        {
            if(i==j) continue;
            //�������ȷ�������������С��ĳһ��Ӱ��ȷ��������һ����������ϲ������
            if(mov[i].surehas < mov[j].surehas && mov[i].maxhas < mov[j].surehas)
            {
                ok=1;
                break;
            }
            //��Ȼ�����ȷ����С��ĳһ��Ӱ����������������п��ܱ���Խ�ģ�������2
            if(mov[i].surehas < mov[j].maxhas)
                ok=2;
        }
        if(mov[i].surehas == m)
            ok=0;
        cout << ok << endl;
    }
    return 0;
}

