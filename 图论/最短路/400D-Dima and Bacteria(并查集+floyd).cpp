/*
 * ���⣺
 * ��һ��������n(ϸ������,��1~n���),m(ת������),k(������)
 * �ڶ���k���� ��ʾ��i��������c[i]��ϸ��
 * ������m������ת�Ƶķ��ã�ָ��u��ϸ���͵�v��ϸ��֮��ת����Ҫ����w
 * ���ͬ��������������ϸ��ת�Ʒ��ö���0�Ļ������Yes����������ת�Ƶ���С����
 * �����ĳ����ͬ����ϸ��ת�ƻ��Ѳ���0�Ļ��ͽ����No
 *
 * ˼·��
 * һ�����ϱ�ʾ�����ڵ�Ԫ��֮���ת�ƻ��Ѷ���0���ò��鼯�㶨
 * ����С���ѵĻ�����500^3��floyd
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
const int MAX = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int n,m,k;
int c[510];
int f[MAX];
int pos[MAX],p;
int g[510][510];

int find(int x)
{
    return x!=f[x] ? f[x]=find(f[x]) : x;
}

void merger(int x , int y)
{
    x = find(x);
    y = find(y);

    if(x!=y)
        f[y]=x;
}

int main()
{
    cin >> n >> m >> k;
    clr(g,0x1f);

    for(int i = 1 ; i <= n ; i++) f[i]=i;
    for(int i = 1 ;i <= k ; i++)
    {
        cin >> c[i];
        for(int j = 0 ; j < c[i] ; j++)
            pos[++p] = i;
    }

    for(int i = 0 ; i < m ; i++)
    {
        int x,y,v;
        cin >> x >> y >> v;

        if(!v) merger(x,y);
        g[pos[x]][pos[y]]=g[pos[y]][pos[x]]=min(v,g[pos[x]][pos[y]]);
    }

    int ok=1;
    for(int i = 2 ; i <= n ; i++)
        if(pos[i]==pos[i-1]&&find(i)!=find(i-1))
        {
            ok=0;
            break;
        }
    if(!ok) cout << "No" << endl;
    else
    {
        for(int mid=1 ; mid <= k ; mid++)
            for(int i = 1 ; i <= k ; i++)
                if(g[mid][i] < inf)
                    for(int j = 1 ; j <= k ; j++)
                        if(i!=j && g[i][j] > g[i][mid]+g[mid][j])
                            g[i][j]=g[i][mid]+g[mid][j];
        cout << "Yes" << endl;
        for(int i = 1 ; i <= k ; i++)
        {
            g[i][i]=0;
            for(int j = 1 ; j <= k ; j++)
                cout << (g[i][j]==inf?-1:g[i][j]) << ' ';
            cout << endl;
        }
    }
    return 0;
}
