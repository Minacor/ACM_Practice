/*
 * ���ͣ�����
 *
 * ���⣺��һ������һ�����Ӳ��Ǻ�(B)���ǰ�(W)����������ѡ��һ�У��Ѻڱ�װױ��
 * �ʽ������ɲ������ܵõ��İ�ɫ�����ε�������
 *
 * ˼·�����������ɴ�߳����Ǿ��εĿ�(�̱�)����ô�Ӷ̱߳��ȿ�ʼ��ö�ٳ��ȣ������������Ϊ�߳��İ������ξ�ֹͣѰ��
 * �������εķ�����ֻҪ�ҵ������ַ���ͬ�����оͿ�����Ϊ���ܱ߳������жϣ���Ϊ�������ܰ����Ǳ�������İ�ɫ
 */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class AlienAndGame {
public:
    bool judge(int , int , int);
    int sum[55][55], num[55][55];
	int getNumber(vector <string>);
};

int AlienAndGame::getNumber(vector <string> board)
{
    int c = board[0].length(), r = board.size();
    int small = min(c, r);
    for(int i = 0; i != board.size(); i ++)
    {
        for(int j = 0; j != board[i].length(); j ++)
        {
            if(board[i][j] == 'W')
                num[i+1][j+1] = 1;
            else
                num[i+1][j+1] = 0;
        }
    }

    for(int i = 1; i <= r; i ++)
    {
        for(int j = 1; j <= c; j ++)
        {
            sum[i][j] += sum[i][j-1] + num[i][j];
        }
    }
    int ans = 1;
    for(int x = small; x > 1; x --)
    {
        for(int i = 1; i + x - 1 <= r; i ++)
        {

            for(int j = 1; j + x - 1 <= c; j ++)
            {
                if(!judge(i, j, x))
                    continue;
                else
                {
                    ans = x;
                    break;
                }

            }
            if(ans != 1)
                break;
        }
        if(ans != 1)
            break;
    }
    return ans * ans;
}

bool AlienAndGame::judge(int r, int c, int k)
{
    bool ok = true;
    for(int i = 0; i < k; i ++)
    {
        if(sum[r+i][c+k-1] - sum[r+i][c-1] != 0 && sum[r+i][c+k-1] - sum[r+i][c-1] != k) //Ҫ��������0��Ҫ��������1
        {
            ok = false;
            break;
        }
    }

    return ok;
}
