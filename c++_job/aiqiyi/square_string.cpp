#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

bool cmp_value(pair<string,int> &a , pair<string,int> &b)
{
    return a.second > b.second;
}

int main(int argc, const char *argv[])
{
    string s;
    cin >> s;
    int s_len = s.size();
    vector<pair<string,int> > s_info;
    
    if (s_len == 1)
    {
        cout << 1;
        return 0;
    }
    if (s_len==0)
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
        bool isEqual(pair<string,int> &element)
        {
            return element.first == fragment;
        }
        auto findit = find_if(fragments.begin(),fragments.end(),isEqual);
        if (findit == fragments.end())
        {
            fragments.push_back(pair<string,int>(fragment,1));
            //length_all += destent;
        }
        else
        {
            int index = iterator_to_index(fragments,findit);
            fragments[index].second++;
        }
        begin_index = end_index;
        end_index++;
        count++;
    }


    

    return 0;
}
