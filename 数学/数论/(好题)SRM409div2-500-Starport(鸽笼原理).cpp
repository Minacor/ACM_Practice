/*
 * 题意：
 * M：每M分钟开来一辆飞船
 * N：每N分钟开启一个传送点
 * 只有在传送点开启时才能传送一个飞船，在这期间飞船先到的话就得等一段时间
 * 求飞船等待的平均时间
 *
 * 思路：
 * 显然等待时间是周期性的，我们只需求出一个周期内的平均值
 * 而第n艘飞船的等待时间是N-(n*M)%N
 * 由鸽笼原理，当(M,N)==1时,(n*M)%N取遍且仅一次取遍[0,N-1]中的所有值
 * 当(M,N)!=1时同除两者的最大公约数就互质了
 * 所以若两者互质，则一个周期内的平均等待时间就是(0+1+...+N-1)/N = (N-1)/2
 * 不互质的话，乘上gcd就是答案了
 * 其实就是(n*M)%N取遍且仅一次取遍gcd(N,M)*[0,N-1]中的所有值
 */

#line 2 "Starport.cpp"
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

class Starport {
public:
    LL gcd(LL a , LL b)
    {
        if(b == 0)
            return a;
        return gcd(b,a%b);
    }

    double getExpectedTime(int N, int M) {
        LL g = gcd(N,M);
        return double((N/g-1)/2.0 *g);
    }
};
