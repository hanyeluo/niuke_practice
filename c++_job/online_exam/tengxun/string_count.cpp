#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

 int how_many(std::string& strSource, const std::string& strOld)
 {
    int nPos = 0;
    int find_count = 0;
    while ((nPos = strSource.find(strOld, nPos)) != strSource.npos)
    {
         //strSource.replace(nPos, strOld.length(), strNew);
         //nPos += strOld.length();
         nPos++;
         find_count++;
    }
    return find_count;
 }

int main(int argc, const char *argv[])
{
    int k;
    string a_str;
    string b_str;
    scanf("%d",&k);
    cin >> a_str;
    cin >> b_str;
    int result = 0;//how_many(b_str,a_str);
    set<string> str_a_info;
    for(int i = 0 ; i <= a_str.size()-k ; i++)
    {
        string new_small = a_str.substr(i,k);
        if( str_a_info.find(new_small) == str_a_info.end())
        {
            str_a_info.insert(new_small);
            result += how_many(b_str,new_small);  
        }
    }

    cout << result << endl;
    return 0;
}
