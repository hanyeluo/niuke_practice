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
    int left_no = 0;
    stack<char> s_stack;
    for (auto iter = s.begin(); iter != s.end(); ++iter) 
    {
        char s_r = *iter;
        if(s_r == '(')
            s_stack.push(s_r);
        if(s_r == ')')
        {
            if(s_stack.size() != 0)
                s_stack.pop();
            else
                left_no++;
        }
    }

    cout << s_stack.size() + left_no << endl;
    return 0;
}
