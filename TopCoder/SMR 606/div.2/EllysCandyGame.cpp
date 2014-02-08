/*
 * 题意：
 * 有一堆箱子里面有一些糖，L,K两人轮流拿，L先拿，拿光一个箱子里的糖相邻两个箱子的糖会翻倍，拿光糖为止
 * 每个人都是最优决策，最后谁糖多谁赢
 *
 * 输出赢的人的名字或者平局
 *
 */

#line 2 "EllysCandyGame.cpp"
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
const int inf = 522133279;
typedef long long LL;

class EllysCandyGame {
public:
    int num;
    int up=0;
    int sw[20];
    string out;

    int dfs(int x,int y , bool cur , int turn)
    {
        if(turn == num)
            return x-y;

        int ans=-inf;

        for(int i = 1 ; i <= up  ; i++)
        {
            if(!sw[i]) continue;

//            if(cur) y += sw[i];
//            else x += sw[i];

            int t1=sw[i],t2=sw[i-1],t3=sw[i+1];
            sw[i]=0;sw[i-1]*=2;sw[i+1]*=2;

            ans = max(ans , -dfs(y,x+t1,!cur,turn+1));

//            if(cur) y -= t1;
//            else x -= t1;
            sw[i] = t1 ; sw[i-1] = t2 ; sw[i+1] = t3;
        }

        return ans;
    }

    string getWinner(vector <int> sweets) {

        memset(sw,0,sizeof sw);
        num=0;
        up = sweets.size();
        for(int i = 0 ; i < up ; i++)
        {
            sw[i+1]=sweets[i];
            if(sweets[i]) num++;
        }

        int ans= dfs(0,0,false,0);

        if(ans > 0) out = "Elly";
        else if(ans == 0) out = "Draw";
        else out = "Kris";

        return string(out);
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {20, 50, 70, 0, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Kris"; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { int Arr0[] = {42, 13, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Elly"; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { int Arr0[] = {10, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Draw"; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { int Arr0[] = {3, 1, 7, 11, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Kris"; verify_case(3, Arg1, getWinner(Arg0)); }
	void test_case_4() { int Arr0[] = {41, 449, 328, 474, 150, 501, 467, 329, 536, 440}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Kris"; verify_case(4, Arg1, getWinner(Arg0)); }
	void test_case_5() { int Arr0[] = {177, 131, 142, 171, 411, 391, 17, 222, 100, 298}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Elly"; verify_case(5, Arg1, getWinner(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    EllysCandyGame ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
