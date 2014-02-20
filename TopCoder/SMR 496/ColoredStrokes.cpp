/*
 * 思路：
 * 对于每一行，计算有几段连续的R和G
 * 对于每一列，计算有几段连续的B和G
 * 累加
 */

#line 2 "ColoredStrokes.cpp"
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

class ColoredStrokes {
public:

    int getLeast(vector <string> picture)
    {
        int cntb[100],cntr[100];
        memset(cntb,0,sizeof cntb);
        memset(cntr,0,sizeof cntr);
        int n = picture.size();
        int m = picture[0].size();
        //cout << n << ' ' << m << endl;
        vector<string>g(picture);

        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
            {
                if(g[i][j] == 'R' || g[i][j] == 'G')
                {
                    cntr[i]++;
                    while(j<m && (g[i][j] == 'R' || g[i][j] == 'G'))
                        j++;
                }
            }

        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
            {
                if(g[j][i] == 'B' || g[j][i] == 'G')
                {
                    cntb[i]++;
                    while(j<n && (g[j][i] == 'B' || g[j][i] == 'G'))
                        j++;
                }
            }

        int ans=0;
        for(int i = 0 ; i < n ; i++)
            ans+=cntr[i];
        for(int i = 0 ; i < m ; i++)
            ans+=cntb[i];

        return int(ans);
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, getLeast(Arg0)); }
	void test_case_1() { string Arr0[] = {"..B.",
 "..B."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getLeast(Arg0)); }
	void test_case_2() { string Arr0[] = {".BB."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, getLeast(Arg0)); }
	void test_case_3() { string Arr0[] = {"...B..",
 ".BRGRR",
 ".B.B.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, getLeast(Arg0)); }
	void test_case_4() { string Arr0[] = {"...B..",
 ".BRBRR",
 ".B.B.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, getLeast(Arg0)); }
	void test_case_5() { string Arr0[] = {"GR",
 "BG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(5, Arg1, getLeast(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    ColoredStrokes ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
