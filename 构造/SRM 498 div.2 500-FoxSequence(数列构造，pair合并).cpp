/*
 * ���⣺
 * ��һ�������ж��Ƿ�������������
 * ����0 < a < b <= c < d < N-1
 * 0~a�׶��ǵ����Ȳ�����
 * a~b�׶��ǵݼ��Ȳ�����
 * b~c�׶ε���ȫ��ͬ
 * c~d�׶��ǵ����Ȳ�����
 * d~N-1�׶��ǵݼ��Ȳ�����
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
    // �ж��������ͣ�ע��ת�۵���ж�
    int ju(int i)
    {
        if (g[i]*2 == g[i-1]+g[i+1] && g[i]>g[i-1])
            return 1; //�����Ȳ�
        if(g[i]*2 == g[i-1]+g[i+1] && g[i]<g[i-1])
            return 3; // �½��Ȳ�
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

        //ǧ��ע���ʼ��������жϣ���Ϊ�жϺ����ǲ�������
        if(g[0]<g[1]) state.push_back(make_pair(1,1));
        else return "NO";
        for(int i = 1 ; i < n-1 ; i++)
        {
            int cur = ju(i);
            //cout << cur << endl;
            if(!cur){ok=0;break;}
            else                    //�ϲ���֮ǰ�������Ƶ���ϰ��
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