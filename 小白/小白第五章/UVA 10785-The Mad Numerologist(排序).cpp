/*
 * 题意：元音字母AUEOI和辅音字母JSBKTCLDMVNWFXGPYHQZR有各自对应的值，
 * 一个长为n的串的权值是所有字母值的总和，这个串是这样安排的：首位为1，奇数位放元音字母，偶数位放辅音字母
 * 同一个元音字母不能超过21个，同一个辅音字母不能超过5个
 *
 * 现在给定n，要求构造出这样的串，使得在总权值最小的情况下字典序最小
 *
 * 思路：第一步，选字母，我们需要多少元音，辅音字母，都选出来，权值小的优先被选择
 * 第二部，排字母，在奇偶位规则下优先安排字典序最小的字母
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
