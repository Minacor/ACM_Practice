/*
 * 思路：
 * 如果R能够一次移动成功则R赢，如果R不能一次移动成功，且不论R怎么移动第一步，S都能一步移动成功则S赢
 * 否则平局，因为可以反复在两个状态之间翻转
 */

#line 2 "StonesGame.cpp"
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

class StonesGame {
public:
    int left , right;
    //返回1表示当前能够由m移动到l
    int gao(int n , int m , int k , int l)
    {
        if(l-k+1 >= 1)
            left = l-k+1;
        else
            left = k-l+1;
        if(l+k-1<=n)
            right = l+k-1;
        else
            right = 2*n-(l+k-1);

        if(m >= left && m <= right && ((left-m)%2==0||(right-m)%2==0))
            return 1;
        return 0;
    }

    string winner(int N, int M, int K, int L) {

        if(gao(N,M,K,L))
            return "Romeo";

        for(int i = 1 ; i <= N ; i++)
            if(!gao(N,i,K,L)&&gao(N,M,K,i))
                return "Draw";
        return "Strangelet";
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; string Arg4 = "Draw"; verify_case(0, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 2; int Arg3 = 2; string Arg4 = "Romeo"; verify_case(1, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 2; int Arg3 = 3; string Arg4 = "Strangelet"; verify_case(2, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 2; int Arg3 = 2; string Arg4 = "Draw"; verify_case(3, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 804588; int Arg2 = 705444; int Arg3 = 292263; string Arg4 = "Romeo"; verify_case(4, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 1000000; int Arg1 = 100000; int Arg2 = 500000; int Arg3 = 600000; string Arg4 = "Strangelet"; verify_case(5, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    StonesGame ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
