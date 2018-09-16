#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[])
{
    int n;
    scanf("%d",&n);
    int min_x = 999999999;
    int max_x = -999999999;
    int min_y = 999999999;
    int max_y = -999999999;
    vector<int> x_info;
    vector<int> y_info;
    for(int i = 0 ; i < n ; i++)
    {
        int x_;
        int y_;
        scanf("%d %d",&x_,&y_);
        if (x_ < min_x)
            min_x = x_;
        if(x_ > max_x )
            max_x = x_;
        if(y_ < min_y)
            min_y = y_;
        if(y_ > max_y)
            max_y = y_;
    }
    int border_len = max(max_x-min_x,max_y-min_y);

    printf("%d",border_len*border_len);
    return 0;
}
