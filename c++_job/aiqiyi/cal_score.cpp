#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

long long int csum(long long int sum)
{
    long long int result = 0;
    while(sum)
    {
        result += sum;
        sum /= 10;
    }
    return result;
}

int main(int argc, const char *argv[])
{
    long long int sum;
    cin >> sum;
    long long int start = 1;
    long long int end = sum;
    while(start + 1< end)
    {
        long long int mid = start + (end - start)/2;
        if( csum(mid) == sum)
        {
            cout << mid << endl;
            return 0;
        }
        else if( csum(mid) > sum)
            end = mid;
        else
            start = mid;
    }
    if(csum(start) == sum)
        cout << start << endl;
    else if(csum(end) == sum)
        cout << end << endl;
    else
        cout << -1 << endl;

    return 0;
}
