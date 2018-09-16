#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int dp_balloon(int n , vector<int> balloon_info)
{
    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int i = 1 ; i <= n ; i++)
    {
        set<int> set_;
        int j = i-1;
        while(j >= 0 && set_.find(balloon_info[j]) == set_.end())
        {
            set_.insert(balloon_info[j]);
            dp[i] += dp[j];
            dp[i] = (int)(dp[i]%(int)(pow(10,9)+7));
            j--;
        }
    }
    return dp[n];
}

int main(int argc, const char *argv[])
{
    int n;
    scanf("%d",&n);
    vector<int> balloon_info;
    for(int i = 0 ; i < n ; i++)
    {
        int number;
        scanf("%d",&number);
        balloon_info.push_back(number);
    }

    cout << dp_balloon(n,balloon_info);

    return 0;
}
