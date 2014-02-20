#line 2 "Painting.cpp"
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

class Painting {
public:
    int g[60][60];
    int n,m;
    bool ju(int sx,int sy,int s,vector<string> pic)
    {
        if(sx+s>n || sy+s>m)
            return 0;

        for(int i = sx ; i < sx+s ; i++)
            if(pic[i][sy] == 'B' && (g[i][sy+s-1]-(sy?g[i][sy-1]:0)) == s);
            else return 0;
        return 1;
    }
    int largestBrush(vector <string> picture)
    {
        n = picture.size();
        m = picture[0].size();

        memset(g,0,sizeof g);
        int maxc[60][60];

        for(int i = 0 ; i < n ; i++)
        {
            maxc[i][0]=1;
            g[i][0] = (picture[i][0]=='B');
            for(int j = 1 ; j < m ; j++)
            {
                g[i][j] = g[i][j-1] + (picture[i][j] == 'B');
                maxc[i][j]=1;
            }
        }

        for(int len = min(n,m) ; len >= 2 ; len--)
        {
            for(int i = 0 ;i < n ; i++)
            {
                for(int j = 0 ; j < m ; j++)
                    if(ju(i,j,len,picture))
                        for(int x = i ; x < i+len ; x++)
                            for(int y = j ; y < j+len ; y++)
                                maxc[x][y]=max(len,maxc[x][y]);
            }
        }
        int minc = 1000000;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(picture[i][j]=='B')
                    minc = min(minc,maxc[i][j]);
        return minc;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BBBB",
 "BBBB",
 "BBBB",
 "BBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, largestBrush(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBBB",
 "BWWB",
 "BWWB",
 "BBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, largestBrush(Arg0)); }
	void test_case_2() { string Arr0[] = {"WBBBBB",
 "BBBBBB",
 "BBBBBB",
 "BBBBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, largestBrush(Arg0)); }
	void test_case_3() { string Arr0[] = {"BBBB",
 "BBBB",
 "WBBB",
 "BBBB",
 "BBBB",
 "BBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, largestBrush(Arg0)); }
	void test_case_4() { string Arr0[] = {"WBBBBBWWWWWWWWW",
 "WBBBBBBWWWWWWWW",
 "WBBBBBBBBBBBWWW",
 "WBBBBBBBBBBBWWW",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBWWBBBBB",
 "BBBBBBBBWBBBBBB",
 "WBBBBBBBWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBWWWBBBBBW",
 "BBBBBWWWWWWWWWW",
 "BBBBBWWWWWWWWWW"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, largestBrush(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    Painting ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
