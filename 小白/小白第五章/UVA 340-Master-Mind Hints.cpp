/*
 *输入的第一个字符串是原串，后面的都是猜测的串，(x,y)表示两种状态的数目，要求比较原串和猜测串
 *若s1[i] = s2[i]，则x++；若s1[i]=s2[j]且s1[i] != s2[i]则y++，判断过的字符不能再用，首先比较前者
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

struct point
{
    int x;
    int y;
};

point gao(string s1 , string s2)
{
    point p;
    p.x=p.y=0;

    for(int i = 0 ; i < s1.size() ; i+=2)
    {
        if(s1[i]==s2[i])
        {
            p.x++;
            s1[i]=s2[i] = 'a';
        }
    }

    for(int i = 0 ; i < s1.size() ; i+=2)
    {
        if(s1[i] == 'a')
            continue;

        for(int j = 0 ; j < s2.size() ; j+=2)
        {
            if(s2[j] == 'a')
                continue;

            if(s1[i] == s2[j])
            {
                p.y++;
                s1[i] = s2[j] = 'a';
            }
        }
    }

    return p;
}

int main()
{
    int len;
    int ka=0;
    while(cin >> len && len)
    {
        cin.ignore();
        string origin;
        string cmp;

        getline(cin,origin);

        printf("Game %d:\n" , ++ka);

        while(getline(cin,cmp) && cmp[0]!='0')
        {
            point out = gao(cmp,origin);

            printf("    (%d,%d)\n",out.x,out.y);
        }
    }

    return 0;
}













