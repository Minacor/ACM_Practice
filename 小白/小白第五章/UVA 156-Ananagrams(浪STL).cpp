/*
 *定义：在规定的一群单词中，忽略大小写，如果一个单词不能通过字母重组得到其他单词，它就是目标单词
 *给一堆单词，要求按字典序输出目标单词
 *
 *思路：确定两个单词能互相得到的方法很简单，统一大小写之后排序，这是gao函数完成的
 *然后ju记录操作后的字符串有多少种，如果数量是1，那么这个单词对应的原单词肯定是目标单词
 *记录原单词用out，直接对每一个操作后单词s，进行out[s] = origin ，因为一定只有一个，所以不怕被覆盖，
 *而那些可能被覆盖的就是我们不需要的单词，覆盖不覆盖Who Cares?
 *最后字典序输出，由于是通过判断操作后字符串数量然后引出原单词的，所以还需要另外储存目标单词用来排序后
 *输出
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
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;

map<string , int> ju;
map<string , string > out;

string gao(string s)
{
    for(int i = 0 ; i < s.size() ; i++)
    {
        s[i] = tolower(s[i]);
    }

    sort(s.begin() , s.end());

    return s;
}

int main()
{
    string line;

    while(cin >> line && line != "#")
    {
        string tmp = gao(line);
        //cout << tmp << "*****" << endl;
        ju[tmp]++;
        out[tmp] = line;
    }

    map<string , int > :: iterator it = ju.begin();

    vector<string> OO;
    while(it != ju.end())
    {
        if(it->second == 1)
        {
            OO.push_back(out[it->first]);
        }

        it++;
    }

    sort(OO.begin() , OO.end());

    for(int i = 0 ; i < OO.size() ; i++)
    {
        cout << OO[i] << endl;
    }

    return 0;
}
