#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    long n;
    cin >> n;
    int a[6]={1,5,10,20,50,100};
    vector<long> dp(n+1,0);
    dp[0]=1;
    for(int i = 0 ; i < 6 ; i++)
    {
        for (long j = 1 ; j < n+1 ; j++) 
        {
            if( j >= a[i])
            {
                dp[j]+=dp[j-a[i]];
            }
        } 
    }
    cout << dp[n];
    return 0;
}
