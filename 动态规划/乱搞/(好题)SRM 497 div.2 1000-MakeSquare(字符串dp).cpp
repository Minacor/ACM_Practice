/*
 * 题意：
 * 经过更改，删除，添加操作使一个字符串变成重复两遍的字符串,如abvabv
 * 求最小的操作数
 */

#line 2 "MakeSquare.cpp"
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

class MakeSquare {
public:
    int dp[60][60];     //dp[i][j]表示处理到s1[i],s2[j]时最小的操作数
    int minChanges(string S)
    {
        int len = S.size();
        int minc = len;
        for(int i = 1 ; i < len ; i++)      //枚举分割点，分割成两个字符串，对一个字符串进行操作，此时删除操作是无用的
                                            //因为对一个串的删除就是对另一个串的添加
        {
            memset(dp,0x1f,sizeof dp);
            string s1=S.substr(0,i);
            string s2=S.substr(i);
            //cout << s1 << ' ' << s2 << ' ';
            int l1=s1.size(),l2=s2.size();
            for(int i = 0 ; i <= ml ;i++)
                dp[0][i]=dp[i][0]=i;
            //dp[0][0]=522133279;
            for(int i = 1 ; i <= l1 ; i++)
                for(int j = 1 ; j <= l2 ; j++)
                    if(s1[i-1]!=s2[j-1])    //如果不能配对，或更改，或在此位添加，并且配对，无论怎么样，操作数都+1
                    {
                        dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
                        dp[i][j]++;
                    }
                    else        //如果i和j位能够配对，则操作数为0，并且配对
                        dp[i][j]=dp[i-1][j-1];
            //cout << ml << ' ' << dp[l1-1][l2-1] << endl;
            minc = min(minc,dp[l1][l2]);
        }

        return int(minc);
    }