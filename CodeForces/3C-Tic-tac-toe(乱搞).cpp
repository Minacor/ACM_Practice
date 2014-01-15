/*
 * ���⣺�жϵ�ǰ�����Ƿ�������Ƿ��ܹ��ߵ���һ������������ж��Ƿ��Ѿ�����Ӯ�ˣ�û�˵Ļ��ж���һ����˭�ߣ�����߲��˵Ļ���ƽ��
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

char g[5][5];
int cnt[2];
int mir[500];

bool win(char a)
{
    for(int i = 1 ; i <= 3 ; i++)
        for(int j = 0 ; j <= 3 ; j++)
        {
            if(g[i][j] != a)
                continue;

            if((g[i-1][j] == a && g[i+1][j] == a)
            ||(g[i][j-1] == a && g[i][j+1] == a)
            ||(g[i-1][j-1] == a && g[i+1][j+1] == a)
            ||(g[i-1][j+1] == a && g[i+1][j-1] == a))
                return 1;
        }

    return 0;
}

int check()
{
    if(!(cnt[0] == cnt[1] || cnt[0]-cnt[1] == 1))   //X���ߵģ���ô���ۺ�ʱ0�����ܱ�X�࣬Ҳ��������2�����ϣ������������������ǲ�����
        return 6;

    int winX=win('X');
    int win0 = win('0');

    if(winX&&win0 ||(winX && cnt[0]==cnt[1]) || (win0 && cnt[0]-cnt[1]==1)) //���˶�Ӯ������(��Ϊһ������Ӯ�ͽ�����)��һ����Ӯ����������ӵ�ȴ����Ӯ���Ǹ��ˣ�Ҳ������
        return 6;

    if(win0 && cnt[0] == cnt[1])        //Ӯ�����������ĳ��Ӯ����������ӵ����Ǹ���
        return 4;
    else if(winX && cnt[0] - cnt[1] == 1)
        return 3;

    for(int i = 1 ; i <= 3 ; i++)       //����������˾Ͳ�������һ���ˣ�ƽ�֣�����������������ж�˭��
        for(int j = 1 ; j <= 3 ; j++)
        {
            if(g[i][j] == '.')
            {
                if(cnt[0] == cnt[1])
                    return 1;
                else if(cnt[0]-cnt[1]==1)
                    return 2;
            }
        }

    return 0;
}

int main()
{
    int ok = 0;
    mir['X']=1,mir['0']=2;
    for(int i = 1 ; i <= 3 ; i++)
    {
        cin >> g[i]+1;

        for(int j = 1 ; j <= 3  ;j++)
        {
            if(g[i][j] == 'X')
                cnt[0]++;
            else if(g[i][j] == '0')
                cnt[1]++;
        }
    }

    ok = check();

    if(ok == 0)
        cout << "draw" << endl;
    else if(ok == 1)
        cout << "first" <<endl;
    else if(ok == 2)
        cout << "second" << endl;
    else if(ok == 3)
        cout << "the first player won" << endl;
    else if(ok == 4)
        cout << "the second player won" << endl;
    else
        cout << "illegal" << endl;

    return 0;

}
