/*
 * �ܼ򵥺����ŷ����·������Ҫע�⼸��:
 * 1.����ͼ
 * 2.���Ϊ0��Ҳ�������˹��ļң�ͼ������ͨ(Ҳ�������й����㣬��Ŀ��Ȼ����Ҫ���б�����·����δҪ���б�����·������㣬�����������������е����·)
 *   ����������ص�0�㣬Ҳ����˵��0���������֮��û��·���������ڵ�֮����ŷ����·���ڵ�Ҳ����
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

int f[250];
int in[250];
int n,r;

int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}

void merger(int x , int y)
{
    x = find(x);
    y = find(y);

    if(x != y)
    {
        if(f[x] == 0)       //ע��ϲ���ʱ��Ϊ�ж����̵�
            f[y]=x;
        else
            f[x] = y;
    }
}

bool isEuler()
{
    int cnt=0;
    for(int i = 0 ; i < n ; i++)
    {
        if(in[i]%2 || find(i) != 0)            //���i�����Ȳ���0��˵�������ܻؼң�ͬʱ˵�����ܵ�������ڵ�
            return 0;
    }

    return 1;
}

void init()
{
    memset(in , 0, sizeof in);

    for(int i = 0 ; i <= n ; i++)
        f[i]=i;
}

int main()
{
    while(cin >> n >> r)
    {
        init();

        for(int i  =0 ; i < r ; i++)
        {
            int a,b;
            cin >> a >> b;
            in[a]++;in[b]++;
            merger(a,b);
        }

        cout << (isEuler() ? "Possible" : "Not Possible") << endl;
    }

    return 0;
}


