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
    for(int i = 0 ; i < t ; i++)
    {
        long number;
        scanf("%ld",&number);
        long count_ = number;
        bool niu_yang = false;
        while( count_ )
        {
            niu_yang = !niu_yang;
            if(count_ < 4)
                count_--;
            else
            {
                count_= count_%4;
            }
        }
        if(niu_yang)
            result.push_back("niu");
        else
            result.push_back("yang");
    }

    for (auto iter = result.begin(); iter != result.end(); ++iter) 
    {
        printf("%s\n",(*iter).c_str());
    } 

    return 0;
}
