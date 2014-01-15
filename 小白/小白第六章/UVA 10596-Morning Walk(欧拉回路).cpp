/*
 * 很简单很裸的欧拉回路，不过要注意几点:
 * 1.无向图
 * 2.起点为0，也就是主人公的家，图必须连通(也不可以有孤立点，题目虽然仅仅要求行遍所有路，并未要求行遍所有路径交叉点，但是依题意来看是有点必有路)
 *   所以最后必须回到0点，也就是说，0到其他结点之间没有路，但其他节点之间有欧拉回路存在的也不行
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
        if(f[x] == 0)       //注意合并的时候，为判断做铺垫
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
        if(in[i]%2 || find(i) != 0)            //如果i的祖先不是0，说明不可能回家，同时说明不能到达这个节点
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


