#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(pair<int,int> a , pair<int,int> b)
{
    return a.second > b.second;
}

int main(int argc, const char *argv[])
{
    int N,M,P;
    vector<pair<int,int> > food_info;
    scanf("%d %d %d",&N,&M,&P);
    for(int i = 1 ; i <= N ; i++)
    {
        int Ai;
        scanf("%d",&Ai);
        food_info.push_back(pair<int,int>(i,Ai));
    }

    for(int j = 0 ; j < M ; j++)
    {
        string action;
        int food_num;
        cin >> action >> food_num;
        if(action == "A")
        {
            food_info[food_num-1].second++;
        }
        else if(action == "B")
        {
            food_info[food_num-1].second--;
        }
        else
            continue;
    }

    sort(food_info.begin(),food_info.end(),cmp);

    int res = 0 ;
    while( res < food_info.size()-1 )
    {
        if(food_info[res].first == P)
            break;
        else
            res++;
    }

    int result = res;
    for(int k = res ; k-1 > 0 ; k--)
    {
        if(food_info[k].second == food_info[k-1].second)
            continue;
        else
        {
            result = k;
            break;
        }
    }

    printf("%d",result+1);
    return 0;
}
