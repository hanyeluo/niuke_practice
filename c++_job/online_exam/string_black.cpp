#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    string str;
    vector<string> str_vec;
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 0 ; i < n ; i++)
    {
        getline(cin,str);
        str_vec.push_back(str);
    }

    for (auto iter = str_vec.begin(); iter != str_vec.end() ; iter++)
            cout << *iter << endl;
    return 0;
}
