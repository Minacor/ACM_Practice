/*
 * 题意：
 * 第一行两个数：演员人数n和小明喜欢的人数m
 * 第二行m个人的编号，演员人数是从1~n编号的
 * 之后每三行一个电影信息
 * 第一行电影名
 * 第二行有几个演员参加了这场电影
 * 第三行这些演员的编号，0表示小明忘了他的编号
 *
 * 对于每一个电影，输出：
 * 0，表示这一定是小明最喜欢的电影 1，表示这一定不是小明最喜欢的电影 2，有可能是有可能不是
 * 最喜欢的电影定义：没有其他电影包含的最喜欢演员数量超过这部电影
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
#define MID(x,y) ((x+y)>>1)
#define FR (freopen("in.txt","r",stdin))
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
using namespace std;
typedef long long LL;
const int MAX = 200000+100;
const int inf = 522133279;
const int mod = 1000000007;

int n,m;
bool fav[110];

struct movie
{
    string name;
    int star;
    bool has[110];
    int surehas;
    int maxhas;
}mov[110];

int main()
{
    freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
    cin >>n >> m;
    for(int i = 0 ; i < m ; i++)
    {
        int a;
        cin >> a;
        fav[a]=1;
    }
    int num;
    cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        cin >> mov[i].name >> mov[i].star;
        int zuiai=0,zero=0,buai=0;
        for(int j = 0 ; j < mov[i].star ;j++)
        {
            int a;
            cin >> a;
            if(fav[a])
                zuiai++;       //当前电影已有的最爱演员数
            else if(!a)
                zero++;         //0的个数
            else
                buai++;         //当前电影已有的不喜欢的演员数
        }

        //最大可能有的最喜欢演员 = 当前已有的最爱的演员数+能够从没选的最爱演员中替换0的最大人数
        mov[i].maxhas = zuiai + (zero > (m-zuiai)?(m-zuiai):zero);
        //至少拥有数=当前已有的最爱演员数+(zero-最多能够替换掉0的未选的不喜欢的演员人数)
        // n-m-buai就是剩余未选的不喜欢的演员数量，如果把它们全替换掉0，那么剩余的0必须是最爱的演员
        mov[i].surehas = zuiai+((zero-(n-m-buai)) >= 0 ? (zero-(n-m-buai)) : 0);
    }

    for(int i = 0 ; i < num ; i++)
    {
        int ok=0;
        for(int j = 0 ; j < num ; j++)
        {
            if(i==j) continue;
            //如果出现确定数和最大数都小于某一电影的确定数，则一定不会是最喜欢的了
            if(mov[i].surehas < mov[j].surehas && mov[i].maxhas < mov[j].surehas)
            {
                ok=1;
                break;
            }
            //不然，如果确定数小于某一电影的最大数，则其是有可能被超越的，所以是2
            if(mov[i].surehas < mov[j].maxhas)
                ok=2;
        }
        if(mov[i].surehas == m)
            ok=0;
        cout << ok << endl;
    }
    return 0;
}

