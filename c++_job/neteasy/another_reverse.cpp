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
    cin >> n;
    int cn = 0;
    int status_n = n;
    while(status_n)
    {
        cn = cn *10 + status_n%10;
        status_n/=10;
    }
    cout << n + cn <<endl;
    return 0;
}
