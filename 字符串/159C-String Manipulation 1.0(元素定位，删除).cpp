/*
 * 题意：
 * 给一个字符串s片段和k，总字符串out是由k个s拼接而成的
 * 给n个操作p c，删除out中第p个c字符，删除后重新编号
 * 输出更改后的字符串
 *
 * 思路：
 * 直接暴力肯定不行，定位方法很重要
 * 刚开始记录了s中各个字符的个数，然后通过除法来定位，可是这样行不通，因为删除后会重新编号，每个循环节已经不同了
 * 所以改用vector<int> [char]来记录char出现的位置
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

string out,s;
int k,n;
vector<int> pos[500];

int main()
{
    cin >> k >> s >> n;

    for(int i = 0 ; i < k ; i++)
        out+=s;
    for(int i = 0 ; i < out.size() ; i++)
        pos[out[i]].push_back(i);

    while(n--)
    {
        int p;char c;
        cin >> p >> c;
        out[*(pos[c].begin()+p-1)] = 'A';
        pos[c].erase(pos[c].begin() + p-1);
    }

    for(int i = 0 ; i < out.size() ; i++)
        if(out[i] != 'A') cout << out[i];

    return 0;
}
