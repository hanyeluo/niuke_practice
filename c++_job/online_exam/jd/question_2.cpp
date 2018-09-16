#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <map>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
void ReplaceAll(std::string& strSource, const char& strOld, const std::string& strNew)
{
    int nPos = 0;
    //string new_str = string(strNew);
    while ((nPos = strSource.find(strOld, nPos)) != strSource.npos)
    {
        strSource.replace(nPos,1, strNew);
        nPos += 1;//strNew.length();
    }
}

 int how_many(std::string& strSource, const std::string& strOld)
 {
    int nPos = 0;
    int find_count = 0;
    while ((nPos = strSource.find(strOld, nPos)) != strSource.npos)
    {
         //strSource.replace(nPos, strOld.length(), strNew);
         nPos += strOld.length();
         find_count++;
    }
    return find_count;
 }

int solve(string S, string T) 
{
    string pailie = "abcdefghigklmnopqrstuvwxyz";
    int index = 0;
    map<char,string> pailie_map;
    for (auto iter = T.begin(); iter != T.end(); ++iter) 
    {
        pailie_map[pailie[index++]]=*iter;
    }
    
    for(int i = 0 ; i < S.size() ; i++)
    {
        string::size_type position;
        position = pailie.find_first_of(S[i]);
        ReplaceAll(S,S[i],pailie_map[pailie[position]]);
    }
    
    return how_many(S,T);
}
/******************************结束写代码******************************/


int main() {
    int res;

    string _S;
    getline(cin, _S);
    string _T;
    getline(cin, _T);
    
    res = solve(_S, _T);
    cout << res << endl;
    
    return 0;
}
