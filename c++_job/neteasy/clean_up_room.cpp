#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i != n; ++i) {
        vector<vector<pair<int, int>>>edge(4, vector<pair<int, int>>(4, { 0,0 }));
        for (int j = 0; j != 4; ++j) {
            int a, b, x, y;
            cin >> a >> b >> x >> y;
            edge[j][0] = { a,b };
            for (int k = 1; k != 4; ++k)
                edge[j][k] = { x + y - edge[j][k - 1].second,y - x + edge[j][k - 1].first };
        }
        int mincost = 0x7FFFFFFF;
        for (int a = 0; a != 4; ++a)
            for (int b = 0; b != 4; ++b) 
                for (int c = 0; c != 4; ++c) 
                    for (int d = 0; d != 4; ++d) {
                        vector<pair<int, int>>temp{ edge[0][a],edge[1][b],edge[2][c],edge[3][d] };
                        sort(temp.begin(), temp.end());
                        if (temp[1].second - temp[0].second != 0&&
                            temp[1].second - temp[0].second == temp[2].first - temp[0].first&&
                            temp[3].second - temp[2].second == temp[2].first-temp[0].first&&
                            temp[3].second - temp[1].second == temp[1].first-temp[0].first)
                            mincost = min(mincost, a + b + c + d);
                    }
        cout << (mincost == 0x7FFFFFFF ? -1 : mincost) << endl;
    }
    return 0;
}
