#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, const char *argv[])
{
    long n;
    cin >> n;
    long n_mid = n;
    vector<int> result;
    while( n_mid > 0)
    {
        if(n_mid%2 == 0)
        {
            n_mid = (n_mid-2)/2;
            result.insert(result.begin(),2);
        }
        else
        {
            n_mid = (n_mid-1)/2;
            result.insert(result.begin(),1);
        }
    }
    stringstream ss;
    copy(result.begin(),result.end(),ostream_iterator<int>(ss,""));
    cout << ss.str();
    return 0;
}
