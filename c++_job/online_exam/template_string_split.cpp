#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>

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
    cin >> n;
    vector<vector<int> > info_num;
    for(int i = 0 ; i < n ; i++)
    {
        string str_vec;
        cin >> str_vec;
        int type = 0;
        vector<int> numbers = split(str_vec,",",type);
        info_num.push_back(numbers);
    }

    for (auto iter = info_num.begin(); iter != info_num.end(); ++iter) 
    {
        for(int j = 0 ; j < (*iter).size() ; j++)
        {
            printf("%d\t",(*iter)[j]);
        }
        cout << endl;
    } 

    return 0;
}
