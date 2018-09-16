#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

bool cmp(vector<int> a , vector<int> b)
{
    return a[0] < b[0];
}

void find_in(vector<vector<int> > & info_index , set<int> & index , int n)
{
    for (auto iter = index.begin(); iter != index.end(); ++iter) 
    {
        for(int i = *iter ; i < n ; i++)
        {
            if(info_index[i][2] >= info_index[*iter][0] && info_index[i][3] <= info_index[*iter][0])

                index.insert(i);
            if(index.size() == n)
                break;
        }
        if(index.size() == n)
            break;
    }
}

int main(int argc, const char *argv[])
{
    int n ;
    scanf("%d",&n);
    vector<vector<int> > info;
    vector<vector<int> > info_index;
    for(int i = 0 ; i < n ; i++)
    {
        vector<int> info_;
        int x,h;
        scanf("%d %d",&x,&h);
        info_.push_back(x);
        info_.push_back(h);
        info_.push_back(x+1);
        info_.push_back(x+h-1);
        info.push_back(info_);
    }
    info_index = info;
    vector<int> result;
    sort(info_index.begin(),info_index.end(),cmp);
    for (auto iter = info.begin(); iter != info.end(); ++iter) 
    {
        int count = 0;
        set<int> index;
        auto info_i = find(info_index.begin(),info_index.end(),*iter);
        for (auto iter_ = info_i; iter_ != info_index.end(); ++iter_) 
        {
            if((*iter_)[0] >= (*info_i)[2] && (*iter)[0] <= (*info_i)[2])
            {
                index.insert(distance(begin(info_index),info_i));
            }
            if(index.size() == n)
                result.push_back(n);
            else
                find_in(info_index,index,n);

        }
        result.push_back(index.size());
    } 

    for (auto iter1 = result.begin(); iter1 != result.end(); ++iter1) {
        printf("%d\t",*iter1);
    } 

    

    return 0;
}
