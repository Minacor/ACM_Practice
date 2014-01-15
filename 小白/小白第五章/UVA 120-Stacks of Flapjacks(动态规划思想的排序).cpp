/*
 * ���⣺��һ���ӱ����������ҷֱ���Ǵ������£�����(����)���Ϊ1�����ִ���ֱ��
 * ��ת��������Ϊ����x��ת���ǰ�x(����)����������ӱ���ת������(234)1 , x=2 -> (432)1
 * Ҫ�����ɷ�ת֮�����ڵ��£�С��������
 *
 *
 * ˼·����̬�滮˼�룬�ӽṹ����δ�Ź�����ӱ���
 * ����δ�������䣬�ҵ����е����ֵ���Ȱ������������棬Ȼ��Ϳ��Է�����������������
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

int a[50];

int find_max(int r)
{
    int maxc = -1;
    int pos=0;
    for(int i = 0 ; i <= r ; i++)
    {
        if(maxc < a[i])
        {
            maxc = a[i];
            pos=i;
        }
    }

    return pos;
}

int rev(int r)
{
    for(int i = 0 ,j = r; i <= j ; i++,j--)
    {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
}

int main()
{
    string line;

    while(getline(cin,line))
    {
        istringstream iss(line);
        int n=0;
        while(iss >> a[n])n++;
        for(int i = 0 ; i < n-1 ; i++)
            cout << a[i] << ' ';
            cout << a[n-1] << endl;

        for(int i = n-1 ; i >= 0 ; i--)
        {
            int pos = find_max(i);
            if(pos != i)
            {
                if(pos != 0)
                {
                    cout << n-pos << ' ';
                    rev(pos);
                }

                rev(i);
                cout << n-i << ' ';
            }
        }
        cout << 0 << endl;
    }

    return 0;
}
