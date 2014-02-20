/*
 * ���⣺
 * �����г���Ϊn���ַ���(���Ǵ�д��ĸ���)�������������ַ�������
 * ������һ���ַ��������г���Ϊm�Ļ��Ĵ��� >= k
 *
 * ˼·:
 * ����n��������dfs����ģʽ��
 * ģʽ���������������:1 2 1 3...ǰk���������������������ֲ�ͬ��ʾ��λ�õ���ĸ��ͬ
 * ���ʵ�ʴ��ĸ�����C(26,ģʽ���в�ͬ���ֵ�������)
 * Ѱ�һ��Ĵ�����ż��������
 */

#line 2 "PalindromfulString.cpp"
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

class PalindromfulString {
public:
    int n,m,k;
    LL sum;
    int cnt;

    LL calc(int a[20])
    {
        LL z=1,tmp=26;
        map<int,int> lis;
        lis.clear();
        for(int i = 0 ; i < n ; i++)
            lis[a[i]]++;
        int len = lis.size();
        while(len--)
            z*=(tmp--);

        return z;
    }

    LL gao(int a[20])
    {
        cnt=0;
        for(int pos = 0 ; pos < n ; pos++)
        {
            for(int i = pos,j = pos+1 ; i>=0 && j <n && a[i]==a[j] ; i--,j++)
                if(j-i+1==m)
                {
                    cnt++;break;
                }
            for(int i = pos , j = pos ; i>=0 && j < n && a[i]==a[j] ; i--,j++)
                if(j-i+1==m)
                {
                    cnt++;break;
                }
        }

        if(cnt >= k)
        {
            return calc(a);
        }
        return 0;
    }

    void dfs(int a[20],int id,int maxid,int cnt)
    {
        maxid=max(maxid,id);
        a[cnt] = id;
        if(cnt==n-1)
        {
            sum += gao(a);
            return ;
        }

        for(int i = 1 ; i <= maxid+1 ; i++)
            dfs(a,i,maxid,cnt+1);
    }

    long long count(int N, int M, int K)
    {
        n=N,m=M,k=K; sum=0;
        int a[20];
        memset(a,0,sizeof a);
        dfs(a,1,1,0);

        return sum;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; long long Arg3 = 26LL; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 0; long long Arg3 = 676LL; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; long long Arg3 = 1326LL; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 1; long long Arg3 = 676LL; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 7; int Arg1 = 3; int Arg2 = 3; long long Arg3 = 4310176LL; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    PalindromfulString ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
