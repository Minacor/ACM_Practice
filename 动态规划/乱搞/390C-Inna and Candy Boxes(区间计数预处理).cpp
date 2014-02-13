/*
 * 题意：
 * 给一个01串，0表示有糖果1表示没有，给w组询问和一个k值
 * 定义positive：对每一组询问l，r，仅当l-1+k,l-1+2k,...,r位置是1而其他位置是0时称为positive
 * 定义"一次操作"：从任意一个箱子里拿出糖或者放进糖
 * 对每一次询问，输出使这个区间positive的最少操作数
 *
 * 思路：
 * 首先注意上一次的询问不会影响下一次！！也就是说问完一次，糖就全部还原了
 * 由于k不大，于是对k个起点(0~k)预处理
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
const int MAXN = 100000+10;
const int inf = 522133279;
const int mod = 1000000007;

int dp[15][100000+100];
int cha[100000+100];

int main()
{
    int n,k,w;
    string line;

    cin >> n >> k >> w;
    cin >> line;

    for(int i = 0 ; i < k ; i++)    //i表示从i+1位置开始安排
    {
        for(int j = i+1 ; j <= n ; j++)     //注意开始位置的安排，每个区间起头位置是要算0的
        {
            dp[i][j] = dp[i][j-1];
            if((j-i)%k && line[j-1]=='1') dp[i][j]++;
            if((j-i)%k==0 && line[j-1]=='0') dp[i][j]++;
        }
    }

    for(int i = 0 ; i < w ; i++)
    {
        int l,r;
        cin >> l >>r;
        int st = (l-1)%k;
        cout << dp[st][r]-dp[st][l-1] << endl;
    }
    return 0;
}
