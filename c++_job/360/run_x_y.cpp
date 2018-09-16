#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, const char *argv[])
{
    int L , R;
    scanf("%d %d",&L,&R);
    float x = (float)(R*cos((float)L/R));
    float y = (float)(R*sin((float)L/R));
    printf("%.3f %.3f\n",x,-y);
    printf("%.3f %.3f\n",x,y);
    return 0;
}
