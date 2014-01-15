/*
 * ���⣺��һȺ����������������������ǰ����β��ĸ�ͺ󴮵�����ĸ��ͬ
 * �жϸ����Ĵ��ܷ�����һ��
 *
 * ˼·�������ŷ��ͼ�ж���1.��ͨ��2.����ĸ���ɶ��㣬������������ĸ�ĳ��Ⱥ�������һ���⣬��������Ķ����
 * ��ͨ����dfs��Ҳ���ò��鼯��ŷ��ͨ·����ǣ�����һ������������Լ�����������Ķ�����
 *
 * ��Ҫע����ǣ�������������ϵĵ�ģ�����-���=1�����ߣ����-����=1���Ļ�����ͼһ������ͨ��
 * ����֮��ĳ�����ж��������ж��Ƿ���������ͬʱ���ȱ������1���1
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

string line[100000+100];
int firstcnt[500],lastcnt[500];
int g[30][30];
int vis[30];
int liantong;
int ju[500],sum;

void dfs(int s)
{
    liantong++;
    vis[s]=1;
    for(int i = 0 ; i < 26 ; i++)
        if(!vis[i] && g[s][i])
        {
            dfs(i);
            break;
        }
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        memset(firstcnt,0,sizeof(firstcnt));
        memset(lastcnt,0,sizeof(lastcnt));
        sum=0;
        memset(ju,0,sizeof(ju));
        memset(g,0,sizeof g);

        for(int i = 0 ; i < n ; i++)
        {
            cin >> line[i];
            firstcnt[line[i][0]-'a']++;
            lastcnt[line[i][line[i].size()-1]-'a']++;
            ju[line[i][0]]++;ju[line[i][line[i].size()-1]]++;
            g[line[i][0]-'a'][line[i][line[i].size()-1]-'a'] = 1;
        }

        int maxliantong=0;
        for(int i = 0 ; i < 26 ; i++)
            if(ju[(i+'a')])
            {
                memset(vis,0,sizeof(vis));
                liantong=0;
                sum++;
                dfs(i);
                maxliantong = max(maxliantong,liantong);
            }

        if(sum != maxliantong)
        {
            cout << "The door cannot be opened." << endl;
            continue;
        }

        int cnt1=0;
        for(int i = 0 ; i < 26 ; i++)
            if(abs(firstcnt[i]-lastcnt[i]) == 1)
                cnt1++;
            else if(abs(firstcnt[i]-lastcnt[i]) > 1)
            {
                cnt1=10;break;
            }

        if(cnt1 == 2 || !cnt1)
            cout << "Ordering is possible." << endl;
        else
            cout << "The door cannot be opened." << endl;


    }

    return 0;
}
