#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
    string s;
    string t;
    cin >> s >> t;
    int i = 0;
    for (auto iter = s.begin(); iter != s.end(); ++iter) 
    {
        if(i >= t.size())
            break;
        if(*iter == t[i])
        {
            i++;
        }
        else
            continue;
    }

    if(i==t.size())
        printf("%s","Yes");
    else
        printf("%s","No");
    return 0;
}
