#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

long long getsum(long long x)
{
    long long sum = 0;
    while(x!=0)
    {
        sum+=x;
        x/=(long long)10;
    }
    return sum;
}

int main(int argc, const char *argv[])
{
    long long sum , l , r , mid;
    scanf("%lld",&sum);
    for(l = 0 , r =sum ;l+1 < r;)
    {
        mid = l + (r-l)/2;
        if(getsum(mid) == sum)
        {
            printf("%lld",mid);
            return 0;
        }
        else if (getsum(mid) < sum)
            l = mid;
        else
            r = mid;
    }
    if(getsum(l)==sum)
        printf("%lld",l);
    else if (getsum(r)==sum)
        printf("%lld",r);
    else
        printf("%d",-1);
    return 0;
}
