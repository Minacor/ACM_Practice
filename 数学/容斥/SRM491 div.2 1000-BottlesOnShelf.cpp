/*
 * 题意：
 * 给N个1，编号依次为1~N，然后是一群询问
 * 每一次询问(l,r,damage)，把l~r内的编号能被damage整除的1改成0
 * 最后求出0的数量
 *
 * 思路：
 * damage值的容斥
 * 若干个区间的damage的最小公倍数只能计算一次
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
        int cnt;        //标记本次操作是减还是加
        int ans=0;

        for(int i = 1 ; i < (1 << n) ; i++)
        {
            l = -1,r = N+1,cnt = 0,g = 1;
            for(int k = 0 ; k < n ; k++)
            {
                if(i & (1 << k))
                {
                    cnt++;
                    //求交集
                    l = max(l,left[k]);
                    r = min(r,right[k]);
                    g = lcm(g,damage[k]);
                }
            }

            if(l>r || g > N)
                continue;
            else
                ans += (cnt&1)? getcnt(l,r,g) : -getcnt(l,r,g); //容斥公式，奇偶之间+-交替
        }

        return int(ans);
    }
}
