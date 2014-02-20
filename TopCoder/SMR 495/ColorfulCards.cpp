/*
 * 正向构造一个序列，反向构造一个序列，相应位置相同的就是确定的
 */

#line 2 "ColorfulCards.cpp"
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

class ColorfulCards {
public:
    int prime[1010];
    int n;

    void mk()
    {
        memset(prime,0,sizeof prime);
        prime[1]=1;
        for(int i = 2 ; i <= n ; i++)
            if(!prime[i])
            {
                for(int j = 2*i ; j <= n ; j+=i)
                    prime[j]=1;
            }
    }

    vector <int> theCards(int N, string colors)
    {
        n=N;
        vector<int> zheng,fan,out;
        zheng.clear();fan.clear();out.clear();
        mk();
//        for(int i = 0 ; i <= n ; i++)
//            if(!prime[i])cout << i << ' ';cout << endl;
        int j=1;
        for(int i = 0 ; i < colors.size() ; i++)
        {
            if(colors[i] == 'R')
                while(j<=n)
                {
                    if(!prime[j])
                    {
                        zheng.push_back(j);
                        j++;
                        break;
                    }
                    j++;
                }
            else
            {
                while(j<=n)
                {
                    if(prime[j])
                    {
                        zheng.push_back(j);
                        j++;
                        break;
                    }
                    j++;
                }
            }

        }

        j=n;
        for(int i = colors.size()-1 ; i >= 0 ; i--)
        {
            if(colors[i] == 'R')
                while(j>=1)
                {
                    if(!prime[j])
                    {
                        fan.push_back(j);
                        j--;
                        break;
                    }
                    j--;
                }
            else
            {
                while(j>=1)
                {
                    if(prime[j])
                    {
                        fan.push_back(j);
                        j--;
                        break;
                    }
                    j--;
                }
            }

        }

        int len = zheng.size();
        reverse(fan.begin(),fan.end());

 //       for(int i = 0 ; i < zheng.size() ; i++) cout << zheng[i] << ' ';cout<<endl;
 //       for(int i = 0 ; i < fan.size() ; i++) cout << fan[i] << ' ';cout<<endl;
        for(int i = 0 ; i < len ; i++)
            if(zheng[i] == fan[i])
                out.push_back(zheng[i]);
            else
                out.push_back(-1);

        return out;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; string Arg1 = "RRR"; int Arr2[] = {2, 3, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, theCards(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; string Arg1 = "BBB"; int Arr2[] = {1, 4, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, theCards(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; string Arg1 = "RBR"; int Arr2[] = {-1, 4, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, theCards(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 58; string Arg1 = "RBRRBRBBRBRRBBRRBBBRRBBBRR"; int Arr2[] = {-1, -1, -1, -1, -1, -1, -1, -1, 17, 18, 19, 23, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 47, 53 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, theCards(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 495; string Arg1 = "RBRRBRBBRBRRBBRRBBBRRBBBRR"; int Arr2[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, theCards(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    ColorfulCards ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
