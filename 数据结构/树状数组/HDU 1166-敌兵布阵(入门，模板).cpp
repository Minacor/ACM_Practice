/*
 * 题意：中文题略
 *
 * 思路：树状数组入门，模板题
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

tree[50010];            //注意树状数组是从1开始标号的！！
int n;

int lowbit(int t)
{
    return t&(t^(t-1));  //或者更简单的 (-t)&t;
}

int getsum(int pos)     //获得1~pos的和
{
    int t;

    for(t=0 ; pos>0 ; pos -= lowbit(pos))
        t += tree[pos];

    return t;
}

void modify(int pos , int delta)   //更改pos位置以后的数值 ， 变化量为delta，注意是向上更新，而get是向下查找
{
    for( ; pos <= n ; pos += lowbit(pos))
        tree[pos] += delta;
}

int main()
{
    int t;
    scanf("%d",&t);

    for(int ka = 1 ; ka <= t ; ka++)
    {
        memset(tree,0,sizeof tree);
        scanf("%d",&n);

        for(int i = 1 ; i <= n ; i++)           //树状数组的构造方法
        {
            int tmp;
            scanf("%d",&tmp);
            modify(i,tmp);
        }


        string cmd;

        printf("Case %d:\n",ka);

        while(cin >> cmd && cmd != "End")
        {
            int a,b;
            scanf("%d%d",&a,&b);

            if(cmd == "Query")
            {
                cout << getsum(b) -getsum(a-1) << endl;
            }
            else if(cmd == "Sub")
            {
                modify(a,-b);
            }
            else
            {
                modify(a,b);
            }

        }
    }

    return 0;
}




