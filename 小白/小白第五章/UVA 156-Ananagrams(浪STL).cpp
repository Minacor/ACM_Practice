/*
 *���壺�ڹ涨��һȺ�����У����Դ�Сд�����һ�����ʲ���ͨ����ĸ����õ��������ʣ�������Ŀ�굥��
 *��һ�ѵ��ʣ�Ҫ���ֵ������Ŀ�굥��
 *
 *˼·��ȷ�����������ܻ���õ��ķ����ܼ򵥣�ͳһ��Сд֮����������gao������ɵ�
 *Ȼ��ju��¼��������ַ����ж����֣����������1����ô������ʶ�Ӧ��ԭ���ʿ϶���Ŀ�굥��
 *��¼ԭ������out��ֱ�Ӷ�ÿһ�������󵥴�s������out[s] = origin ����Ϊһ��ֻ��һ�������Բ��±����ǣ�
 *����Щ���ܱ����ǵľ������ǲ���Ҫ�ĵ��ʣ����ǲ�����Who Cares?
 *����ֵ��������������ͨ���жϲ������ַ�������Ȼ������ԭ���ʵģ����Ի���Ҫ���ⴢ��Ŀ�굥�����������
 *���
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
