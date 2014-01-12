
 统计每行第一个单词的个数，字典序输出
 

#include cstdio
#include cstring
#include cmath
#include cstdlib
#include iostream
#include vector
#include map
#include cctype
#include set
#include algorithm
#include string
#include sstream
using namespace std;
typedef long long LL;

mapstring , int lis;

int main()
{
    int t;
    cin  t;
    cin.ignore();

    while(t--)
    {
        string line;
        getline(cin,line);

        istringstream iss(line);
        string word;
        iss  word;

        lis[word]++;
    }

    mapstring , int  iterator it = lis.begin();

    while(it != lis.end())
    {
        cout  it-first  ' '  it-second  endl;
        it++;
    }

    return 0;
}




