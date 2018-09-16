#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

long step(int N,vector<int> &can_use)
{
    if(find(can_use.begin(),can_use.end(),N) != can_use.end())
        return N;

    long reu=0;
    for(int i = 0 ; i < can_use.size() ; i++)
        reu+=step(N-can_use[i],can_use);
    return reu;
}

int main(int argc, const char *argv[])
{
    int M;
    vector<long> result_;
    for(int i = 0 ; i < M ; i++)
    {
        int N;
        vector<int> can_use;
        scanf("%d",&N);
        for(int j = 0 ; ;j++)
        {
            int x = pow(2,j);
            if(j<N)
                can_use.push_back(N);
            else
                break;
        }

        long result = step(N,can_use);
        long moddle = pow(10,9)+3;
        long count_ = result % moddle;
        result_.push_back(count_);
    }

    for (auto iter = result_.begin(); iter != result_.end(); ++iter) {
        cout << *iter << endl;
    } 
    return 0;
}
