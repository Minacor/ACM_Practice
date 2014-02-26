/*
 * ���⣺
 * ����"�Ϸ�����" ����һ��ֻ��01�ľ��Σ��Ҿ������������ڵ�������������ͬ
 *
 * �ָ���һ�����������Ϸ�����
 *
 * ˼·��
 * dp[i][l][r][x]��ʾ��i��l~r�е��ִ��ǲ�����x��β�ķ���Ҫ����ִ�
 * ������dp�����ö�����Ϸ����̵Ŀ��r-l+1,��ÿһ������ж��ܹ��ɵ���󳤶�cnt
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
                        dp[i][l][r][1] = dp[i][l][r-1][0];//������һ����ͬ��β�ĺϷ���
                        dp[i][l][r][0] = 0;     //��ͬ��β�ľͲ��Ϸ��ˣ��Ϸ���=0
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
                vector<int> ju; //ju[i]��ʾ��i�еĵ�ǰö�ٵ���λ�õ��Ӵ��ĺϷ���

                for(int i = 0 ; i < n ; i++)
                    ju.push_back(dp[i][l][r][i&1]);

                //������Ҫ�ҵľ�������������1�ĳ���
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
                //��������010101��101010��������
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
