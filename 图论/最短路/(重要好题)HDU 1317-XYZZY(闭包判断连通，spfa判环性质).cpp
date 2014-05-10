/*******************************************************

    题意：
    数据：
    第一个数n代表有多少房间
    接下来n行，
    每行第一个数vv表示进这个房间得到的权值，-100~100
    第二个数num表示这个房间能够通向num个房间
    然后num个数是能够通向的房间的标号，单向通行
    第一个房间和第n个房间的权值恒为0

    现在主人公有100的初始权值，现在他要从1开始通向n
    每走入一个房间就必须将这个房间的权值加到自己的权值上
    如果自己的权值在到达终点前 <=0 了，就挂了
    房间可以无数次进出
    问主人公能否到达终点n

    思路：
    这题显然就是判环了，用spfa做最长路，并判断正权环，因为
    一旦出现正权环，那么权值就可以无限累加，
    如果这个环中的某点能够到达终点，那么就一定能赢

    特别注意：
    用cnt数组判环的话，能够找出所有的环，具体是：
    所有环中必定有一点是满足跳出条件的,比如cnt[i] >= n
    判断一点能否到达终点，利用传递闭包的性质就可以了

********************************************************/

//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include "iostream"
#include "cstring"
#include "algorithm"
#include "cmath"
#include "cstdio"
#include "sstream"
#include "queue"
#include "vector"
#include "list"
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
#define PI acos(-1.0)
#define mkp make_pair
using namespace std;
typedef long long LL;
const int MAXN = 100000+100;
const int inf = 522133279;
const int mod = 1000000007;

int g[110][110],mg[110][110];
int low[110];
int cnt[110];
int vis[110];
int vv[110];
int n;

void spfa()
{
    for(int i =0 ; i <= n ; i++)
        low[i]=-inf;
    clr(vis,0);
    vis[1]=1;
    cnt[1]++;
    low[1]=100;

    queue<int> que;
    que.push(1);

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        vis[cur]=0;
        if(cnt[cur] >= n)
            break;

        for(int i = 1 ; i <= n ; i++)
        {
            if(g[cur][i])
            {
                if(low[i] <= low[cur]+vv[i] && low[cur]+vv[i] > 0)      //low[cur]+vv[i] > 0这个条件必须得加，已经<=0了就不能再走下去了
                {
                    low[i] = low[cur]+vv[i];

                    if(!vis[i])
                    {
                        vis[i] = 1;
                        que.push(i);
                        cnt[i]++;
                    }
                }
            }
        }
    }

    if(low[n] > 0)      //如果能够直接到达终点
    {
        printf("winnable\n");
        return ;
    }
    else                //否则，判断是否有正环，有的话，只要环中某一点能够到达终点就一定能赢
    {
        for(int i = 1 ; i <= n ; i++)
            if(cnt[i] >= n && mg[i][n])
            {
                printf("winnable\n");
                return ;
            }
    }
    printf("hopeless\n");
}

int main()
{

    while(~scanf("%d",&n) && n!=-1)
    {
        clr(g,0);
        clr(cnt,0);
        clr(mg,0);
        for(int i = 1 ; i <= n ; i++)
        {
            int num;
            scanf("%d%d",&vv[i],&num);

            for(int j = 0 ; j < num ; j++)
            {
                int tmp;
                scanf("%d",&tmp);
                mg[i][tmp]=g[i][tmp] = 1;
            }
        }

        for(int k = 1 ; k <= n ; k++)
            for(int i = 1 ; i <= n ; i++)
                for(int j = 1 ; j<= n ; j++)
                    if(mg[i][k]+mg[k][j]==2)
                        mg[i][j]=1;
        spfa();
    }
    return 0;
}

/*

    9
    0 2 2 5
    100 1 3
    100 1 4
    100 1 2
    1 1 6
    1 2 7 8
    1 1 5
    -100 1 9
    0 0

*/
