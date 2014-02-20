/*
 * 题意：
 * 构造一个序列，使得sig[i]若是D，则相应两个数应该递减，I反之
 *
 * 思路：
 * 先构造1,2,3,4,...,n然后遇到D就交换，直到扫描一遍序列不用交换为止
 */
#line 2 "PermutationSignature.cpp"
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

class PermutationSignature {
public:
    int a[100];
    int use[100];
    vector <int> reconstruct(string signature)
    {
        vector<int> out;
        int g[100];
        int minc=10000;
        memset(a,0,sizeof a);

        out.push_back(1);
        for(int i = 0 ; i < signature.size() ; i++)
        {
            out.push_back(i+2);
            if(signature[i] == 'D')
                g[i]=1;
            else g[i]=-1;
        }

        while(1)    //如果不反复扫描就会被"DD"叉掉
        {
            int ok=1;
            for(int i = 0 ; i < signature.size() ; i++)
                if(g[i]==1 && out[i]<out[i+1])
                    ok=0,swap(out[i],out[i+1]);
            if(ok)
                break;
        }

        return vector <int>(out);
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "IIIII"; int Arr1[] = {1, 2, 3, 4, 5, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, reconstruct(Arg0)); }
	void test_case_1() { string Arg0 = "DI"; int Arr1[] = {2, 1, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, reconstruct(Arg0)); }
	void test_case_2() { string Arg0 = "IIIID"; int Arr1[] = {1, 2, 3, 4, 6, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, reconstruct(Arg0)); }
	void test_case_3() { string Arg0 = "DIIDID"; int Arr1[] = {2, 1, 3, 5, 4, 7, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, reconstruct(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    PermutationSignature ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
