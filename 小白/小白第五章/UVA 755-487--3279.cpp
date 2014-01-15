
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
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;

char mir[] = "22233344455566677778889999";
map<string, int> lis;

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        lis.clear();
        int n;
        scanf("%d",&n);

        for(int i = 0 ; i < n ; i++)
        {
            string tmp,line="";
            cin >>tmp;

            for(int i = 0 ; i <tmp.size() ; i++)
            {
                if(isalpha(tmp[i]))
                    line += mir[tmp[i]-'A'];
                else if(isdigit(tmp[i]))
                    line += tmp[i];

                if(line.size() == 3)
                    line += '-';
            }

            lis[line]++;
        }

        map<string,int> :: iterator it = lis.begin();

        int ok=0;
        while(it != lis.end())
        {
            if(it->second >= 2)
            {
                ok=1;
                cout << it->first << ' ' << it->second <<endl;
            }
            it++;
        }

        if(!ok)
            cout << "No duplicates." << endl;
        if(t)
            cout <<endl;
    }

    return 0;
}
