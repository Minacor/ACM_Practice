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
using namespace std;
typedef long long LL;

int mir[500];

void init()
{
    mir['A'] = 'A';
    mir['E'] = '3' ; mir['3'] = 'E';
    mir['H'] = 'H';
    mir['I'] = 'I';
    mir['J'] = 'L' ; mir['L'] = 'J';
    mir['M'] = 'M';
    mir['O'] = 'O';
    mir['S'] = '2' ; mir['2'] = 'S';
    mir['T'] = 'T';
    mir['U'] = 'U';
    mir['V'] = 'V';
    mir['W'] = 'W';
    mir['X'] = 'X';
    mir['Y'] = 'Y';
    mir['Z'] = '5' ; mir['5'] = 'Z';
    mir['1'] = '1';
    mir['8'] = '8';
}

int j(string s)
{
    int ok1 = 1, ok2 = 1;

    for(int i = 0 ; i < s.size() ; i++)
        if(s[i] == '0')
            s[i] = 'O';

    for(int i = 0 , j = s.size()-1; i < j ; i++,j--)
    {
        if(s[i] != s[j])
            ok1 = 0;
    }

    for(int i = 0 , j = s.size()-1; i <= j ; i++,j--)
    {
        if(!mir[s[i]] || !mir[s[j]] || s[i] != mir[s[j]])
            ok2 = 0;
    }

    if(ok1 && ok2)
        return 3;
    else if(ok1)
        return 1;
    else if(ok2)
        return 2;
    else
        return 0;
}

int main()
{
    string line;
    init();

    while(cin >> line)
    {
        int res = j(line);

        if(res == 0)
            cout << line << " -- is not a palindrome." << endl;
        else if(res == 1)
            cout <<line<< " -- is a regular palindrome." << endl;
        else if(res == 2)
            cout << line << " -- is a mirrored string." << endl;
        else
            cout << line << " -- is a mirrored palindrome." << endl;
        cout <<endl;
    }

    return 0;
}


