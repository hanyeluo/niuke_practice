#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main(int argc, const char *argv[])
{
    string s;
    cin >> s;
    map<string,int> fragments;
    int length_s = s.size();
    if (length_s == 1)
    {
        cout << 1;
        return 0;
    }
    if (length_s==0)
    {
        cout << 0;
        return 0;
    }

    int end_index = 1;
    int begin_index = 0;
    int length_all = 0;
    int count = 0;
    while( end_index <= length_s)
    {
        string fragment;
        if(s[end_index] == s[end_index-1])
        {
            end_index++;
            continue;
        }
        int destent = end_index-begin_index;
        fragment = s.substr(begin_index,destent);
        if (fragments.find(fragment) == fragments.end())
        {
            fragments[fragment] = destent;
            length_all += destent;
        }
        else
        {
            length_all += destent;
        }
        begin_index = end_index;
        end_index++;
        count++;
    }
    double avg_length = (double)length_all/(double)count;
    printf("%.2f",avg_length);
    return 0;
}
