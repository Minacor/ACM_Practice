/*
 * 题意：
 * 给一个三角阵，其中'.'表示可旋转，'X'表示不可旋转，每个点的颜色不同
 * 旋转：两两相邻的三个'.'(即一个三角形),可以旋转，每一次旋转得到一个相对颜色分布不同的三角形
 * 问给出的三角阵经过各个子三角形旋转得到多少不同的颜色分布
 *
 * 思路：
 * 规律：一个三角形旋转可得到3个 ...
 * 一个子阵中都是'.'，且任意点必与某两点相邻构成一个可旋转三角，总点数为n，则可以得到A(n,n)/2,即n!/2种不同的颜色分布
 * 那么只要统计这样的子阵有几个就可以了，结果累乘
 * 一个点属于一个子阵这样的统计，是并查集的经典运用
 */

#line 2 "HexagonPuzzle.cpp"
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
const int mod = 1000000007;

class HexagonPuzzle {
public:
    vector<string> g;
    int len;
    int f[60*60];
    LL cnt[60*60];

    int find(int x)
    {
        return x != f[x] ? f[x] = find(f[x]) : x;
    }

    void merger(int x , int y)
    {
        x = find(x);
        y = find(y);

        if(x != y)
            f[y]=x;
    }

    //每个点的编号，从上到下，从左至右,1-base
    int pos(int x , int y)
    {
        return (1+x)*x/2+y+1;
    }

    // 判断子阵或者点能否合并成一个
    void ju(int x , int y)
    {
        if(x+1<len && y-1>=0 &&
        g[x+1][y]=='.'&&g[x][y-1]=='.')
        {
            merger(f[pos(x,y)],f[pos(x+1,y)]);
            merger(f[pos(x,y)],f[pos(x,y-1)]);
        }

        if(x-1>=0 && y+1<=x+1&&
        g[x-1][y]=='.'&&g[x][y+1]=='.')
        {
            merger(f[pos(x,y)],f[pos(x-1,y)]);
            merger(f[pos(x,y)],f[pos(x,y+1)]);
        }
    }

    //计算A(n,n)/2
    LL calc(LL n)
    {
        LL sum=1;
        for(LL i = 1 ; i <= n ; i++)
        {
            //注意同余定理对除法不适用！！ 所以要先除掉2，而非计算完毕之后再除2
            if(i==2) continue;
            sum = (sum*i)%mod;
        }
        //sum/=2;
        return sum;
    }

    int theCount(vector <string> board)
    {
        memset(cnt,0,sizeof cnt);
        len = board.size();
        g = board;
        LL sum=1;
        int tot = (1+len)*len/2;
        for(int i = 0 ; i <= tot ; i++)
            f[i]=i;

        for(int i = 0 ; i < board.size() ; i++)
            for(int j = 0 ; j <= i ; j++)
                if(board[i][j] == '.')
                    ju(i,j);

        for(int i = 1 ; i <= tot ; i++)
            cnt[find(i)]++;
        int ok=0;
        for(int i = 1 ; i <= tot ; i++)
        {
            if(cnt[i] < 3)
                continue;
            else
            {
                cout << cnt[i] << endl;
                sum = (sum * calc(cnt[i]))%mod;
            }
        }

        return int(sum%mod);
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".",
 ".X",
 "X..",
 ".X.X"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { string Arr0[] = {"X"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { string Arr0[] = {".",
 "..",
 "...",
 ".X.."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20160; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { string Arr0[] = {".",
 "..",
 "XXX",
 "..X.",
 ".X..X",
 "XXXX..",
 "..X.X.X",
 "..X.XX.."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 108; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { string Arr0[] = {".",
 "..",
 "...",
 "....",
 ".....",
 "......",
 ".......",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 261547992; verify_case(4, Arg1, theCount(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    HexagonPuzzle ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE

