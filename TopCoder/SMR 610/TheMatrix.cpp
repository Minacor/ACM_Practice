/*
 * 题意：
 * 定义"合法棋盘" ：是一个只含01的矩形，且矩形内任意相邻的两个数不能相同
 *
 * 现给定一个矩阵，求最大合法棋盘
 *
 * 思路：
 * dp[i][l][r][x]表示第i行l~r列的字串是不是以x结尾的符合要求的字串
 * 构造完dp数组后枚举最大合法棋盘的宽度r-l+1,对每一个宽度判断能构成的最大长度cnt
 */

#line 2 "TheMatrix.cpp"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
#define OUT(x) cerr << #x << ": " << (x) << endl
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;

class TheMatrix {
public:
    int dp[110][110][110][2];

    int MaxArea(vector <string> board)
    {
        memset(dp,0,sizeof dp);
        int n = SZ(board);
        int m = SZ(board[0]);
        cout << n <<' ' << m << endl;

        for(int i = 0 ; i  < n ; i++)
        {
            for(int l = 0 ; l < m ; l++)
            {
                if(board[i][l] == '0') dp[i][l][l][0]=1;
                else dp[i][l][l][1]=1;

                for(int r = l+1 ; r < m ; r++)
                {
                    if(board[i][r] == '1')
                    {
                        dp[i][l][r][1] = dp[i][l][r-1][0];//延续上一个不同结尾的合法度
                        dp[i][l][r][0] = 0;     //相同结尾的就不合法了，合法度=0
                    }
                    else
                    {
                        dp[i][l][r][0] = dp[i][l][r-1][1];
                        dp[i][l][r][1] = 0;
                    }
                }
            }
        }

        int maxc=-1;
        for(int l = 0 ; l < m ; l++)
            for(int r = l ; r < m ; r++)
            {
                vector<int> ju; //ju[i]表示第i行的当前枚举到的位置的子串的合法度

                for(int i = 0 ; i < n ; i++)
                    ju.push_back(dp[i][l][r][i&1]);

                //我们需要找的就是最大的连续的1的长度
                int cnt=0;
                for(int i = 0 ; i < n ; i++)
                    if(ju[i])cnt++;
                    else
                    {
                        maxc = max(maxc,(r-l+1)*cnt);
                        cnt=0;
                    }
                maxc = max(maxc,(r-l+1)*cnt);

                ju.clear();
                //别忘记有010101和101010两种排列
                for(int i = 0 ; i < n ; i++)
                    ju.push_back(dp[i][l][r][!(i&1)]);
                cnt=0;
                for(int i = 0 ; i < n ; i++)
                    if(ju[i])cnt++;
                    else
                    {
                        maxc = max(maxc,(r-l+1)*cnt);
                        cnt=0;
                    }
                maxc = max(maxc,(r-l+1)*cnt);
            }

        return int(maxc);
    }
}
