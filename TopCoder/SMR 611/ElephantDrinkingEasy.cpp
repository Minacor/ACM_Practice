#line 2 "ElephantDrinkingEasy.cpp"
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

class ElephantDrinkingEasy {
public:
    //int vis[10][10];
    vector<string> g;
    int n;
    int ok;

    int ju(int x , int y)
    {
        ok=1;
        for(int i = x-1 ; i >= 0 ; i--) //shang
        {
            if(g[i][y]=='Y'||g[i][y]=='W')
            {
                ok=0;break;
            }
        }


        if(ok)
        {
            for(int i = x-1 ; i >= 0 ; i--)
                g[i][y] = 'W';
            return 1;
        }

        ok=1;
        for(int i = y-1 ; i >= 0 ; i--) //zuo
        if(g[x][i]=='Y'||g[x][i]=='W')
        {
            ok=0;break;
        }

        if(ok)
        {
            for(int i = y-1 ; i >= 0 ; i--)
                g[x][i] = 'W';
            return 1;
        }

        ok=1;
        for(int i = y+1 ; i < n ; i++)  //you
        if(g[x][i]=='Y'||g[x][i] == 'W')
        {
            ok=0;break;
        }


        if(ok)
        {
            for(int i = y+1 ; i < n ; i++)
                g[x][i] = 'W';
            return 1;
        }

        ok=1;
        for(int i = x+1 ; i < n ; i++)      //xia
            if(g[i][y]=='Y'||g[i][y]=='W')
            {
                ok=0;break;
            }

        if(ok)
        {
            for(int i = x+1 ; i < n ; i++)
                g[i][y] = 'W';
            return 1;
        }

        return ok;

    }
    int maxElephants(vector <string> map)
    {
        g=map;
        n=map.size();
        int cnt=0;
        for(int i = 0 ; i < map.size() ; i++)
            for(int j = 0 ; j < map.size() ; j++)
                if(map[i][j] == 'Y')
                    cnt += ju(i,j);
        return int(cnt);
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NNNNN",
 "NNYYN",
 "NYNNN",
 "NNYNN",
 "NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, maxElephants(Arg0)); }
	void test_case_1() { string Arr0[] = {"YYY",
 "YYY",
 "YYY"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, maxElephants(Arg0)); }
	void test_case_2() { string Arr0[] =  {"YNYN",
  "NNYY",
  "YYNN",
  "YYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, maxElephants(Arg0)); }
	void test_case_3() { string Arr0[] =  {"YNYN",
  "YNYY",
  "YYNN",
  "YYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, maxElephants(Arg0)); }
	void test_case_4() { string Arr0[] = {"YYNYN",
 "NYNNY",
 "YNYNN",
 "YYNYY",
 "YYNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(4, Arg1, maxElephants(Arg0)); }
	void test_case_5() { string Arr0[] = {"YYNYN",
 "NYNYY",
 "YNYYN",
 "YYNYY",
 "YYNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(5, Arg1, maxElephants(Arg0)); }
	void test_case_6() { string Arr0[] = {"NN",
 "NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(6, Arg1, maxElephants(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    ElephantDrinkingEasy ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
