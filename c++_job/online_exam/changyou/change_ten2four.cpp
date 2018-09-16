#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main(int argc, const char *argv[])
{
    int n;
    stack<int> s;
    cin >> n;
    while(n)
    {
        s.push(n%4);
        n/=4;
    }
    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    return 0;
}
