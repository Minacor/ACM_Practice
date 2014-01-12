/*
 *阅读题，给定一组点，对于每一个点，求出其与另外几个点的距离的最小值，如果这个值小于10，就让0—9中对应的值+1
 *输出就是0—9这几个数字的被计次数
 */

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
typedef long long LL;

struct point
{
    double x;
    double y;
    double z;
}p[5010];

int dis(point a,point b)
{
    return (int)sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
}

int out[20];

int main()
{
    int cnt=0;

    while(~scanf("%lf%lf%lf",&p[cnt].x,&p[cnt].y,&p[cnt].z) && (p[cnt].x||p[cnt].y||p[cnt].z))
        cnt++;

    for(int i = 0 ; i < cnt ; i++)
    {
        int d=20;

        for(int j = 0 ; j < cnt ; j++)
            if(j != i)
                d = min(d,dis(p[i],p[j]));

        if(d < 10)
            out[d]++;
    }



    for(int i = 0 ; i < 10 ; i++)
    {
        printf("%4d",out[i]);
    }
    puts("");

    return 0;
}




