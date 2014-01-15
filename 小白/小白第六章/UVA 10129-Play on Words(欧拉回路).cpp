/*
 * 题意：给一群串，定义两个串能相连：前串的尾字母和后串的首字母相同
 * 判断给出的词能否连成一串
 *
 * 思路：有向半欧拉图判定，1.连通，2.把字母看成顶点，除了有两个字母的出度和入度相差一以外，其他顶点的都相等
 * 连通用了dfs，也可用并查集，欧拉通路情况是：除了一个点的祖先是自己以外其他点的都不是
 *
 * 需要注意的是，如果有两个以上的点的（出度-入度=1）或者（入度-出度=1）的话，这图一定不连通，
 * 所以之后的出入度判断无需再判断是否有两个点同时出度比入度少1或多1
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
