#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[])
{
    int n;
    vector<int> input_squ;
    vector<int> maxmen;
    vector<int> minmen;
    vector<int> index;
    cin >> n;

    if (n < 0 )
        return 1;
    for(int i = 0 ; i < n ; i++)
    {
        int number;
        cin >> number;
        input_squ.push_back(number);
    }

    if(n == 1)
    {
        cout << input_squ[0];
        return 0;
    }

    int max_ = input_squ[0];
    maxmen.push_back(input_squ[0]);
    minmen.push_back(input_squ[0]);
    index.push_back(0);

    for(int j = 1 ; j < n ; j++)
    {
        maxmen.push_back(max(max(maxmen[j-1]*input_squ[j],minmen[j-1]*input_squ[j]),input_squ[j]));
        if(maxmen[j] == input_squ[j])
            index.push_back(j);
        minmen.push_back(min(min(maxmen[j-1]*input_squ[j],minmen[j-1]*input_squ[j]),input_squ[j]));
        if(minmen[j] != minmen[j-1])
            index.push_back(index[index.size()-2]);
    }

    int max_index = 0;
    for (auto iter = maxmen.begin(); iter != maxmen.end(); ++iter) 
    {
        if( max_ < *iter)
        {
            max_ = *iter;
            max_index = distance(begin(maxmen),iter);
        }
    }

    cout << max_ << endl;
    
    int begin = index[index.size()-1];
    for(int m = begin ; m <= max_index ; m++)
    {
        printf("%d\t",input_squ[m]);
    }

    return 0;
}
