#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char *argv[])
{
    int N , M ;
    cin >> N >> M;
    int time = 0;
    for (int i = 0 ; i < N ; i++)
    {
        time += pow(2,i);
    }

    int result = (M/time) *pow(2,N-1);
    cout << result;
    return 0;
}
