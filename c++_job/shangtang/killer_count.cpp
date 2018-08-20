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
    int killer_info[n+1][n+1];
    memset(killer_info,0,sizeof(killer_info));
    vector<int> killed_list;
    for(int i =1 ; i <= n ; i++)
    {
        int kill;
        cin >> number_kill;
        killer_info[i][kill] = 1;
    }
    


    return 0;
}
