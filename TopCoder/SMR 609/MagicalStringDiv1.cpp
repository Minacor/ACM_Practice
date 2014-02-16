#line 2 "MagicalStringDiv1.cpp"
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

class MagicalStringDiv1 {
public:
    int getLongest(string S) {

        int l=0,r=0;
        int maxc=0;
        for(int i = 0 ; i < S.size() ; i++)
            if(S[i]=='>') l++;
            else r++;

        for(int cnt=1 ; cnt <= l ; cnt++)
        {
            int tmp=0,totl=0,totr=0,ok=0;
            for(int i = 0 ; i < S.size() ; i++)
            {
                if(tmp <= cnt && S[i] == '>') tmp++,totl++;
                else if(tmp>cnt && S[i] == '<') totr++;
            }
            if(totl == totr) maxc = max(maxc,totl+totr);
        }
        return int(maxc);
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "<><><<>"; int Arg1 = 4; verify_case(0, Arg1, getLongest(Arg0)); }
	void test_case_1() { string Arg0 = ">>><<<"; int Arg1 = 6; verify_case(1, Arg1, getLongest(Arg0)); }
	void test_case_2() { string Arg0 = "<<<>>>"; int Arg1 = 0; verify_case(2, Arg1, getLongest(Arg0)); }
	void test_case_3() { string Arg0 = "<<<<><>>><>>><>><>><>>><<<<>><>>>>><<>>>>><><<<<>>"; int Arg1 = 24; verify_case(3, Arg1, getLongest(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    MagicalStringDiv1 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
