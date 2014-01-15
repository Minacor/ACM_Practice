
  题意：有一些任务是要在某些任务完成后才能完成的，问可能的做任务的次序
 
  明显的拓扑排序
 

#include iostream
#include cstring
#include algorithm
#include cmath
#include cstdio
#include sstream
#include queue
#include vector
#include string
#include stack
#include cstdlib
#include deque
#include fstream
#include map
#include set
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;

int n,m;
int in[110];
vectorint g[110];

void topo()
{
    queueint lis;
    stackint out;
    for(int i = 1 ; i = n ; i++)
        if(!in[i])
            lis.push(i);

    while(!lis.empty())
    {
        int tmp = lis.front();
        lis.pop();

        out.push(tmp);

        for(int i = 0 ; i  g[tmp].size() ; i++)
        {
            if(--in[g[tmp][i]] == 0)
            {
                lis.push(g[tmp][i]);
            }
        }
    }

    cout  out.top();
    out.pop();
    while(!out.empty())
    {
        cout  ' '  out.top();
        out.pop();
    }

    cout  endl;
}

int main()
{
    while(cin  n  m && (nm))
    {
        memset(in,0,sizeof(in));
        for(int i = 0 ; i  110 ; i++)
            g[i].clear();

        for(int i = 0 ; i  m ; i++)
        {
            int a,b;
            cin  a  b;

            g[b].push_back(a);
            in[a]++;
        }

        topo();
    }

    return 0;
}

