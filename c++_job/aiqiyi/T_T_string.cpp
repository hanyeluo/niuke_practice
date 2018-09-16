#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

#define N 1000

int c[N][N];
int flag[N][N];

int getLCSlength(const std::string s1, const std::string s2)
{
    int i;
    int len1 = s1.size();;
    int len2 = s2.size();
    for(i=1;i<=len1;i++)
        c[i][0] = 0;
    for(i=0;i<=len2;i++)
        c[0][i] = 0;
    int j;
    for(i=1;i<=len1;i++)
        for(j=1;j<=len2;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                c[i][j] = c[i-1][j-1] +1;
                flag[i][j] = 0;
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                flag[i][j] = 1;
            }
            else
            {
                c[i][j] = c[i][j-1];
                flag[i][j] = -1;
            }
        }
        return c[len1][len2];
}
string getLCS(const std::string s1, const std::string s2,int len, std::string &lcs)
{
    int i = s1.size();
    int j = s2.size();;
    while(i&&j)
    {
        if(flag[i][j]==0)
        {
            lcs = s1[i-1] + lcs;
            i--;
            j--;
        }
        else if(flag[i][j]==1)
            i--;
        else
            j--;
    }
    return lcs;
}

int main(int argc, const char *argv[])
{
    string s;
    cin >> s;
    int size_s = s.size();
    int size_half = size_s/2+1;
    int begin = 1;
    int _max = 0;
    while(begin < size_s)
    {
        string s1 = s.substr(0,begin);
        string s2 = s.substr(begin,size_s-begin+1);
        int len = getLCSlength(s1,s2);
        _max = max(len,_max);
        begin++;
    }
    cout << _max*2 << endl;
    return 0;
}
