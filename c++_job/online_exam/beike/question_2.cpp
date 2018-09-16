#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
    int n , m ;
    scanf("%d %d",&n,&m);
    int info[n+1][n+1];
    for(int i = 0 ; i < m ; i++)
    {
        int x , y;
        scanf("%d %d",&x,&y);
        info[x][y] = 1;
        info[y][x] = 1
    }

    if(m >= n)
        cout << 0;
    return 0;
}
