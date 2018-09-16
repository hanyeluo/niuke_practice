#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, const char *argv[])
{
    int n;
    scanf("%d",&n);
    long max_number = pow(10,18);
    long result = 0;
    for(long i = n ; i < max_number ; i++)
    {
        int count = 0;
        for(long j = 1 ; j <= i ; j++)
        {
            if(i%j == 0)
                count++;
        }
        if(count == n)
        {
            result=i;
            break;
        }
    }
    printf("%ld",result);
    return 0;
}
