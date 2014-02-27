/*
 * 题意：给三个数n，m，k，给一个n*m的矩阵，每一行代表一个序列。
 * 现在给定操作(i,j) ， 选定两列i，j，对于这两列中每个序列中的两个元素，如果这两个数满足xulie[i]>xulie[j]，就交换这两个数
 * 要求若干次操作后，所有序列按升序或降序排列(由k决定，k=0升序，=1降序)
 * 如果某操作交换了数字，就输出这个操作
 *
 * 思路：m最多100，直接暴枚：用两个循环枚举所有列对，对于每个列对再枚举每一个数对(n对)，能交换的就交换
 * 交换过的不可能再交换，因为若干涉及到他们中的其中一个元素的交换都会使差值拉大
 *
 * 本题特别注意的是对一个数对，前者大于后者才能交换，所以如果降序的话，输出的点对要反一下
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
const int INF = 0xfffffff;

struct node
{
    int x;
    int y;
};

int n,m,order;
int lis[1010][110];
vector<node> out;

int main()
{
    cin >> n >> m >> order;

    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
        {
            cin >> lis[i][j];
        }

    int ok=0;
    for(int i = 1 ; i <= m ; i++)
        for(int j = i+1 ; j <= m ;j++)
        {
            ok=0;
            for(int k = 1 ; k <= n ; k++)
            {
                if(!order && lis[k][i] > lis[k][j])
                {
                    ok=1;
                    swap(lis[k][i],lis[k][j]);
                }
                else if(order && lis[k][i] < lis[k][j])
                {
                    ok=1;
                    swap(lis[k][i],lis[k][j]);
                }
            }

            if(ok)
            {
                node tmp;
                if(!order)
                    tmp.x=i,tmp.y=j;
                else if(order)          //降序输出要反一下
                    tmp.y=i,tmp.x=j;
                out.push_back(tmp);
            }
        }

    cout << out.size() << endl;
    for(int i = 0 ; i < out.size() ; i++)
        printf("%d %d\n",out[i].x,out[i].y);

    return 0;
}
