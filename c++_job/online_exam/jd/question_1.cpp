#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

bool cmp_big(int a , int b)
{
    return a > b;
}


int main(int argc, const char *argv[])
{
    int T;
    scanf("%d",&T);
    vector<string> result;
    for(int i = 0 ; i < T ; i++)
    {
        int N,M;
        scanf("%d %d",&N,&M);
        int struct_tu[N][N];
        int vNum = N;
        int eNum = M;
        int visited[N];
        vector<int> count_tu(0,N);
        for(int j = 0 ; j < M ; j++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            struct_tu[x][y] = 1;
            struct_tu[y][x] = 1;
            count_tu[x-1]+=1;
            count_tu[y-1]+=1;
        }


        sort(count_tu.begin(),count_tu.end(),cmp_big);

        int maxcount = count_tu[0];

        int mincount = count_tu[N-1];

        if(mincount == 1 || mincount ==0)
            result.push_back("No");
    }

    for (auto iter = result.begin(); iter != result.end(); ++iter) {
        cout << *iter << endl;
    } 
    return 0;
}
