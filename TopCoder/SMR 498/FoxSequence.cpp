/*
 * 题意：
 * 给一个数列判断是否满足以下条件
 * 对于0 < a < b <= c < d < N-1
 * 0~a阶段是递增等差数列
 * a~b阶段是递减等差数列
 * b~c阶段的数全相同
 * c~d阶段是递增等差数列
 * d~N-1阶段是递减等差数列
 */

#line 2 "FoxSequence.cpp"
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

class FoxSequence {
public:
    vector<int> g;
    // 判断数列类型，注意转折点的判断
    int ju(int i)
    {
        if (g[i]*2 == g[i-1]+g[i+1] && g[i]>g[i-1])
            return 1; //上升等差
        if(g[i]*2 == g[i-1]+g[i+1] && g[i]<g[i-1])
            return 3; // 下降等差
        if(g[i] == g[i-1] && g[i] == g[i+1])
            return 2;
        if(g[i-1]<g[i]&&g[i]>g[i+1])
            return 3;
        if(g[i-1]>g[i]&&g[i]<g[i+1] || g[i-1]==g[i]&&g[i]<g[i+1])
            return 1;
        if(g[i-1]>g[i]&&g[i]==g[i+1])
            return 2;

        return 0;
    }

    string isValid(vector <int> seq)
    {
        g=seq;
        int n = seq.size();
        vector< pair<int,int> > state;
        int ok=1;

        //千万注意初始两个点的判断，因为判断函数是不包括的
        if(g[0]<g[1]) state.push_back(make_pair(1,1));
        else return "NO";
        for(int i = 1 ; i < n-1 ; i++)
        {
            int cur = ju(i);
            //cout << cur << endl;
            if(!cur){ok=0;break;}
            else                    //合并，之前做过类似的练习题
            {
                if(!state.empty()&&state[state.size()-1].first == cur)
                    state[state.size()-1].second++;
                else
                    state.push_back(make_pair(cur,1));
            }
        }

//        cout << ok << endl;
//        for(int i = 0; i < state.size() ; i++)
//            cout << state[i].first << ' ';
//            cout << endl;
        if(ok)
        {
            if(state.size()==5)
            {
                if(state[0].first==1 &&
                state[1].first==3 &&
                state[2].first==2 &&
                state[3].first==1 &&
                state[4].first==3);
                else
                    ok=0;
            }
            else if(state.size()==4)
            {
                if(state[0].first==1 &&
                state[1].first==3 &&
                state[2].first==1 &&
                state[3].first==3);
                else
                    ok=0;
            }
            else ok=0;
        }

        return ok ? "YES" : "NO";
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,5,7,5,3,1,1,1,3,5,7,5,3,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, isValid(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3,4,5,4,3,2,2,2,3,4,5,6,4}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(1, Arg1, isValid(Arg0)); }
	void test_case_2() { int Arr0[] = {3,6,9,1,9,5,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, isValid(Arg0)); }
	void test_case_3() { int Arr0[] = {1,2,3,2,1,2,3,2,1,2,3,2,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, isValid(Arg0)); }
	void test_case_4() { int Arr0[] = {1,3,4,3,1,1,1,1,3,4,3,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, isValid(Arg0)); }
	void test_case_5() { int Arr0[] = {6,1,6}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(5, Arg1, isValid(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    FoxSequence ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
