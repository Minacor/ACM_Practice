#line 2 "InterestingNumber.cpp"
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

class InterestingNumber {
public:
    string xx;
    int vis[15];

    bool judge(char aim)
    {
        int cnt=0;
        int l=0;int r=0;
        for(int i = 0 ; i < xx.size() ;i++)
        {
            if(xx[i]==aim)
            {
                cnt++;
                if(cnt==1) l=i;
                if(cnt==2) r=i;
                if(cnt>2) return 0;
            }
        }

        if(r-l-1 == aim-'0')
            return 1;
        return 0;
    }

    string isInteresting(string x)
    {
        xx=x;
        memset(vis,0,sizeof vis);

        int ok=0;
        for(int i = 0 ; i < x.size() ; i++)
        {
            int cur = x[i]-'0';
            if(!vis[cur])
            {
                vis[cur]=1;
                ok = judge(x[i]);
                if(!ok) break;
            }
        }

        string str = ok ? "Interesting" : "Not interesting";
        return string(str);
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "2002"; string Arg1 = "Interesting"; verify_case(0, Arg1, isInteresting(Arg0)); }
	void test_case_1() { string Arg0 = "1001"; string Arg1 = "Not interesting"; verify_case(1, Arg1, isInteresting(Arg0)); }
	void test_case_2() { string Arg0 = "41312432"; string Arg1 = "Interesting"; verify_case(2, Arg1, isInteresting(Arg0)); }
	void test_case_3() { string Arg0 = "611"; string Arg1 = "Not interesting"; verify_case(3, Arg1, isInteresting(Arg0)); }
	void test_case_4() { string Arg0 = "64200246"; string Arg1 = "Interesting"; verify_case(4, Arg1, isInteresting(Arg0)); }
	void test_case_5() { string Arg0 = "631413164"; string Arg1 = "Not interesting"; verify_case(5, Arg1, isInteresting(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    InterestingNumber ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
