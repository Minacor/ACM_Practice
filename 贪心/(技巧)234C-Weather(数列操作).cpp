/*
 * 题意：
 * 给一串数列，求最少改变多少数字使得串的前面连续几个数是负数，后面连续的数是正数
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

int a[100000+100];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    int qian=0,hou=0;       //qian表示将当前这个数(包括)之前的>=0的数全变负数所需操作数
                            //hou表示将当前这个数(不包括)之后的<=0的数全变正数所需操作数
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        if(a[i] <= 0)
            hou++;
    }

    int minc=inf;
    for(int i = 0 ; i < n-1 ; i++)  //注意题目要求：全正或全负也不行，所以开始为0，结束为n-1
    {
        if(a[i] >= 0) qian++;
        if(a[i] <= 0) hou--;
        minc = min(qian+hou,minc);
    }
    cout << minc << endl;

    return 0;
}
