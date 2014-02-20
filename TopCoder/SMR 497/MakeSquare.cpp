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

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abcdabgcd"; int Arg1 = 1; verify_case(0, Arg1, minChanges(Arg0)); }
	void test_case_1() { string Arg0 = "abcdeabce"; int Arg1 = 1; verify_case(1, Arg1, minChanges(Arg0)); }
	void test_case_2() { string Arg0 = "abcdeabxde"; int Arg1 = 1; verify_case(2, Arg1, minChanges(Arg0)); }
	void test_case_3() { string Arg0 = "aabcaabc"; int Arg1 = 0; verify_case(3, Arg1, minChanges(Arg0)); }

	void test_case_4() { string Arg0 = "aaaaabaaaaabaaaaa"; int Arg1 = 2; verify_case(4, Arg1, minChanges(Arg0)); }
	void test_case_5() { string Arg0 = "qetuoadgjlzcbmqwertyuiopasdfghjklzxcvbnm"; int Arg1 = 12; verify_case(5, Arg1, minChanges(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    MakeSquare ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE


