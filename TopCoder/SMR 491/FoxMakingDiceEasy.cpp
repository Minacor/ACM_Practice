#line 2 "FoxMakingDiceEasy.cpp"
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

class FoxMakingDiceEasy {
public:
    int theCount(int N, int K) {

        int vis[60];
        int ans=0;
        for(int i = K ; i <= 2*N ; i++)
        {
            for(int a = 1 ; a < (i+1)/2 ; a++)
                for(int b = a+1; b < (i+1)/2 ;b++)
                    for(int c = b+1 ; c < (i+1)/2 ; c++)
                    {
                        if(i-a <= N && i-b<=N && i-c<=N)
                            ans+=2;
                    }
        }
        return int(ans);
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 7; int Arg2 = 2; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 7; int Arg2 = 0; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 50; int Arg1 = 1; int Arg2 = 105800; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 31; int Arg1 = 46; int Arg2 = 504; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 48; verify_case(4, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    FoxMakingDiceEasy ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
