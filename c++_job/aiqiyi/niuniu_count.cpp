#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

#define mod 1000000007

using namespace std;

int main(int argc, const char *argv[])
{
    int n;
    scanf("%d",&n);
    vector<int> niu_info;
    for(int i = 0 ; i < n ; i++)
    {
        int count_num;
        scanf("%d",&count_num);
        niu_info.push_back(count_num);
    }
    sort(niu_info.begin(),niu_info.end());
    
    long long int result = 1;
    for(int i = 0 ; i < n ; i++)
    {
        if(niu_info[i] <= i)
        {
            cout << 0 << endl;
            return 0;
        }
        result = result*(niu_info[i]-i)%mod;
    }

    cout << result << endl;

    return 0;
}
