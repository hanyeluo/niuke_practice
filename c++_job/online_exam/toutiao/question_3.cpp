#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
    int n;
    vector<string> result;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        int number;
        cin >> number;
        string s_0;
        string s_1;
        cin >> s_0;
        cin >> s_1;
        string::size_type position = s_0.find(s_1[0]);

    }
    return 0;
}
