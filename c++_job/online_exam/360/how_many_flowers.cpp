#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[])
{
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> flowers_info;
    for(int i = 0 ; i < n ; i++)
    {
        int flower_number;
        scanf("%d",&flower_number);
        flowers_info.push_back(flower_number);
    }

    vector<vector<int> > flower_number_info;

    for( int x = 0 ; x < n ; x++)
    {
        vector<int> x_vec;
        x_vec.push_back(1);
        for(int y = x+1 ; y < n ; y++)
        {
            set<int> flowers;
            for(int m = x; m <= y ; m++)
            {
                flowers.insert(flowers_info[m]);
            }
            x_vec.push_back(flowers.size());
        }
        flower_number_info.push_back(x_vec);
    }
    
    long question_num;
    scanf("%ld",&question_num);
    vector<int> results;
    for(long j = 0 ; j < question_num ; j++)
    {
        int begin;
        int end;
        scanf("%d %d",&begin,&end);
        //set<int> flowers;
        //for(int m = begin-1; m < end ; m++)
        //{
        //    flowers.insert(flowers_info[m]);
        //}
        results.push_back(flower_number_info[begin-1][end-1]);
    }

    for (auto iter = results.begin(); iter != results.end(); ++iter) {
        printf("%d\n",*iter);
    } 

    return 0;
}
