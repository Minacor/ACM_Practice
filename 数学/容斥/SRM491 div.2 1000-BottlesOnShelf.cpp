/*
 * ���⣺
 * ��N��1���������Ϊ1~N��Ȼ����һȺѯ��
 * ÿһ��ѯ��(l,r,damage)����l~r�ڵı���ܱ�damage������1�ĳ�0
 * ������0������
 *
 * ˼·��
 * damageֵ���ݳ�
 * ���ɸ������damage����С������ֻ�ܼ���һ��
 */

#line 2 "BottlesOnShelf.cpp"
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
const int inf = 1000000000;
typedef long long LL;

class BottlesOnShelf {
public:
    LL gcd(LL x , LL y)
    {
        if(y == 0)
            return x;
        return gcd(y,x%y);
    }

    LL lcm(LL x , LL y)
    {
        return x/gcd(x,y) * y;
    }

    LL getcnt(int l , int r , LL p)
    {
        return r/p-(l-1)/p;
    }

    int getNumBroken(int N, vector <int> left, vector <int> right, vector <int> damage)
    {
        int l,r;
        LL g;
        int n = left.size();
        int cnt;        //��Ǳ��β����Ǽ����Ǽ�
        int ans=0;

        for(int i = 1 ; i < (1 << n) ; i++)
        {
            l = -1,r = N+1,cnt = 0,g = 1;
            for(int k = 0 ; k < n ; k++)
            {
                if(i & (1 << k))
                {
                    cnt++;
                    //�󽻼�
                    l = max(l,left[k]);
                    r = min(r,right[k]);
                    g = lcm(g,damage[k]);
                }
            }

            if(l>r || g > N)
                continue;
            else
                ans += (cnt&1)? getcnt(l,r,g) : -getcnt(l,r,g); //�ݳ⹫ʽ����ż֮��+-����
        }

        return int(ans);
    }
}
