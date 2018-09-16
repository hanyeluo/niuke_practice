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
    int res=0;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        int x;
        scanf("%d",&x);
        while(s.size() && s.top() <= x)
        {
            res=max(res,x^s.top());
            s.pop();
        }
        if(s.size())
            res=max(res,x^s.top());
        s.push(x);
    }
    printf("%d\n",res);
    return 0;
}
