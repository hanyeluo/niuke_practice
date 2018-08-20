#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp_sort(int a , int b)
{
    return a > b;
}

int main()
{
    int n ;
    cin >> n;
    vector<int> numbers;
    for(int i = 0 ; i < n ; i++)
    {
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    int scores_n = 0;
    int scores_y = 0;
    
    sort(numbers.begin(),numbers.end(),cmp_sort);

    int tag = 0;

    for(auto itor = numbers.begin() ; itor != numbers.end() ; itor++)
    {
        if (tag%2 == 0)
            scores_n+=*itor;
        else
            scores_y+=*itor;

        tag++;  
    }

    cout << scores_n-scores_y;
    return 0;
}
