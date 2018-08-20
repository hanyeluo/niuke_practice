#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;




int main(int argc, const char *argv[])
{
    int t;
    scanf("%d",&t);
    vector<string> result;
    for(int j = 0 ; j < t ; j++)
    {
        int n;
        scanf("%d",&n);
        int count_Four = 0;
        int count_two = 0;
        int count_another = 0;
        for(int i = 0 ; i < n ; i++)
        {
            int x;
            scanf("%d",&x);
            if(x%4 == 0)
                count_Four++;
            else if ( x%2 == 0)
                count_two++;
        }
        count_another=n-count_Four-count_two;
        if((n==1 && count_Four) || (count_Four >= count_another - !count_two))
        {
            result.push_back("Yes");
        }
        else
        {
            result.push_back("No");
        }
    }
    for (auto iter = result.begin(); iter != result.end(); ++iter) 
    {
        cout << *iter << endl;
    } 
    return 0;
}
