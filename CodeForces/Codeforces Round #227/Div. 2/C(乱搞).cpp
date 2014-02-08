/*
 * 题意：
 * 有一个数组里有若干个数，有这样的一种操作
 * 1, 选择两个数a[i],a[j],且a[i]>=a[j]
 * 2, 将大的数接到小的数前面，组成一个数，把这个数加入到数组末尾
 * 3, 删除a[i],a[j],重新标号
 * 现在给一个数，问原数组中最多有几个数，使得最终能拼成这个数
 *
 * 思路：
 * 对这个数从后往前遍历，从当前位置i将未判断的子数切成两段0~i，i~size，看看能不能满足合并要求
 * 能的话就加1
 * 直接函数递归会爆内存，所以采用递推
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
#define FR (freopen("in.txt","r",stdin))
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 100000+100;
const int inf = 522133279;

int cmp(string a , string b)   //判断数a是否>=数b
{
    if(a.size() > b.size())
        return 1;
    if(a.size() == b.size() && a >= b)
        return 1;
    return 0;
}

int dfs(string cur)
{
    int cnt=0,lastpos=cur.size();
    for(int i = cur.size()-1 ; i >= 0 ; i--)
    {
        if(cur[i] == '0') continue; //题目保证没有前导零，所以可以放心跳过
        
        //切分未处理的子数
        string s1 = cur.substr(0,i); //第一段
        string s2 = cur.substr(i,lastpos-i); //第二段的末端是已处理的子数前一个位置，之后的都是已经合并并且记过数的子数

        if(cmp(s1,s2))
        {
            cnt++;
            lastpos = i;
        }
    }
    return cnt;
}

int main()
{
    //FR;
    string line;
    cin >> line;
    cout << dfs(line)+1 << endl;
    return 0;
}
