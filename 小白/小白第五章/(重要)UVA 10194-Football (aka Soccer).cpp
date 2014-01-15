/*
 * 题意：一个队伍有如下属性：名字，总得分，赢的场次，平局场次，输的场次，比赛次数，进球数，失球数
 *
 * 现在给定了一个排序规则，优先级如下：
 * 1.总得分最高 2.赢的场次最多 3.进球数-失球数最大 4.进球数最多 5.比赛数最少 6.名字字典序(特别注意是大小写不敏感的！！WA了两次)
 *
 *最后以规定格式排序输出
 *
 *重点：
 *1.格式化输入的技巧sscanf(tmp.c_str() , "%[^#]#%d@%d#%[^\n]",name1,&a,&b,name2);
 *2.C++中忽略大小写的字符串大小比较strcasecmp
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
using namespace std;
typedef long long LL;
const int INF = 0xfffffff;

int t;
char tournament[150];

struct TEAM
{
    string name;
    int totPoint;
    int gamenum;
    int win;
    int tie;
    int loss;
    int goalscoed;
    int goalaga;

    TEAM()
    {
        totPoint=gamenum=win=tie=loss=goalscoed=goalaga=0;
    }

    void clear()
    {
        totPoint=gamenum=win=tie=loss=goalscoed=goalaga=0;
    }

    bool operator < (const TEAM& b)const
    {
        if(totPoint != b.totPoint) return totPoint > b.totPoint;
        if(win != b.win) return win >b.win;
        if(goalscoed-goalaga != b.goalscoed-b.goalaga) return goalscoed-goalaga > b.goalscoed-b.goalaga;
        if(goalscoed != b.goalscoed) return goalscoed > b.goalscoed;
        if(gamenum!=b.gamenum) return gamenum < b.gamenum;
        return strcasecmp(name.c_str(),b.name.c_str()) < 0;
    }

    void bisai(int a,int b)
    {
        if(a > b)
            win+=1,totPoint+=3;
        else if(a == b)
            tie+=1,totPoint+=1;
        else
            loss+=1;

        gamenum++;
        goalaga+=b;
        goalscoed+=a;
    }


}team[50];

map<string , int > suoyin;


int main()
{
    scanf("%d",&t);
    getchar();

    while(t--)
    {
        gets(tournament);

        suoyin.clear();

        int n;
        scanf("%d",&n);
        getchar();

        for(int i = 1 ; i <= n ; i++)
        {
            team[i].clear();
            getline(cin,team[i].name);
            suoyin[team[i].name]=i;
        }

        int g;
        scanf("%d",&g);
        getchar();

        char name1[50],name2[50];
        int a,b;
        for(int i = 0 ; i < g ; i++)
        {
            string tmp;
            getline(cin,tmp);

            sscanf(tmp.c_str() , "%[^#]#%d@%d#%[^\n]",name1,&a,&b,name2);

            team[suoyin[name1]].bisai(a,b);
            team[suoyin[name2]].bisai(b,a);
        }

        sort(team+1,team+n+1);

        cout << tournament << endl;
        for(int i = 1 ; i <= n ; i++)
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i,team[i].name.c_str(),team[i].totPoint,team[i].gamenum,team[i].win,team[i].tie,team[i].loss,team[i].goalscoed-team[i].goalaga,team[i].goalscoed,team[i].goalaga);

        if(t)
            cout << endl;
    }

    return 0;
}

