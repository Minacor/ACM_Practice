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