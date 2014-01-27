/*
 * ���⣺
 * ���룺
 * ��һ������������n����ɫ���·� ��m��
 * �ڶ���n����ɫ������
 * ������m�У�ÿ��������
 * ϴ����·���ʱ��time ����·�����ɫname
 *
 * �������������ٶ���ͬ����ϴ�·������Ǳ���һ����ɫһ����ɫϴ��ϴ�����ϴ��һ����ɫ
 * ������ʱ��
 *
 * ˼·��
 * �������big event in hdu��ǿ����
 * ���ڲ�ͬ��ɫ���ܽ��棬����ϴ��ͬ��ɫ���·����¼��Ƕ����ģ��������ϴĳ����ɫ�·�������ʱ��Ȼ�����
 * ����ÿ����ɫ��������ϴ��ʱ��һ��Խ�ӽ�Խ�ã���һ���ͺ���һ��һ���ˣ�
 * ����ʱ���һ����Ϊ������������һ���˵�ʱ�価�������������������һ���˵�ʱ�������������ʱ����
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
using namespace std;
typedef long long LL;
const int MAX = 1000;
const int inf = 522133279;

map < string , vector<int> > lis;
int dp[100000+100];

int main()
{
    //FR;
    int n,m;
    while(cin >> n >> m && (n||m))
    {
        lis.clear();
        cin.ignore();

        string name;
        int time;
        getline(cin,name);

        for(int i = 0 ; i < m ; i++)
        {
            cin >> time >> name;
            cin.ignore();
            lis[name].push_back(time);
        }

        int ans=0;
        map< string , vector<int> > :: iterator it = lis.begin();
        for( ; it != lis.end() ; it++)
        {
            vector<int> tmp(it->second);
            int sum=0;
            for(int i = 0 ; i < tmp.size() ; i++)
                sum += tmp[i];

            memset(dp,0,sizeof dp);

            for(int i = 0 ; i < tmp.size() ; i++)
                for(int j = sum/2 ; j >= tmp[i] ; j--)
                    dp[j] = max(dp[j],dp[j-tmp[i]]+tmp[i]);
            ans += sum - dp[sum/2];
        }

        cout << ans << endl;
    }

    return 0;
}
