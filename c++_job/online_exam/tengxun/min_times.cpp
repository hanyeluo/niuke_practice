#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
    long x , y;
    scanf("%ld %ld",&x,&y);
    vector<long> num_vec;
    long count = 1;
    long sum = 0;
    long result = 0;
    while( sum < x+y)
    {   
        sum += count;
        num_vec.push_back(count);
        count++;
    }

    count--;

    if( x > count )
    {
        result++;
        long dis = x-count;
        while( num_vec[num_vec.size()-1] <= dis )
        {
            dis = dis - num_vec[num_vec.size()-1];
            num_vec.erase(num_vec.begin()+num_vec.size()-1);
            result++;
        }
        if(dis != 0)
            result++;
    }
    else
    {
        result = 1;   
    }

    cout << result << endl;

    return 0;
}
