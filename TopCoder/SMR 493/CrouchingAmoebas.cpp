#line 2 "CrouchingAmoebas.cpp"
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
const int mov = 1000000000;
int dir[4][2] = {0,0,-1,0,0,1,-1,1};

class CrouchingAmoebas {
public:
    LL dis[60];

    int num;
    LL step(LL l,LL r,LL u,LL d ,LL x , LL y)
    {
        LL cnt=0;
        if(l > x) cnt += l-x;
        if(x > r) cnt += x-r;
        if(d > y) cnt += d-y;
        if(u < y) cnt += y-u;
        return cnt;
    }

    int count(vector <int> x, vector <int> y, int A, int T)
    {
        int num=x.size();
        int maxc = -1;
        for(int i = 0 ; i < num ; i++)
        {
            x[i]+=mov , y[i]+=mov;
        }

        for(int i = 0 ; i < x.size() ; i++)
        {
            for(int ii = 0 ; ii < y.size() ; ii++)
            {
                for(int j = 0 ; j < 4 ; j++)
                {
                    LL d = y[ii]+dir[j][0]*A;
                    LL r = x[i]+dir[j][1]*A;

                    int tmp = T,cnt=0;
                    for(int k = 0 ; k < num ; k++)
                    {
                        dis[k] = step(r-A,r,d+A,d,x[k],y[k]);
                    }
                    sort(dis,dis+num);

                    for(int pos = 0 ; pos < num && dis[pos] <= tmp ; pos++)
                    {
                        tmp-=dis[pos];
                        cnt++;
                    }

                    maxc = max(maxc,cnt);
                }
            }
        }
        return int(maxc);
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; int Arg4 = 3; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,0,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,3,0,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 4; int Arg4 = 4; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {-1000000000,1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1000000000,1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 15; int Arg4 = 1; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    CrouchingAmoebas ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
