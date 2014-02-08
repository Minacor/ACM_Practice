/*
 * 题意：
 * 改造字符串
 * 1：如果一个字符连续超过三次，则至少要删除到连续2次以下，如wooooto -> wooto
 * 2：一个连续序列xx之后不能跟其余的连续序列yy，所以如右删除：wwttqqrr->wwtqqr
 * 输出操作后的字符串
 *
 * 利用pair数组记录每个连续字符的出现次数十分方便
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
const int MAX = 200000+100;
const int inf = 522133279;
const int mod = 1000000007;

pair<char , int> cnt[200000+100];
int num;

int main()
{
    string line;
    cin >> line;

    for(int i = 0 ; i < line.size() ; i++)
    {
        if(!i)
            cnt[num++] = make_pair(line[i],1);
        else
        {
            char cur = line[i];
            if(cur == cnt[num-1].first) //如果当前字符和前一个字符一样就要深入判断，否则直接新建一个pair
            {
                cnt[num-1].second += (cnt[num-1].second < 2);//如果超过连续2个就不累加
                if(num>=2 && cnt[num-2].second == 2 && cnt[num-1].second==2)    //如果当前字符有两个了，并且前一个字符也是连续两个，当前字符就要删
                    cnt[num-1].second--;
            }
            else
                cnt[num++] = make_pair(line[i],1);

        }
    }

    for(int i = 0 ; i < num ; i++)
        while(cnt[i].second)
        {
            cnt[i].second--;
            cout << cnt[i].first;
        }

    return 0;
}
