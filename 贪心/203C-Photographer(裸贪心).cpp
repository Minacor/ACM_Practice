/*
 * 题意：
 * 有两种照片，拍普通照花费a，高清照花费b，主人公一共有tot可供花费
 * 有n个顾客，每个顾客需要x张普通照和y张高清照
 * 问主人公最多能招待几个顾客
 *
 * 思路：
 * 很裸的贪心，当然是总花费a*x+b*y越小的越先招待咯，于是按这个排序再遍历就行了
 * 题目要求输出顾客编号，设置个id就行了
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

int n,tot;
int a,b;
vector<int> out;

struct node
{
    int x,y;
    int id;
    bool operator <(const node&mir)const
    {
        return a*x+b*y < a*mir.x + b*mir.y;
    }
}p[100000+100];

int main()
{
    cin >> n;
    cin >> tot;

    cin >> a >> b;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> p[i].x >> p[i].y;
        p[i].id = i+1;
    }
    sort(p,p+n);

    int pos=0;
    while(tot >= 0 && pos < n)
    {
        if(tot >= a*p[pos].x+b*p[pos].y)
        {
            tot -= a*p[pos].x+b*p[pos].y;
            out.push_back(p[pos].id);
        }
        else
            break;
        pos++;
    }
    cout << out.size() << endl;
    for(int i = 0 ; i < out.size() ; i++)
        cout << out[i] << ' ';
        cout << endl;
    return 0;
}
