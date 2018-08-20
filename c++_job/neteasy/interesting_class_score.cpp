#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp_scores(pair<int,int> &a , pair<int,int> &b)
{
    return a.second > b.second;
}

int main(int argc, const char *argv[])
{
    int n,k;
    cin >> n >> k;
    map<int,vector<int> > class_info;
    for(int i = 0 ; i < n ; i++)
    {
        int score;
        cin >> score;
        vector<int> time_info;
        time_info.push_back(score);
        class_info[i]=time_info;
    }
    for(int j = 0 ; j < n ;j++)
    {
        int status_;
        cin >> status_;
        class_info[j].push_back(status_);
    }
    
    vector<pair<int,int> >score_cmp;
    
    int count_nosleep=1;
    int scores_1=0;
    for (auto iter = class_info.begin(); iter != class_info.end(); ++iter) 
    {
        if ((iter->second)[1] == 0 )
        {
            int scores=0;
            for (auto iter_cal = iter; iter_cal != class_info.end(); ++iter_cal) 
            {
                if ((iter_cal->second)[1]==1) 
                { 
                    count_nosleep++;
                    continue;
                } 
                if( count_nosleep <= k) 
                {
                    scores+=(iter_cal->second)[0];
                    count_nosleep++;
                }
                else
                    break;
            }
            count_nosleep=1;
            score_cmp.push_back(pair<int,int>(iter->first,scores));
        }
        else
            scores_1+=(iter->second)[0];
    }
    sort(score_cmp.begin(),score_cmp.end(),cmp_scores);
    cout << scores_1+score_cmp[0].second;
    return 0;
}
