/*
 * ���⣺
 * ��һ������������'.'��ʾ����ת��'X'��ʾ������ת��ÿ�������ɫ��ͬ
 * ��ת���������ڵ�����'.'(��һ��������),������ת��ÿһ����ת�õ�һ�������ɫ�ֲ���ͬ��������
 * �ʸ����������󾭹���������������ת�õ����ٲ�ͬ����ɫ�ֲ�
 *
 * ˼·��
 * ���ɣ�һ����������ת�ɵõ�3�� ...
 * һ�������ж���'.'������������ĳ�������ڹ���һ������ת���ǣ��ܵ���Ϊn������Եõ�A(n,n)/2,��n!/2�ֲ�ͬ����ɫ�ֲ�
 * ��ôֻҪͳ�������������м����Ϳ����ˣ�����۳�
 * һ��������һ������������ͳ�ƣ��ǲ��鼯�ľ�������
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

    //ÿ����ı�ţ����ϵ��£���������,1-base
    int pos(int x , int y)
    {
        return (1+x)*x/2+y+1;
    }

    // �ж�������ߵ��ܷ�ϲ���һ��
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

    //����A(n,n)/2
    LL calc(LL n)
    {
        LL sum=1;
        for(LL i = 1 ; i <= n ; i++)
        {
            //ע��ͬ�ඨ��Գ��������ã��� ����Ҫ�ȳ���2�����Ǽ������֮���ٳ�2
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

