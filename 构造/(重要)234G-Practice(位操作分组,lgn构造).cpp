/*
 * 题意：
 * 有n个球员编号1~n，教练要分配m场比赛，使得每个人都与其他人至少交手过一次
 * 每场比赛两队，不同队伍的两个人就算是交手过一次
 * 输出最小场数m和m行的每场比赛信息
 * 比赛信息第一个数为其中一队的人数，之后几个数为队员编号
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
#define lson(x) (x<<1)
#define rson(x) (x<<1|1)
#define MID(x,y) ((x+y)>>1)
#define FR (freopen("in.txt","r",stdin))
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 200000+100;
const int inf = 522133279;
const int mod = 1000000007;

int n;

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    cin >> n;
    int r=0;

    while((1<<r) < n) r++;  //log(n)的构造法
    cout << r <<endl;

    for(int i = 0 ; i < r ; i++)
    {
        int cnt=0;
        //由于0~n的连续性，相邻的两个数(更确切说是任意两个数)必定会出现一个0一个1的情况
        //意味着任意的两个队员一定至少交过一次手
        for(int j = 0; j < n ; j++)     //对于每一个数位i，只要这个位置是1，就加入当前的队伍
            if(j & (1 << i)) cnt++;
        cout << cnt << ' ';
        for(int j = 0 ; j < n ; j++)
            if(j & (1 << i)) cout << j+1 << ' ';
        cout << endl;
    }
    return 0;
}
