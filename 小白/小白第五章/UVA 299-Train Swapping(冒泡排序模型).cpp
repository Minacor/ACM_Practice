/*
 *题目不难，是冒泡排序的次数，重在如何抽出模型
 
 *模型：有一座桥可以绕它的中心轴水平转180度，如果把火车开到这座桥上，最多可以容纳两节车厢，然后
 *      让桥转过180度之后，就相当于这两节车厢调换了位置，问最少需要调换相邻车厢多少次使得车厢升序排列
 
 */

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
#include <cctype>
using namespace std;
typedef long long LL;

int arr[100];

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n;
        scanf("%d",&n);

        for(int i = 0 ; i < n ; i++)
            scanf("%d",arr+i);

        int cnt=0;
        for(int i = 0 ; i < n ; i++)
            for(int j = 1  ; j < n ; j++)
            {
                if(arr[j-1] > arr[j])
                {
                    int tmp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = tmp;
                    cnt++;
                }
            }
        cout << "Optimal train swapping takes " << cnt << " swaps." << endl;
    }

    return 0;
}
