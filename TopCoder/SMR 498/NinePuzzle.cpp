/*
 * 题意：
 * 使得第一种状态可达第二种状态的更改颜色的最少数量
 *
 * 思路：
 * 想通了就是大水题
 * 只要把1的颜色改成和2一样的就一定可达....
 */
#line 2 "NinePuzzle.cpp"
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

class NinePuzzle {
public:
    int getMinimumCost(string init, string goal)
    {
        int cnt1[150],cnt2[150];
        memset(cnt1,0,sizeof cnt1);
        memset(cnt2,0,sizeof cnt2);

        for(int i = 0 ; i < init.size() ; i++)
            cnt1[init[i]]++;
        for(int i = 0 ; i < goal.size() ; i++)
            cnt2[goal[i]]++;
        int ans=0;

        int a1=cnt1['R'],b1=cnt1['G'],c1=cnt1['B'],d1=cnt1['Y'];
        int a2=cnt2['R'],b2=cnt2['G'],c2=cnt2['B'],d2=cnt2['Y'];

        ans += a2<a1?0:a2-a1;
        ans += b2<b1?0:b2-b1;
        ans += c2<c1?0:c2-c1;
        ans += d2<d1?0:d2-d1;
        return int(ans);
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BG*YRGRRYR" ; string Arg1 = "BGGY*YRRRR" ; int Arg2 = 0; verify_case(0, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "GBBB*BGBBG" ; string Arg1 = "RYYY*YRYYR"; int Arg2 = 9; verify_case(1, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "RRBR*BRBBB" ; string Arg1 = "BBRB*RBRRR" ; int Arg2 = 1; verify_case(2, Arg2, getMinimumCost(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    NinePuzzle ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
