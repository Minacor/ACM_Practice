/*
 *�����Ժ�ǰ����������������ɣ���Ϊ�����ֵ������s1��s2��ǰ׺�Ļ���
 *s1һ���������s2����s2��ǰ��
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

string lis[10000];
int cnt;
int ka=0;

int j(string s1,string s2)
{
    int minlen = min(s1.length(),s2.length());

    for(int i = 0 ; i < minlen ; i++)
        if(s1[i] != s2[i])
            return 0;

    return 1;
}

int main()
{
    string line;

    while(cin >> line)
    {
        if(line == "9")
            continue;
        else
        {
            cnt=0;

            do
            {
                lis[cnt++] = line;
                cin >> line;
            }while(line != "9");

            sort(lis , lis+cnt);
        }

//        for(int i = 0 ; i < cnt ; i++)
//            cout << lis[i] <<endl;

        int ok = 0;
        for(int i = 0 ; i < cnt-1;i++)
            if(j(lis[i],lis[i+1]))
            {
                ok=1;
                break;
            }

        cout << "Set " << ++ka << ' ';
        cout << (!ok ? "is immediately decodable" : "is not immediately decodable") << endl;
    }
    return 0;
}

