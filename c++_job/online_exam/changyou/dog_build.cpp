#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

#define Max 1000

using namespace std;

int main(int argc, const char *argv[])
{
    int N,arry[Max];
    scanf("%d",&N);
    arry[1] = 1;
    arry[2] = 1;
    for(int i = 3 ; i <= N ; i++)
    {
        arry[i] = arry[i-1]+arry[i-2];
    }
    printf("%d",arry[N]);
    return 0;
}
