#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

int index_max(vector<int> &apple_info)
{
    auto max_vec = max_element(begin(apple_info),end(apple_info));
    int index_max = distance(begin(apple_info),max_vec);
    return index_max;
}

int index_min(vector<int> &apple_info)
{
    auto min_vec = min_element(begin(apple_info),end(apple_info));
    int index_min = distance(begin(apple_info),min_vec);
    return index_min;
}

int main(int argc, const char *argv[])
{
    int n;
    vector<int> apple_info;
    scanf("%d",&n);
    
    for(int i = 0 ; i < n ; i++)
    {
        int count_apple;
        scanf("%d",&count_apple);
        apple_info.push_back(count_apple);
    }
    
    //sort(apple_info.begin(),apple_info.end(),cmp);
    int max_index = index_max(apple_info);
    int min_index = index_min(apple_info);
    
    int distent = apple_info[max_index]-apple_info[min_index];
    int step = 0;

    while(distent > 0 )
    {
        step++;
        apple_info[max_index]-=2;
        apple_info[min_index]+=2;
        max_index = index_max(apple_info);
        min_index = index_min(apple_info);
        distent = apple_info[max_index]-apple_info[min_index];
    }

    if (distent == 0)
        printf("%d\n",step);
    else
        printf("%d\n",-1);

    return 0;
}
