/*
 * ���⣺
 * ��n����m���ߣ�n�Ǳ�3������
 * �ֽ�n���˷ֳ�n/3�飬Ҫ���б��������˱�����һ�����һ�ַ��鷽����û�з����Ļ����-1
 *
 * ˼·��
 * ���鼯���б���������(ֱ�ӻ���)ѹ��ͬһ�����ϣ���ͬһ�����ϳ���3��Ԫ�ؾ�һ������
 * Ȼ�������˵ļ��϶���һ���˵ļ���Ҳ���У���Ϊ�ܻ���2���˵���ϲ��ܱ���ȫ
 * Ȼ����Ƿ����ˣ��������������
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
#define FO (freopen("out.txt","w",stdout))
#define clr(a,b) memset(a,b,sizeof(a))
#define mkp make_pair
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 1000000;
const int inf = 522133279;
const int mod = 1000000007;

int n,m;
int f[60] , cnt[60];
vector<int> o[60];
vector< vector<int> > oo[4];


int find(int x)
{
    return x!=f[x] ? f[x] = find(f[x]) : x;
}

void merger(int x , int y)
{
    x = find(x);
    y = find(y);

    if(x!=y)
        f[x]=y;
}

int main()
{
    cin >> n >> m;
    for(int i = 0 ; i <= n ; i++)
        f[i]=i;

    for(int i = 0 ; i < m ; i++)
    {
        int a,b;
        cin >> a >> b;
        merger(a,b);
    }

    for(int i = 1 ; i <= n ; i++)
        o[find(i)].push_back(i);
//    for(int i = 1 ; i <= n ; i++)
//        cout << o[i].size() << endl;

    int ok=1;
    for(int i = 1 ; i <= n ; i++)
    {
        if(o[i].size() > 3)
        {
            ok=0;
            break;
        }
        else if(!o[i].empty())
            oo[o[i].size()].push_back(o[i]);
    }

    if(!ok || oo[2].size() > oo[1].size())
        cout << -1 << endl;
    else
    {
        for(int i = 0 ; i < oo[3].size() ; i++)
        {
            for(int j = 0 ; j < oo[3][i].size() ; j++)
                cout << oo[3][i][j] << ' ';
            cout << endl;
        }

        int pos1=0,pos2=0;
        for( ; pos2 < oo[2].size() ; pos2++,pos1++)
            cout << oo[2][pos2][0] << ' ' << oo[2][pos2][1] << ' ' << oo[1][pos1][0]<<endl;
        int t=0;
        for( ; pos1 < oo[1].size() ; pos1++)
        {
            cout << oo[1][pos1][0] << ' ';
            t = (t+1)%3;
            if(!t) cout << endl;
        }
    }
    return 0;
}
