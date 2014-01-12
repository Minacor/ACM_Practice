/*
 *排序后搜索指定的数
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

int arr[10010];

int main()
{
    int a,b;
    int cnt=0;

    while(~scanf("%d%d",&a,&b) && (a||b))
    {
        for(int i = 0 ; i < a ; i++)
            scanf("%d",arr+i);

        sort(arr,arr+a);

        printf("CASE# %d:\n" , ++cnt);

        for(int j = 0 ; j < b ; j++)
        {
            int tmp;
            scanf("%d",&tmp);

            int i;
            for(i = 0 ; i < a ; i++)
                if(tmp == arr[i])
                {
                    printf("%d found at %d\n",tmp,i+1);
                    break;
                }
            if(i == a)
                printf("%d not found\n", tmp);
        }
    }


    return 0;
}


