/*
 * 题意：给出一群需要忽略的单词和一些句子，将句子中非忽略的单词全变成大写后字典序排序，
 * 输出要求输出单词所在原句，只不过除此单词全大写之外，其余单词小写
 * 如果一个句子中有多个相同的非忽略单词，先把左边的单词大写后输出
 *
 * 思路：multimap用法，它允许重复键值的插入，键值有字典序排序规则，对相同的键值，再按照值的字典序排序，
 * 由于这里大写>小写，恰好符合字典序
 *
 * 先截取一句话，把它全变成小写，然后一个个单词枚举，用replace改变(注意！！replace是直接改变被操作的字符串！)
 *
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
#include "set"
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;

set< string >  ig;
multimap<string , string> lis;

int main()
{
    string tmp;
    while(cin >>tmp && tmp != "::")
        ig.insert(tmp);

    while(getline(cin,tmp))
    {
        for(int i = 0 ; i < tmp.size() ; i++)
            tmp[i] = tolower(tmp[i]);

        for(int i  =0 ; i < tmp.size() ; i++)
        {
            string word;

            if(!isalpha(tmp[i]))
                continue;

            int start = i;

            for(int j = start ; j < tmp.size() && isalpha(tmp[j]) ; j++)
                word+=tmp[j];

            if(!ig.count(word))
            {
                for(int k = 0 ; k < word.size() ; k++)
                    word[k] = toupper(word[k]);

                string tt=tmp;

                //tmp.replace(start,len,string) 将tmp中start(包括)后len长度的内容替换为string

                lis.insert(make_pair(word,tt.replace(start,word.size(),word))); //multimap的插入法：用pair插入
            }

            i+=word.size();
        }
    }

    multimap<string,string> :: iterator it = lis.begin();

    for( ; it != lis.end() ; it++)
        cout << it->second << endl;

    return 0;
}
