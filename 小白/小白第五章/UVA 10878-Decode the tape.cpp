/*
 *' '代表0，‘o’代表1，是ASCII码的二进制表示
 */

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
#include <cctype>
#define OUT(x) cerr << #x << ": " << (x) << endl
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;

char gao(int s)
{
    int res=0,cnt=1;
    while(s)
    {
        res += (s%10)*cnt;
        cnt*=2;
        s/=10;
    }
    return res;
}

char out[10000];

int main()
{
    string line;

    int cnt=0;
    cin >> line;
    cin.ignore();
    int s;

    while(getline(cin,line))
    {
        if(line != "___________")
        {
            s=0;
            for(int i= 0 ; i < line.size() ; i++)
            {
                if(line[i] == ' ')
                    s = s*10;
                else if(line[i] == 'o')
                    s = s*10+1;
            }

            out[cnt++] = gao(s);
        }
        else
        {
            out[cnt]='\0';
            break;
        }

    }
    cout << out;

    return 0;
}
