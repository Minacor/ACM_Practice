/*
 * ���⣺
 * �����ſΣ�ÿ�У��ε����� �˿���ҵ�Ľ�ֹ���� ������ҵ��Ҫ��ʱ��
 * ���������ֹ���ޣ�ÿ����һ���һ��
 * ��ʹ�ÿ۵ķ������ٵ�����ҵ��˳��
 *
 * �ε�����������15��״̬ѹ��dp
 * ת�Ʒ�����ǰһ״̬��ѡ���˵�ǰ�γ���ҵ����̬������״̬��һ������������ʾ��0��ʾû���꣬1��ʾ������
 * ϸ�ڼ�����
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
const int MAX = (1<<15)+100;
const int inf = 522133279;

int n,t;
struct n1
{
    string name;        //�γ�����
    int deadline;       //���ſγ���ҵ�Ľ�ֹ����
    int spend;          //�������ſγ���ҵ����ʱ��
}c[20];

struct n2
{
    int score;          //��ǰ״̬�۵��ķ���
    int prevState;      //��ʾǰһ״̬��ʮ������
    int curpos;         //��ǰѡ�����±�Ϊcurpos�����ſΣ�ע���±��0��ʼ
    int totspend;       //���굱ǰ״̬������ɵ���ҵ����ʱ��
}dp[MAX];

int main()
{
    FR;
    cin >> t;

    while(t--)
    {
        cin >> n;
        for(int i = 0 ; i < n ; i++)
            cin >> c[i].name >> c[i].deadline >> c[i].spend;
        clr(dp,0);

        int totState = 1 << n;      //��״̬��

        for(int i = 1 ; i < totState ; i++)
        {
            dp[i].score = inf;
            //�ر�ע�������ĿҪ��������ķ�����ͬ���Ͱ��ֵ���С�����
            //Ȼ��������Сֵ�����ж���'<'����'<='��������Ҫ����
            for(int k = n-1 ; k >= 0 ; k--)     //ö��ÿһ�ſ�
            {
                int curclass = 1 << k;

                if(i&curclass)          //������ſ��ڵ�ǰ״̬���ѱ�ѡ��
                {
                    int prevState = i-curclass; //ǰһ״̬��û��ѡ�����ſε�״̬
                    int spend = dp[prevState].totspend + c[k].spend;    //�������ſκ�Ļ���ʱ��
                    int jianfen=0;
                    if(spend > c[k].deadline)       //������ֹʱ��͵ü�����
                        jianfen = spend-c[k].deadline;
                    if(dp[prevState].score+jianfen < dp[i].score)       //�����ǰ״̬ʹ�ü��ָ��پ͸���
                    {
                        dp[i].score = dp[prevState].score+jianfen;
                        dp[i].totspend = dp[prevState].totspend+c[k].spend;
                        dp[i].curpos = k;               //ѡ��ʹ�ü��ָ��ٵĿγ�
                        dp[i].prevState = prevState;    //����ǰһ״̬
                    }
                }
            }
        }

        //����·��
        cout << dp[totState-1].score << endl;
        stack<string> out;
        int prev = totState-1;
        do
        {
            int cur = dp[prev].curpos;
            out.push(c[cur].name);
            prev = dp[prev].prevState;
        }while(prev);

        while(!out.empty())
        {
            cout << out.top() << endl;
            out.pop();
        }
    }

    return 0;
}
