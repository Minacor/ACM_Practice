/*
 * 题意：
 * 输入：
 * 第一行两个数：有n种颜色的衣服 共m件
 * 第二行n个颜色的名字
 * 接下来m行，每行两个数
 * 洗这件衣服的时间time 这件衣服的颜色name
 *
 * 现在有两个人速度相同的人洗衣服，他们必须一种颜色一种颜色洗，洗完才能洗下一种颜色
 * 问最少时间
 *
 * 思路：
 * 这题就是big event in hdu的强化版
 * 由于不同颜色不能交叉，所以洗不同颜色的衣服的事件是独立的，可以求出洗某种颜色衣服的最少时间然后相加
 * 对于每种颜色，两个人洗的时间一定越接近越好，这一步就和那一题一样了：
 * 把总时间的一半作为背包容量，让一个人的时间尽可能填满这个背包，另一个人的时间就是所需最少时间了
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
using namespace std;
typedef long long LL;
const int MAX = 1000;
const int inf = 522133279;

map < string , vector<int> > lis;
int dp[100000+100];

int main()
{
    //FR;
    int n,m;
    while(cin >> n >> m && (n||m))
    {
        lis.clear();
        cin.ignore();

        string name;
        int time;
        getline(cin,name);

        for(int i = 0 ; i < m ; i++)
        {
            cin >> time >> name;
            cin.ignore();
            lis[name].push_back(time);
        }

        int ans=0;
        map< string , vector<int> > :: iterator it = lis.begin();
        for( ; it != lis.end() ; it++)
        {
            vector<int> tmp(it->second);
            int sum=0;
            for(int i = 0 ; i < tmp.size() ; i++)
                sum += tmp[i];

            memset(dp,0,sizeof dp);

            for(int i = 0 ; i < tmp.size() ; i++)
                for(int j = sum/2 ; j >= tmp[i] ; j--)
                    dp[j] = max(dp[j],dp[j-tmp[i]]+tmp[i]);
            ans += sum - dp[sum/2];
        }

        cout << ans << endl;
    }

    return 0;
}
