/*
 * 题型：暴力
 *
 * 题意：给一个矩阵，一个格子不是黑(B)就是白(W)，外星人能选择一行，把黑变白白变黑
 * 问进行若干操作后能得到的白色正方形的最大面积
 *
 * 思路：正方形最大可达边长就是矩形的宽(短边)，那么从短边长度开始，枚举长度，如果遇到以其为边长的白正方形就停止寻找
 * 找正方形的方法：只要找到连续字符相同的序列就可以作为可能边长进行判断，因为操作总能把他们变成连续的白色
 */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class AlienAndGame {
public:
    bool judge(int , int , int);
    int sum[55][55], num[55][55];
	int getNumber(vector <string>);
};

int AlienAndGame::getNumber(vector <string> board)
{
    int c = board[0].length(), r = board.size();
    int small = min(c, r);
    for(int i = 0; i != board.size(); i ++)
    {
        for(int j = 0; j != board[i].length(); j ++)
        {
            if(board[i][j] == 'W')
                num[i+1][j+1] = 1;
            else
                num[i+1][j+1] = 0;
        }
    }

    for(int i = 1; i <= r; i ++)
    {
        for(int j = 1; j <= c; j ++)
        {
            sum[i][j] += sum[i][j-1] + num[i][j];
        }
    }
    int ans = 1;
    for(int x = small; x > 1; x --)
    {
        for(int i = 1; i + x - 1 <= r; i ++)
        {

            for(int j = 1; j + x - 1 <= c; j ++)
            {
                if(!judge(i, j, x))
                    continue;
                else
                {
                    ans = x;
                    break;
                }

            }
            if(ans != 1)
                break;
        }
        if(ans != 1)
            break;
    }
    return ans * ans;
}

bool AlienAndGame::judge(int r, int c, int k)
{
    bool ok = true;
    for(int i = 0; i < k; i ++)
    {
        if(sum[r+i][c+k-1] - sum[r+i][c-1] != 0 && sum[r+i][c+k-1] - sum[r+i][c-1] != k) //要不连续的0，要不连续的1
        {
            ok = false;
            break;
        }
    }

    return ok;
}
