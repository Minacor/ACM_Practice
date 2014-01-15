/*
 * 题意：给n个单词，需要把他们按字典序输出，要求竖着安排，而且每行至多60字符。
 * 每个单词，最后一列的输出宽度为最大单词长度，其余列的为最大单词长度+2，额外宽度用空格补齐，算入总字符中
 * 要求行数尽可能少
 *
 * 思路：行数尽可能少，就是列数尽可能多，也就是说要尽可能利用60个字符，列数最多必定为62 / (maxlen+2)，因为每行最后一个单词的宽度比其他单词少2，所以要补上2
 * 行数就是总单词数/列数了，注意不整除就要加1，否则不完整行就会遗漏了
 * 然后就是具体安排输出法了
 *
 * 这里的输出很重要:printf("%-*s",m,str);'-'表示左对齐，'*'表示指定str输出宽度为m
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

string words[110];
vector<string> out[110];

int main()
{
    int n;

    while(cin >> n)
    {
        for(int i = 0 ; i < 110 ; i++)
            out[i].clear();

        int maxlen = 0;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> words[i];
            maxlen = max(maxlen,(int)words[i].length());
        }

        sort(words , words + n);

        int col = 62 / (maxlen+2);

        int row = n/col;
        if(n%col!=0)row++;

//        cout << col << "*************" <<endl;
//        cout << row << "***********" << endl;

        for(int i = 0 ; i < col ; i++)
            for(int j = 0 ; j < row && i*row+j<n; j++)
            {
                out[i].push_back(words[i*row+j]);           //out[i]表示第i列的单词
            }

        cout << "------------------------------------------------------------" << endl;
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col && i < out[j].size() ; j++)     //注意不完整行的输出完毕判断i < out[j].size()
            {
                if(j == col-1)
                    printf("%-*s",maxlen,out[j][i].c_str());
                else
                    printf("%-*s",2+maxlen,out[j][i].c_str());
            }
            cout << endl;
        }

    }

    return 0;
}


