/*
 * ���⣺��n�����ʣ���Ҫ�����ǰ��ֵ��������Ҫ�����Ű��ţ�����ÿ������60�ַ���
 * ÿ�����ʣ����һ�е�������Ϊ��󵥴ʳ��ȣ������е�Ϊ��󵥴ʳ���+2���������ÿո��룬�������ַ���
 * Ҫ��������������
 *
 * ˼·�������������٣��������������ܶ࣬Ҳ����˵Ҫ����������60���ַ����������ض�Ϊ62 / (maxlen+2)����Ϊÿ�����һ�����ʵĿ�ȱ�����������2������Ҫ����2
 * ���������ܵ�����/�����ˣ�ע�ⲻ������Ҫ��1�����������оͻ���©��
 * Ȼ����Ǿ��尲���������
 *
 * ������������Ҫ:printf("%-*s",m,str);'-'��ʾ����룬'*'��ʾָ��str������Ϊm
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
                out[i].push_back(words[i*row+j]);           //out[i]��ʾ��i�еĵ���
            }

        cout << "------------------------------------------------------------" << endl;
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col && i < out[j].size() ; j++)     //ע�ⲻ�����е��������ж�i < out[j].size()
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


