/*
 *��Ŀ���ѣ���ð������Ĵ�����������γ��ģ��
 
 *ģ�ͣ���һ���ſ���������������ˮƽת180�ȣ�����ѻ𳵿����������ϣ��������������ڳ��ᣬȻ��
 *      ����ת��180��֮�󣬾��൱�������ڳ��������λ�ã���������Ҫ�������ڳ�����ٴ�ʹ�ó�����������
 
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
