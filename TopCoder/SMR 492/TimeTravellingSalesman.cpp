#line 2 "TimeTravellingSalesman.cpp"
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
const int inf=522133279;

class TimeTravellingSalesman {
public:
    LL g[1010][1010];
    LL low[1010];
    int vis[1010];
    int n;

    LL prim()
    {
        vis[0]=1;
        low[0]=0;
        LL sum=0;
        for(int i = 1 ; i < n ; i++)
            low[i] = g[0][i];

        for(int i = 1 ;i < n ; i++)
        {
            LL minc = inf;
            int pos;
            for(int j = 0 ; j < n ; j++)
                if(!vis[j] && minc > low[j])
                {
                    minc = low[j];
                    pos = j;
                }
            if(minc == inf)
               return -1;
            vis[pos]=1;
            sum+=minc;

            for(int j = 0 ; j < n ; j++)
            {
                if(!vis[j] && low[j] > g[pos][j])
                    low[j] = g[pos][j];
            }
        }
        return sum;
    }

    long long determineCost(int N, vector <string> roads)
    {
        n=N;
        for(int i = 0 ; i <= n ; i++)
        {
            low[i]=inf;
            for(int j = 0 ; j <= n ; j++)
                g[i][j]=inf;
        }

        string s="";
        for(int i = 0 ; i < roads.size() ; i++)
            s += roads[i];
        for(int i = 0 ; i < s.size() ; i++)
            if(s[i] == ',') s[i] = ' ';
        cout << s << endl;
        istringstream iss(s);
        int a,b,c;
        while(iss >> a >> b >> c)
            g[a][b] = g[b][a]=c;

        return prim();
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"0,1,1 0,2,1 1,2,2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(0, Arg2, determineCost(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; string Arr1[] = {"0,1,2 1,4,2 4,3,3 2,4,4 0,5,3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 14LL; verify_case(1, Arg2, determineCost(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"0,2,2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = -1LL; verify_case(2, Arg2, determineCost(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; string Arr1[] = {"1,0",",10","0 2,1",",584 3,2",",754"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1438LL; verify_case(3, Arg2, determineCost(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    TimeTravellingSalesman ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
