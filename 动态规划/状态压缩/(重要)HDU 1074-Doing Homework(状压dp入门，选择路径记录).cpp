/*
 * 题意：
 * 给几门课，每行：课的名字 此课作业的截止期限 做完作业需要的时间
 * 如果超出截止期限，每超出一天扣一分
 * 求：使得扣的分数最少的做作业的顺序
 *
 * 课的数量不超过15，状态压缩dp
 * 转移方程由前一状态和选择了当前课程作业的现态决定，状态由一个二进制数表示，0表示没做完，1表示已做完
 * 细节见代码
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
const int MAX = (1<<15)+100;
const int inf = 522133279;

int n,t;
struct n1
{
    string name;        //课程名字
    int deadline;       //这门课程作业的截止期限
    int spend;          //做完这门课程作业所需时间
}c[20];

struct n2
{
    int score;          //当前状态扣掉的分数
    int prevState;      //表示前一状态的十进制数
    int curpos;         //当前选择了下标为curpos的这门课，注意下标从0开始
    int totspend;       //做完当前状态下已完成的作业的总时间
}dp[MAX];

int main()
{
    FR;
    cin >> t;

    while(t--)
    {
        cin >> n;
        for(int i = 0 ; i < n ; i++)
            cin >> c[i].name >> c[i].deadline >> c[i].spend;
        clr(dp,0);

        int totState = 1 << n;      //总状态数

        for(int i = 1 ; i < totState ; i++)
        {
            dp[i].score = inf;
            //特别注意这里。题目要求如果减的分数相同，就按字典序小的输出
            //然后后面的最小值更新判断是'<'而非'<='，故这里要逆序
            for(int k = n-1 ; k >= 0 ; k--)     //枚举每一门课
            {
                int curclass = 1 << k;

                if(i&curclass)          //如果这门课在当前状态下已被选择
                {
                    int prevState = i-curclass; //前一状态，没有选择这门课的状态
                    int spend = dp[prevState].totspend + c[k].spend;    //做完这门课后的花费时间
                    int jianfen=0;
                    if(spend > c[k].deadline)       //超过截止时间就得减分了
                        jianfen = spend-c[k].deadline;
                    if(dp[prevState].score+jianfen < dp[i].score)       //如果当前状态使得减分更少就更新
                    {
                        dp[i].score = dp[prevState].score+jianfen;
                        dp[i].totspend = dp[prevState].totspend+c[k].spend;
                        dp[i].curpos = k;               //选择使得减分更少的课程
                        dp[i].prevState = prevState;    //更改前一状态
                    }
                }
            }
        }

        //回溯路径
        cout << dp[totState-1].score << endl;
        stack<string> out;
        int prev = totState-1;
        do
        {
            int cur = dp[prev].curpos;
            out.push(c[cur].name);
            prev = dp[prev].prevState;
        }while(prev);

        while(!out.empty())
        {
            cout << out.top() << endl;
            out.pop();
        }
    }

    return 0;
}
