#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

bool cmp_sale(pair<int,int> a , pair<int,int> b)
{
    return a.second > b.second;
}

bool cmp_tables(int a , int b)
{
    return a < b;
}

int main(int argc, const char *argv[])
{
    int n , m ;
    scanf("%d %d",&n,&m);
    vector<int> tables_info;
    vector<pair<int,int> >person_info;
    for(int i = 0 ; i < n ; i++)
    {
        int count_;
        scanf("%d",&count_);
        tables_info.push_back(count_);
    }
    for(int j = 0 ; j < m ; j++)
    {
        int counts,sales;
        scanf("%d %d",&counts,&sales);
        person_info.push_back(pair<int,int>(counts,sales));
    }

    sort(tables_info.begin(),tables_info.end(),cmp_tables);
    sort(person_info.begin(),person_info.end(),cmp_sale);
    int sum = 0;
    vector<int> selected_table;

    for (auto iter_ = person_info.begin(); iter_ != person_info.end(); ++iter_) 
    {
        for (auto iter = tables_info.begin(); iter != tables_info.end(); ++iter) 
        {
            if(count(selected_table.begin(),selected_table.end(),*iter) >= count(tables_info.begin(),tables_info.end(),*iter))
                continue;
            if(*iter >= iter_->first)
            {
                selected_table.push_back(*iter);
                sum += iter_->second;
            }
            else
                continue;
        }
    } 

    printf("%d",sum);
    return 0;
}
