/*
 * ���⣺
 * �����ַ���
 * 1�����һ���ַ������������Σ�������Ҫɾ��������2�����£���wooooto -> wooto
 * 2��һ����������xx֮���ܸ��������������yy����������ɾ����wwttqqrr->wwtqqr
 * �����������ַ���
 *
 * ����pair�����¼ÿ�������ַ��ĳ��ִ���ʮ�ַ���
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
#define lson(x) (x<<1)
#define rson(x) (x<<1|1)
#define FR (freopen("in.txt","r",stdin))
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 200000+100;
const int inf = 522133279;
const int mod = 1000000007;

pair<char , int> cnt[200000+100];
int num;

int main()
{
    string line;
    cin >> line;

    for(int i = 0 ; i < line.size() ; i++)
    {
        if(!i)
            cnt[num++] = make_pair(line[i],1);
        else
        {
            char cur = line[i];
            if(cur == cnt[num-1].first) //�����ǰ�ַ���ǰһ���ַ�һ����Ҫ�����жϣ�����ֱ���½�һ��pair
            {
                cnt[num-1].second += (cnt[num-1].second < 2);//�����������2���Ͳ��ۼ�
                if(num>=2 && cnt[num-2].second == 2 && cnt[num-1].second==2)    //�����ǰ�ַ��������ˣ�����ǰһ���ַ�Ҳ��������������ǰ�ַ���Ҫɾ
                    cnt[num-1].second--;
            }
            else
                cnt[num++] = make_pair(line[i],1);

        }
    }

    for(int i = 0 ; i < num ; i++)
        while(cnt[i].second)
        {
            cnt[i].second--;
            cout << cnt[i].first;
        }

    return 0;
}
