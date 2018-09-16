#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

int maxSumInSubArray(vector<int> & array , int len , int &begin , int &endd)
{
    int *c = new int[len];
    int max = -1000;
    int start = 0;
    int end = 0;
    int tmp = 0;
 
    c[0] = array[0];
    for(int i = 1;i < len;++i)
    {
        if(c[i-1] > 0)
        {
            c[i] = c[i-1] + array[i];
        }
        else
        {
            c[i] = array[i];
            tmp = i;
        }
        if(c[i] > max)
        {
            max = c[i];
            start = tmp;
            end = i;
        }
    }
    
    vector<int>::iterator begin_ = array.begin() + start;
    vector<int>::iterator end_ = array.begin() + end;
    array.erase(begin_,end_);
    begin = start;
    endd = end;
    //cout<<"子数组最大和的起始位置："<<start<<"~"<<end<<endl;
    return max;
}


int main(int argc, const char *argv[])
{
    int N,M;
    scanf("%d %d",&N,&M);
    vector<pair<int,int> > no_use;
    vector<int> A;
    int zheng_count = 0;
    bool hive = true;

    int max_count = 0;

    for(int i = 0 ; i < N ; i++)
    {
        int count_;
        scanf("%d",&count_);
        if(count_>= 0)
        {
            if(hive == true)
                max_count+=count_;
            else
            {
                zheng_count++;
                max_count+=count_;
                hive = true;
            }
        }
        else
            hive = false;

        A.push_back(count_);
    }

    if (zheng_count+1 <= M)
    {
        cout << max_count;
        return 0;
    }

    int result_max;

    while(M>0)
    {
        int begin;
        int end;
        result_max += maxSumInSubArray(A,A.size(),begin,end);
        M--;
    }

    cout << result_max;
    
    return 0;
}
