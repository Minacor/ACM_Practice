/*
给定UIP中的两个量，求第三个量，有单位换算
*/


#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
typedef long long LL;

double mir2[500];

void init()
{
    mir2['m'] = 0.001;
    mir2['M'] = 1000000;
    mir2['k'] = 1000;
    mir2['V'] = mir2['A'] = mir2['W'] = 1;
}

double change(string s)
{
    int pos=s.size()-1;
    double res=0;
    int fu=1;

    for(int i = 0 ; i < s.size() ; i++)
        if(s[i] == '-')
        {
            fu=-1;
            continue;
        }
        else if(s[i] != '.')
            res = 10*res+(s[i]-'0');
        else
            pos = i;

    res = res / pow(10,s.size()-pos-1)*fu;

    return res;
}

int main()
{
    int t;
    cin >>t;
    getchar();
    init();

    for(int tt = 0 ; tt < t ; tt++)
    {
        string line;
        getline(cin,line);

        double num[2];
        char item[2],unit[2];

        int cnt=0;
        for(int i = 0 ; i < line.size() ; i++)
        {
            if(line[i] == '=')
            {
                item[cnt] = line[i-1];

                int len=0;
                while(!isalpha(line[i+len])) len++;
                unit[cnt] = line[i+len];

                string ss = line.substr(i+1,len-1);
                num[cnt++] = change(ss);
            }
        }

        double res;
        printf("Problem #%d\n",tt+1);

        if(item[0] == 'U' && item[1] == 'P')
        {
            res = num[1]*mir2[unit[1]] / (num[0]*mir2[unit[0]]);
            printf("I=%.2lfA\n",res);
        }
        else if(item[0] == 'P' && item[1] == 'U')
        {
            res = num[0]*mir2[unit[0]] / (num[1]*mir2[unit[1]]);
            printf("I=%.2lfA\n",res);
        }
        else if(item[0] == 'I' && item[1] == 'P')
        {
            res = num[1]*mir2[unit[1]] / (num[0]*mir2[unit[0]]);
            printf("U=%.2lfV\n",res);
        }
        else if(item[0] == 'P' && item[1] == 'I')
        {
            res = num[0]*mir2[unit[0]] / (num[1]*mir2[unit[1]]);
            printf("U=%.2lfV\n",res);
        }
        else
        {
            res = num[0]*mir2[unit[0]] * (num[1]*mir2[unit[1]]);
            printf("P=%.2lfW\n",res);
        }
        cout << endl;
    }

    return 0;
}

//P=6W,I=3A
//U=3mV,I=3A
//If the voltage is U=2V and the current is I=-4.5A, which power is generated?
