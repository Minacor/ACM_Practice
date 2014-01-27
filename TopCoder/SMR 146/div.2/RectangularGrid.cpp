/*
 * 题意：
 * 求一个矩阵里面有多少个子矩阵，正方形不算，1*2和2*1算两种
 *
 * 思路：
 * 数据量小，直接暴力
 */

#line 2 "RectangularGrid.cpp"
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

class RectangularGrid {
public:
    long long countRectangles(int width, int height) {

        LL ans=0;
        for(int i = 1 ; i <= width ; i++)
            for(int j = 1 ; j <= height ; j++)
            {
                if(i == j) continue;
                ans += (width-i+1)*(height-j+1);
            }
        return (long long)(ans);
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; long long Arg2 = 22LL; verify_case(0, Arg2, countRectangles(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; long long Arg2 = 31LL; verify_case(1, Arg2, countRectangles(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; long long Arg2 = 2640LL; verify_case(2, Arg2, countRectangles(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; long long Arg2 = 0LL; verify_case(3, Arg2, countRectangles(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 592; int Arg1 = 964; long long Arg2 = 81508708664LL; verify_case(4, Arg2, countRectangles(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    RectangularGrid ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
