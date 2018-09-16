#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
    int n;
    vector<int> numbers(n+1,0);
    vector<int> maxmen(n+1,0);
    int maxN = 0;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++)
    {
        int number;
        scanf("%d",&number);
        numbers[i]=number;
        maxmen[i]=max(maxmen[i-1]+numbers[i],numbers[i]);
        maxN = max(maxmen[i],maxN);
    }

    cout << maxN;

    return 0;
}
