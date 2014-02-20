/*
 * ���⣺
 * �������ģ�ɾ������Ӳ���ʹһ���ַ�������ظ�������ַ���,��abvabv
 * ����С�Ĳ�����
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
    int dp[60][60];     //dp[i][j]��ʾ����s1[i],s2[j]ʱ��С�Ĳ�����
    int minChanges(string S)
    {
        int len = S.size();
        int minc = len;
        for(int i = 1 ; i < len ; i++)      //ö�ٷָ�㣬�ָ�������ַ�������һ���ַ������в�������ʱɾ�����������õ�
                                            //��Ϊ��һ������ɾ�����Ƕ���һ���������
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
                    if(s1[i-1]!=s2[j-1])    //���������ԣ�����ģ����ڴ�λ��ӣ�������ԣ�������ô������������+1
                    {
                        dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
                        dp[i][j]++;
                    }
                    else        //���i��jλ�ܹ���ԣ��������Ϊ0���������
                        dp[i][j]=dp[i-1][j-1];
            //cout << ml << ' ' << dp[l1-1][l2-1] << endl;
            minc = min(minc,dp[l1][l2]);
        }

        return int(minc);
    }