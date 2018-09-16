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
    string s;
    cin >> s;
    stack<char> stk;
    int Max = 0;
    for (auto iter = s.begin(); iter != s.end(); ++iter) {
        char s_x = *iter;
        if(s_x == '(')
        {
            stk.push(s_x);
            int size_stk = stk.size();
            Max = max(Max,size_stk);
        }
        else
            stk.pop();
    } 
    printf("%d",Max);
    return 0;
}
