/*
 * ���⣺����һȺ��Ҫ���Եĵ��ʺ�һЩ���ӣ��������зǺ��Եĵ���ȫ��ɴ�д���ֵ�������
 * ���Ҫ�������������ԭ�䣬ֻ�������˵���ȫ��д֮�⣬���൥��Сд
 * ���һ���������ж����ͬ�ķǺ��Ե��ʣ��Ȱ���ߵĵ��ʴ�д�����
 *
 * ˼·��multimap�÷����������ظ���ֵ�Ĳ��룬��ֵ���ֵ���������򣬶���ͬ�ļ�ֵ���ٰ���ֵ���ֵ�������
 * ���������д>Сд��ǡ�÷����ֵ���
 *
 * �Ƚ�ȡһ�仰������ȫ���Сд��Ȼ��һ��������ö�٣���replace�ı�(ע�⣡��replace��ֱ�Ӹı䱻�������ַ�����)
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

                //tmp.replace(start,len,string) ��tmp��start(����)��len���ȵ������滻Ϊstring

                lis.insert(make_pair(word,tt.replace(start,word.size(),word))); //multimap�Ĳ��뷨����pair����
            }

            i+=word.size();
        }
    }

    multimap<string,string> :: iterator it = lis.begin();

    for( ; it != lis.end() ; it++)
        cout << it->second << endl;

    return 0;
}
