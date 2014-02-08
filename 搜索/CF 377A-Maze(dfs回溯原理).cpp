/*
 * ���⣺
 * ��һ���������ݣ�ͼ������������n,m,Ҫ���k��ǽ
 * ��һ��ͼ��ͼ�� '.' ��ʾ��ͨ�� '#'��ʾǽ
 * Ҫ�����k��ǽ�Ժ���еĵط�����ͨ�ģ�������ǽ�Ժ�ĵ�ͼ
 *
 * ˼·��
 * dfs��׷����֮���ڻ��ݣ����Կ����ڻ���������ʱ������ǽ�������ͱ�֤��֮ǰ�Ŀ��еĵط���ͨ
 * �������ݰ�����������ԭͼ���еط�����ͨ�ģ��ʲ��ÿ��Ƕ����ͨ��
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
const int MAX = 100000+100;
const int inf = 522133279;

string g[510];
int vis[510][510];
int dir[4][2] = {1,0,0,1,-1,0,0,-1};

int n,m,k;

void dfs(int x,int y)
{
    if(k == 0)
        return ;
    vis[x][y] = 1;

    for(int i = 0 ; i < 4 ; i++)
    {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];

        if(tx >= 0 && tx < n && ty >= 0 && ty < m && !vis[tx][ty] && g[tx][ty]!='#')
        {
            dfs(tx,ty);
        }
    }

     if(k)      //ע���ǽ�Ĵ���д����
        g[x][y] = 'X',k--;

}
int main()
{
    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; i++)
        cin >> g[i];
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            if(g[i][j] == '.')
                dfs(i,j);

    for(int i = 0 ; i < n ; i++)
        cout << g[i] << endl;
    return 0;
}
