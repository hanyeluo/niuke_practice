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
    int m,n;
    while( cin >> m >> n)
    {
        int count = 0;
        vector<int> shuixianhua;
        for( int i = m ; i <= n ; i++)
        {
            int gewei = pow(i%10,3);
            int shiwei = pow((i/10)%10,3);
            int baiwei = pow((i/100)%10,3);
            if( gewei + shiwei + baiwei == i)
            {
                shuixianhua.push_back(i);
                count++;
            }
        }
        if(count == 0)
            cout << "no" << endl;
        else
        {
            for (auto iter = shuixianhua.begin(); iter != shuixianhua.end(); ++iter) {
                cout << *iter << " ";
            } 
        }
    }

    return 0;
}
