/*
 * ���⣺Ԫ����ĸAUEOI�͸�����ĸJSBKTCLDMVNWFXGPYHQZR�и��Զ�Ӧ��ֵ��
 * һ����Ϊn�Ĵ���Ȩֵ��������ĸֵ���ܺͣ���������������ŵģ���λΪ1������λ��Ԫ����ĸ��ż��λ�Ÿ�����ĸ
 * ͬһ��Ԫ����ĸ���ܳ���21����ͬһ��������ĸ���ܳ���5��
 *
 * ���ڸ���n��Ҫ����������Ĵ���ʹ������Ȩֵ��С��������ֵ�����С
 *
 * ˼·����һ����ѡ��ĸ��������Ҫ����Ԫ����������ĸ����ѡ������ȨֵС�����ȱ�ѡ��
 * �ڶ���������ĸ������żλ���������Ȱ����ֵ�����С����ĸ
 */

#include "iostream"
#include "cstring"
#include "algorithm"
#include "cmath"
#include "cstdio"
#include "sstream"
#include "queue"
#include "vector"
#include "string"
#include "stack"
#include "cstdlib"
#include "deque"
#include "fstream"
#include "map"
#include "set"
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;

int ju(char a)
{
    if(a == 'A' || a == 'E' || a ==  'I' || a ==  'O' || a == 'U')
        return 1;
    return 0;
}

char mir1[] = "AUEOI";
char mir2[] = "JSBKTCLDMVNWFXGPYHQZR";
int cnt[500];

int main()
{
    int t;
    cin >> t;

    for(int ka = 1 ; ka <= t ; ka++)
    {
        int n;
        cin >> n ;
        memset(cnt,0,sizeof(cnt));

        printf("Case %d: ",ka);

        int pos1=0,pos2=0;
        for(int i = 1 ; i <= n ; i++)
        {
            if(i%2)
            {
                if(cnt[mir1[pos1]] == 21) pos1++;
                cnt[mir1[pos1]]++;
            }

            else
            {
                if(cnt[mir2[pos2]] == 5) pos2++;
                cnt[mir2[pos2]]++;
            }

        }

        for(int i = 1 ; i <= n ; i++)
        {
            if(i%2)
            {
                for(int i = 'A' ; i <= 'Z' ; i++)
                    if(ju(i) && cnt[i])
                    {
                        cnt[i]--;
                        printf("%c" , i);
                        break;
                    }
            }
            else
            {
                for(int i = 'A' ; i <= 'Z' ; i++)
                    if(!ju(i) && cnt[i])
                    {
                        cnt[i]--;
                        printf("%c" , i);
                        break;
                    }
            }
        }

        puts("");
    }

    return 0;
}
