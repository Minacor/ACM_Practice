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
}