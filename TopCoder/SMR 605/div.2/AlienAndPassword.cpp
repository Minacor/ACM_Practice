/*
 * 题型：字符串乱搞
 *
 * 题意：给一个字符串，求剔除一个字符之后能得到多少不同的字符串
 *
 * 思路：如果一个字符和周围字符一样的话，那么去掉这一个字符和去掉这些和他相邻且一样的字符，得到的字符串是一样的
 * 所以我们只要O(n)判断一个字符是否和前一个字符相同，不同的话就计数。
 */


#line 2 "AlienAndPassword.cpp"
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

class AlienAndPassword {
public:
    int getNumber(string S) {

        int cnt=0;

        for(int i = 1 ; i < S.size() ; i++)
        {
            if(S[i] != S[i-1])
                cnt++;
        }

        return int(cnt+1);
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "A"; int Arg1 = 1; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { string Arg0 = "ABA"; int Arg1 = 3; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arg0 = "AABACCCCABAA"; int Arg1 = 7; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arg0 = "AGAAGAHHHHFTQLLAPUURQQRRRUFJJSBSZVJZZZ"; int Arg1 = 26; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arg0 = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"; int Arg1 = 1; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    AlienAndPassword ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
