#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
    int n;
    scanf("%d",&n);
    vector<int> numbers;
    for(int i = 0 ; i < n ; i++)
    {
        int num;
        scanf("%d",&num);
        numbers.push_back(num);
    }

    vector<int> dp(n,0);
    dp[0] = numbers[0];
    dp[1] = max(numbers[0],numbers[1]);

    for(int j = 2 ; j < n ; j++)
    {
        if ( dp[j-1] == dp[j-2])
            dp[j] = dp[j-1]+numbers[j];
        else
            dp[j] = dp[j-1];
    }
    
    cout << dp[n-1] << endl;
    return 0;
}
