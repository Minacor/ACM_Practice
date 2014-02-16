#line 2 "PackingBallsDiv1.cpp"
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

class PackingBallsDiv1 {
public:
    LL X[100000+100],XX[100000+100];

    int minPacks(int K, int A, int B, int C, int D) {

        memset(X,0,sizeof(X));
        memset(XX,0,sizeof(XX));
        X[0]=A;
        int sum=0;
        for(int i = 1 ; i < K ; i++)
            X[i] = (X[i-1]*B+C)%D+1;
        sort(X,X+K);

        int out=0,mir=0;
        for(int i = 0 ; i < K ; i++)
        {
            int p;
            p=X[i]/K;
            XX[i] = X[i]%K;
            out += p;
        }
        //cout << out << endl;
        sort(XX,XX+K);
        for(int i = 0 ; i < K ; i++)
        {
            LL t = (XX[i]-mir);
            if(!t) continue;
            if(t >= K-i-1 )
                out++;
            else{
            out += t;
            mir += (XX[i]-mir);}
        }

        return int(out);
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 2; int Arg3 = 5; int Arg4 = 6; int Arg5 = 4; verify_case(0, Arg5, minPacks(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 58; int Arg2 = 23; int Arg3 = 39; int Arg4 = 93; int Arg5 = 58; verify_case(1, Arg5, minPacks(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 23; int Arg1 = 10988; int Arg2 = 5573; int Arg3 = 4384; int Arg4 = 100007; int Arg5 = 47743; verify_case(2, Arg5, minPacks(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 100000; int Arg1 = 123456789; int Arg2 = 234567890; int Arg3 = 345678901; int Arg4 = 1000000000; int Arg5 = 331988732; verify_case(3, Arg5, minPacks(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    PackingBallsDiv1 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
