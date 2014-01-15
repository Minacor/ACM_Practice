/*
 * 题意：给一叠烙饼，从左至右分别就是从上至下，最下(最右)编号为1，数字代表直径
 * 翻转操作定义为：从x翻转就是把x(包括)上面的所有烙饼翻转，比如(234)1 , x=2 -> (432)1
 * 要求若干翻转之后大的在底下，小的在上面
 *
 *
 * 思路：动态规划思想，子结构就是未排过序的烙饼，
 * 锁定未排序区间，找到其中的最大值，先把它翻到最上面，然后就可以翻到这个区间的最下面
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
