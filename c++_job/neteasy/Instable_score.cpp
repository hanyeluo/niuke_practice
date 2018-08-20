#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

bool cmp_high(pair<int,long> &a , pair<int,long> &b)
{
    return a.second >= b.second;
}

int main(int argc, const char *argv[])
{
    int n,k;
    cin >> n >> k;
    vector<pair<int,long> > Pagoda_info;
    vector<pair<int,int> > result;
    for(int i = 1 ; i <= n ; i++)
    {
        int high;
        cin >> high;
        Pagoda_info.push_back(pair<int,long>(i,high));
    }
    
    sort(Pagoda_info.begin(),Pagoda_info.end(),cmp_high);

    long no_count = Pagoda_info[0].second-Pagoda_info[n-1].second;
    int times = 0;

    while( no_count > 0 && times < k)
    {
        sort(Pagoda_info.begin(),Pagoda_info.end(),cmp_high);
        if(Pagoda_info[n-2].second==Pagoda_info[n-1].second && Pagoda_info[n-2].first < Pagoda_info[n-1].first)
        {
            swap(Pagoda_info[n-1],Pagoda_info[n-2]);
        }
        Pagoda_info[0].second-=1;
        Pagoda_info[n-1].second+=1;
        result.push_back(pair<int,int>(Pagoda_info[0].first,Pagoda_info[n-1].first));
        no_count=Pagoda_info[0].second-Pagoda_info[n-1].second;
        times++;
    }
    
    cout << no_count << " " << times << endl;
    for(auto itor = result.begin() ; itor != result.end() ; itor++)
    {
        cout << itor->first << " " << itor->second << endl;
    }

    return 0;
}
