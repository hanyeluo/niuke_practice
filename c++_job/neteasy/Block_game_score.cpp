#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp_time(pair<int,int> &a ,pair<int,int> &b)
{
    return a.second < b.second;
}

int main(int argc, const char *argv[])
{
    int n,m;
    cin >> n >> m;
    map<int,int> step_times;
    vector<pair<int,int> >step_times_vec;
    for(int i = 0 ; i < m ; i++)
    {
        int step;
        cin >> step;
        if (step_times.find(step) != step_times.end()) 
        { 
            step_times[step]+=1;
        } 
        else
        {
            step_times[step]=1;
        }
    }
    for(auto itor = step_times.begin() ; itor != step_times.end() ; itor++)
    {
        step_times_vec.push_back(pair<int,int>(itor->first,itor->second));
    }

    sort(step_times_vec.begin(),step_times_vec.end(),cmp_time);

    if(n == step_times_vec.size())
        cout << step_times_vec[0].second;
    else
        cout << 0;

    return 0;
}
