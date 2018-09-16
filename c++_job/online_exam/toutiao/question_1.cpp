#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>

using namespace std;

void trans(string &str , int &number)
{
    stringstream stream(str);
    stream >> number;
}

void trans(string &str , float &number)
{
    stringstream stream(str);
    stream >> number;
}

template<typename T>
vector<T> split(const string &str,const string &pattern,T datatype)
{
    //const char* convert to char*
    char * strc = new char[strlen(str.c_str())+1];
    strcpy(strc, str.c_str());
    vector<T> resultVec;
    char* tmpStr = strtok(strc, pattern.c_str());
    while (tmpStr != NULL)
    {
        T number;
        string tmp_str = string(tmpStr);
        trans(tmp_str,number);
        resultVec.push_back(number);
        tmpStr = strtok(NULL, pattern.c_str());
    }

    delete[] strc;

    return resultVec;
}

int main(int argc, const char *argv[])
{
    int n;
    scanf("%d",&n);
    cin.ignore();
    map<int,vector<int> > info;
    for(int i = 1 ; i <= n ; i++)
    {
        string str_vec;
        getline(cin,str_vec);
        string pattern = " ";
        int type = 0;
        vector<int> numbers = split(str_vec,pattern,type);
        info[i]=numbers;
    }

    for (auto iter = info.begin(); iter != info.end(); ++iter) 
    {
        for(int j = 0 ; j < (iter->second).size() ; j++)
        {
            printf("%d\t",(iter->second)[j]);
        }
        cout << endl;
    } 

    return 0;
}
