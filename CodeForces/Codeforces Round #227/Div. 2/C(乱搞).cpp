/*
 * ���⣺
 * ��һ�������������ɸ�������������һ�ֲ���
 * 1, ѡ��������a[i],a[j],��a[i]>=a[j]
 * 2, ��������ӵ�С����ǰ�棬���һ����������������뵽����ĩβ
 * 3, ɾ��a[i],a[j],���±��
 * ���ڸ�һ��������ԭ����������м�������ʹ��������ƴ�������
 *
 * ˼·��
 * ��������Ӻ���ǰ�������ӵ�ǰλ��i��δ�жϵ������г�����0~i��i~size�������ܲ�������ϲ�Ҫ��
 * �ܵĻ��ͼ�1
 * ֱ�Ӻ����ݹ�ᱬ�ڴ棬���Բ��õ���
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
const int MAX = 100000+100;
const int inf = 522133279;

int cmp(string a , string b)   //�ж���a�Ƿ�>=��b
{
    if(a.size() > b.size())
        return 1;
    if(a.size() == b.size() && a >= b)
        return 1;
    return 0;
}

int dfs(string cur)
{
    int cnt=0,lastpos=cur.size();
    for(int i = cur.size()-1 ; i >= 0 ; i--)
    {
        if(cur[i] == '0') continue; //��Ŀ��֤û��ǰ���㣬���Կ��Է�������
        
        //�з�δ���������
        string s1 = cur.substr(0,i); //��һ��
        string s2 = cur.substr(i,lastpos-i); //�ڶ��ε�ĩ�����Ѵ��������ǰһ��λ�ã�֮��Ķ����Ѿ��ϲ����Ҽǹ���������

        if(cmp(s1,s2))
        {
            cnt++;
            lastpos = i;
        }
    }
    return cnt;
}

int main()
{
    //FR;
    string line;
    cin >> line;
    cout << dfs(line)+1 << endl;
    return 0;
}
