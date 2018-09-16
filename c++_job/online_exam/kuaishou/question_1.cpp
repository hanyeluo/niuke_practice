#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>

using namespace std;

void tran(int &number , string &str)
{
    stringstream stream;
    stream << number;
    str = stream.str();
}

int main(int argc, const char *argv[])
{
    string s;
    map<char,int> result;
    getline(cin,s);
    for (auto iter = s.begin(); iter != s.end(); ++iter) 
    {
        char a = *iter;
        if(result.find(a) != result.end())
        {
            result[a] +=1;
        }
        else
        {
            result[a] = 1;
        }
    }
    for (auto iter_ = result.begin(); iter_ != result.end(); ++iter_) 
    {
        char first_ = iter_->first;
        int number = iter_->second;
        string second_;
        tran(number,second_);
        cout << first_+second_;
    }
    cout << endl;
    return 0;
}
