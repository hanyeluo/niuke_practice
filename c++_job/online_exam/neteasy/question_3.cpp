#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

long check_cap(long index , vector<long> &capacity_pogoda , vector<long> hive_wine)
{
    long result = capacity_pogoda[index] - hive_wine[index];
    if (result <= 0)
        return 0;
    else
        return result;
}

long input_wine(long index , long input , vector<long> &capacity_pogoda , vector<long> &hive_wine)
{
    long result = capacity_pogoda[index] - hive_wine[index];
    if (input <= result) 
    {
        hive_wine[index] += input;
        return -1;
    }
    else
    {
        hive_wine[index] = capacity_pogoda[index];
        return input - result;
    }
}


int main(int argc, const char *argv[])
{
    long n,m;
    vector<long> capacity_pogoda;

    vector<long> result;
    scanf("%ld %ld",&n,&m);

    vector<long> hive_wine(n,0);
    for(long i = 0; i < n ; i++)
    {
        long _capacity;
        scanf("%ld",&_capacity);
        capacity_pogoda.push_back(_capacity);
    }


    for(int t = 0 ; t < m ; t++)
    {
        int type;
        long x,v;
        long k;
        scanf("%d",&type);
        if(type == 2)
        {
            scanf("%ld %ld",&x,&v);
            while( check_cap(x-1 , capacity_pogoda , hive_wine) != 0 && x <= n)
                x++;
            if(x > n)
                x = n;
            v = input_wine(x-1 , v , capacity_pogoda , hive_wine);
            while( v !=-1 && x<n && v>0)
            {
                x++;
                v = input_wine(x-1 , v , capacity_pogoda , hive_wine);
            }
        }
        else if(type == 1)
        {
            scanf("%ld",&k);
            result.push_back(hive_wine[k-1]);
        }
        else
            continue;
    }

    for (auto iter = result.begin(); iter != result.end(); ++iter) 
    {
        printf("%ld",*iter);
    } 

    return 0;
}
