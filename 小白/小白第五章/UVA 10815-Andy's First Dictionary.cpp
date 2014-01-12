/*
 *题意：把一篇文章中的单词按字典序提取出来，大小写不敏感
 
 *注意：有可能出现as.asdasd这种情况，所以不要用istringstream截取一个字符串然后再剔除标点作为一个单词
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
