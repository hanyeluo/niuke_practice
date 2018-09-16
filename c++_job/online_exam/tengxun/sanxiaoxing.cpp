#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

bool if_triangle(int a,int b,int c)
{
    if(a+b>c && a+c>b && b+c >a)
        return true;
    else
        return false;
}

int main(int argc, const char *argv[])
{
    int x ,y ,z;
    scanf("%d %d %d",&x,&y,&z);
    long result = 0;
    for(int i = 1 ; i <= x ; i++)
    {
        for(int j = 1 ; j <= y ; j++)
        {
            for(int k = 1 ; k <= z ; k++)
            {
                if(if_triangle(i,j,k))
                {
                    result += 1;
                }
            }
        }
    }

    long out = result % 10000007;
    cout << out << endl;
    return 0;
}
