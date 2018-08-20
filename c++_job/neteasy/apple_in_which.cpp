#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    int n;
    cin >> n;
    vector<long> apple_step;
    apple_step.push_back(0);
    for(int i = 1 ; i < n ;i++)
    {
        int count_num;
        cin >> count_num;
        int count_min = apple_step[i-1];
        count_min += count_num;
        apple_step.push_back(count_min);
    }
    int m;
    cin >> m;
    for(int j = 0 ; j < m ;j++)
    {
        int q;
        cin >> q;
        int loc = lower_bound(apple_step.begin(),apple_step.end(),q)-apple_step.begin();
        cout << loc << endl;
    }
    return 0;
}
