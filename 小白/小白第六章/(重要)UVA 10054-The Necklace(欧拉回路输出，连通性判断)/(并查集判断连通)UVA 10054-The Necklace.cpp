/*���⣺��һ��ɢ��������ĵ����ӣ������п����ظ��ĳ��֣��������ܷ����ӳ�һ��������Ҫ���������ÿһ�ڵ���������Ҫ���㣻

������ͼ��
���壺�����޹������ͼG��������һ��·������ͼ��ÿ����һ���ҽ���һ�Σ�����·��ŷ��·��������һ����·������ͼ��ÿ��һ���ҽ���һ�Σ��û�·��Ϊŷ����·������ŷ����·��ͼ��Ϊŷ��ͼ�����ǰ���ͼ��
��������ͼG����һ��ŷ��·�����ҽ���G����ͨ�ģ�����0�����������������ȵý�㡣
���ۣ�����ͼG����һ��ŷ����·�����ҽ���G����ͨ�ģ��������н��Ķ�����Ϊż����

һ�ʻ�������ǵ��͵��������⣺Ҫ�ж�һ��ͼG�Ƿ��һ�ʻ���������������� ��ͼ��ĳһ��������������ͼG��ÿ����һ���ٻص��ý�㣬�����Ǵ�G��ĳһ��������������G��ÿ��һ���ҽ�һ�ε�����һ����㣬�ֱ��Ӧ��ŷ����·��ŷ��·������
 ������ͼ��
���壺��������ͼG��ͨ��ͼ��ÿ��һ���ҽ�һ�ε�һ������·����·������������ŷ��·����·����
��������ͼG���� ����ŷ��·�����ҽ���������ͨ�ģ����ҳ���������⣬ÿ��������ȵ��ڳ��ȣ�������������У�һ��������ȱȳ��ȴ�1����һ��������ȱȳ���С1��
��������ͼG����һ������ŷ����·�����ҽ�������ͨ�ģ���ÿ�������ȵ��ڳ��ȡ�
�Լ�Fleury�㷨��
����������1����ȡv0��V(G)����P0=v0��
����������2����Pi=v0e1v1e2...eivi�Ѿ��б飬�����淽������E(G)-{e1,e2,...,ei}��ѡ
 ��������    ȡei+1��
  ��������  ��a��ei+1��vi�������
  ��������  ��b�������ޱ�ı߿ɹ��б飬����ei+1��Ӧ��ΪGi=G-{e1,e2,...,ei}�е���.
����������3������2�������ٽ���ʱ���㷨ֹͣ��
�������ݣ��õ��԰�ÿһ���������������������Ҹ���Ȼ��һ��Ϊ��㿪ʼ�����������ܼ���ʱ��������һ�㣬���Ǻ�����ղ��޷������������Ǹ��꣬Ҳ��������Ϊ��㣬����dfs�ĵݹ鷵��ʱ�Ĺ������������㷨�Ȼ��ݿ�Щ*/

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

int f[60];
int g[1010][1010];
int use[1010];
int n;

int find(int x)
{
    return (x == f[x]) ? x : f[x] = find(f[x]);
}

int merger(int x , int y)
{
    x = find(x);
    y = find(y);

    if(x!=y)
        f[x]=y;
}

int vis[100],in[100];
queue<int> out;

void oula(int cur)          //Ѱ������һ��ŷ����·˳��ģ��
{
    for(int i = 0 ; i < 60 ; i++)
        if(g[cur][i])
        {
            g[cur][i] = g[i][cur] = g[i][cur]-1;
            oula(i);
            printf("%d %d\n" ,i,cur);
        }

}

int main()
{
    freopen("input.txt","r",stdin);

    int t;
    cin >> t;

    for(int ka = 1  ; ka <= t ; ka++)
    {
        int a,b;
        memset(vis,0,sizeof vis);
        memset(use,0,sizeof(use));
        memset(in,0,sizeof in);
        memset(g,0,sizeof g);

        for(int i = 0 ; i < 60 ; i++)
            f[i] = i;

        cin >>n;

        for(int i = 0 ; i < n ; i++)
        {
            cin >> a >> b;
            g[a][b] = g[b][a] = g[a][b]+1;
            vis[a]=vis[b]=1;
            in[a]++,in[b]++;
            merger(a,b);
        }

        int cnt=0;
        for(int i = 0 ; i < 60 ; i++)
            if(vis[i] && f[i] == i)
                cnt++;
        if(cnt > 1)         //��ͨ�Ļ���ֻ��һ��������������Լ�
            printf("Case #%d\nsome beads may be lost\n",ka);
        else
        {
            int ok = 1;
            for(int i = 0 ; i < 60 ; i++)
            {
                if(vis[i] && in[i]%2)           //ŷ��ͼ�����ж���Ķ�������ż��
                {
                    ok = 0;
                    break;
                }
            }

            if(!ok)
                printf("Case #%d\nsome beads may be lost\n",ka);
            else
            {
                printf("Case #%d\n",ka);

                for(int i = 0 ; i < 60 ; i++)
                    if(vis[i])
                        oula(i);
            }
        }

        if(ka < t)
            cout << endl;
    }

    return 0;
}
