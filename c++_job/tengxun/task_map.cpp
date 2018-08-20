#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int check_info(int time , int level , vector<pair<int,int> > & monitor_numbers ,int &index)
{
    int canfinish = 0;
    int smaller=monitor_numbers[0].second;
    index = -1;
    for (auto iter = monitor_numbers.begin(); iter != monitor_numbers.end(); ++iter) 
    {
        if (iter->first >= time && iter->second >= level) 
        { 
            canfinish++;
            if(smaller > iter->second)
                index = iter-monitor_numbers.begin();
        } 
        else
            continue;
    } 
    return canfinish;
}

int check_info(int time , int level , vector<pair<int,int> > & monitor_numbers ,int &index , vector<int> &delete_index)
{
    int canfinish = 0;
    int smaller=1000;
    index = -1;
    int mid_index = 0;
    for (auto iter = monitor_numbers.begin(); iter != monitor_numbers.end(); ++iter)
    {
        if (iter->first >= time && iter->second >= level)
        {
            canfinish++;
            mid_index = iter-monitor_numbers.begin();
            if(smaller > iter->second &&(find(delete_index.begin(),delete_index.end(),mid_index) == delete_index.end()))
                index = mid_index;
        }
        else
            continue;
    }
    return canfinish;
}
bool cmp_count(vector<int> &a , vector<int> &b)
{
    return a[2] < b[2];
}

bool cmp_time(pair<int,int> &a , pair<int,int> &b)
{
    return a.first < b.first;
}

int main(int argc, const char *argv[])
{
    int N , M;
    cin >> N >> M ;
    vector<pair<int,int> > monitor_numbers;
    vector<vector<int> > task_info;
    vector<int> delete_index;
    int number = 0;
    for(int i = 0 ; i < N ; i++)
    {
        int time,level;
        cin >> time >> level;
        monitor_numbers.push_back(pair<int,int>(time,level));
    }
    sort(monitor_numbers.begin(),monitor_numbers.end(),cmp_time);

    for (int j = 0 ; j < M ; j++) 
    {
        int time , level , index;
        cin >> time >> level;
        int count = check_info(time,level,monitor_numbers,index);
        vector<int> info;
        info.push_back(time);
        info.push_back(level);
        info.push_back(count);
        info.push_back(index);
        task_info.push_back(info);
    }

    sort(task_info.begin(),task_info.end(),cmp_count);
    
    for (auto iter = task_info.begin(); iter != task_info.end(); ++iter) 
    {
        if (delete_index.size() == monitor_numbers.size())
        { 
            break;
        } 
        int now_index = iter-task_info.begin();
        if(find(delete_index.begin(),delete_index.end(),(*iter)[3]) == delete_index.end())
        {
            if ((*iter)[3]==-1) 
            { 
                continue;
            } 
            delete_index.push_back((*iter)[3]);
            number += (*iter)[0]*200+(*iter)[1]*3;
        }
        else
        {
            int index;
            check_info((*iter)[0],(*iter)[1],monitor_numbers,index,delete_index);
            if (index != -1) 
            { 
                delete_index.push_back(index);
                number+= (*iter)[0]*200+(*iter)[1]*3;
            } 
            else
                continue;
        }
    } 

    cout << delete_index.size() << " " << number;
    return 0;
}
