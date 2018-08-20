#include <iostream>
#include <vector>

using namespace std;

bool cmp(int a , int b)
{
    return a > b;
}

int main(int argc, const char *argv[])
{
    int a,b,c;
    cin >> a >> b >> c;
    if(a==1 || b==1 || c==1)
    {
        vector<int> _number;
        _number.push_back(a);
        _number.push_back(b);
        _number.push_back(c);
        sort(_number.begin(),_number.end(),cmp);
        cout << _number[0]*(_number[1]+_number[2]);
    }
    else
        cout << a*b*c;
    return 0;
}
