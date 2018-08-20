#include <iostream>
#include <list>
#include <vector>
#include <utility>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	int m;
	cin >> m;

    int tran = 0;
    bool iftran = false;
    int result = 0;
    for(int i = 1; i <= n ; i++)
    {
        if (tran < m)
        {
            tran++;
            if(iftran)
                result += i;
            else
                result += -i;
        }
        else
        {
            tran = 1;
            if (iftran)
                iftran = false;
            else
                iftran = true;

            if(iftran)
                result += i;
            else
                result += -i;
        }
    }

    cout << result;
    return 0;
}
