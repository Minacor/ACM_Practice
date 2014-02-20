/*
 * 题意：
 * 找到一对数[A,B],使得这个区间内的数包含所有给出的被接受的数，且不包含任何一个被拒绝的数，且这个区间最小
 * 不存在返回空vector
 *
 * 思路：
 * 记录第一个被接受的数的位置l和最后一个被接受的数的位置r，枚举中间的数
 * 如果中间出现不被接受的数则直接退出，不可行
 * 否则答案就是(l,r)
 */

#line 2 "Filtering.cpp"
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

class Filtering {
public:
    vector <int> designFilter(vector <int> sizes, string outcome)
    {
        int biaoji[110];
        memset(biaoji,0,sizeof biaoji);
        int l=200,r=-1;
        int outl,outr;
        for(int i = 0; i < sizes.size() ; i++)
        {
            if(outcome[i]=='A')
            {
                l = min(l,sizes[i]);
                r = max(r,sizes[i]);
                biaoji[sizes[i]]=1;
            }
            else biaoji[sizes[i]]=-1;
        }
        int ok=1;
        for(int i = l ; i <= r ; i++)
        {
            if(biaoji[i]==-1)
            {
                ok=0;
                break;
            }
        }
        vector<int> out;
        out.clear();
        if(ok)
            out.push_back(l),out.push_back(r);
        return vector <int>(out);
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AAAAA"; int Arr2[] = {3, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, designFilter(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AARAA"; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, designFilter(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "RAAAA"; int Arr2[] = {4, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, designFilter(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {68,57,7,41,76,53,43,77,84,52,34,48,27,75,36}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "RARRRARRRARARRR"; int Arr2[] = {48, 57 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, designFilter(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {26,81,9,14,43,77,55,57,12,34,29,79,40,25,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ARAAARRARARARAA"; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, designFilter(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    Filtering ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
