/*
 * ���⣺
 * ��һ���ַ���sƬ�κ�k�����ַ���out����k��sƴ�Ӷ��ɵ�
 * ��n������p c��ɾ��out�е�p��c�ַ���ɾ�������±��
 * ������ĺ���ַ���
 *
 * ˼·��
 * ֱ�ӱ����϶����У���λ��������Ҫ
 * �տ�ʼ��¼��s�и����ַ��ĸ�����Ȼ��ͨ����������λ�����������в�ͨ����Ϊɾ��������±�ţ�ÿ��ѭ�����Ѿ���ͬ��
 * ���Ը���vector<int> [char]����¼char���ֵ�λ��
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

string out,s;
int k,n;
vector<int> pos[500];

int main()
{
    cin >> k >> s >> n;

    for(int i = 0 ; i < k ; i++)
        out+=s;
    for(int i = 0 ; i < out.size() ; i++)
        pos[out[i]].push_back(i);

    while(n--)
    {
        int p;char c;
        cin >> p >> c;
        out[*(pos[c].begin()+p-1)] = 'A';
        pos[c].erase(pos[c].begin() + p-1);
    }

    for(int i = 0 ; i < out.size() ; i++)
        if(out[i] != 'A') cout << out[i];

    return 0;
}
