/*
 *���⣺��һƪ�����еĵ��ʰ��ֵ�����ȡ��������Сд������
 
 *ע�⣺�п��ܳ���as.asdasd������������Բ�Ҫ��istringstream��ȡһ���ַ���Ȼ�����޳������Ϊһ������
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
using namespace std;
typedef long long LL;

map<string , int > dic;

int main()
{
    string line;
    while(getline(cin,line))
    {
        string word;
        for(int i = 0 ; i < line.size()  ;i++)
        {
            word = "";
            while(isalpha(line[i])) word += tolower(line[i++]);

            if(word!="")
                i--,dic[word]++;
        }
    }

    map<string , int > :: iterator it =dic.begin();

    while(it != dic.end())
    {
        cout << it->first << endl;
        it++;
    }

    return 0;
}
