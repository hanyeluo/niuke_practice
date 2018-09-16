#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
    long n;
    scanf("%ld",&n);
    vector<pair<long,long> > result;

    for(int i = 0 ; i < n ; i++)
    {
        long n,k;
        scanf("%ld %ld",&n,&k);
        if(n <= 2)
        {
            result.push_back(pair<long,long>(0,0));
        }
        else
        {
            long check = n%3;
            long count = n/3;
            if(check == 0 || check == 2 || check == 1)
            {
                if(k >= count*2)
                    result.push_back(pair<long,long>(0,count));
                else
                    result.push_back(pair<long,long>(0,k/2));
            }
        }
    }


    for (auto iter = result.begin(); iter != result.end(); ++iter) 
    {
        printf("%ld %ld\n",iter->first,iter->second);
    }
    return 0;
}
