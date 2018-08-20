#include <iostream>

using namespace std;

bool ifprime(int a)
{
    for(int i = 2 ; i < a ; i++)
    {
        if(a%i==0)
            return false;
    }
    return true;
}


int main(int argc, const char *argv[])
{
    int n;
    cin >> n;
    int i = 3;
    int j = n-i;
    int count = 0;
    while(i<=j)
    {
        if (!ifprime(i))
        {
            i++;
            j=n-i;
            continue;
        }
        if(!ifprime(j))
        {
            i++;
            j=n-i;
            continue;
        }
        count++;
        i++;
        j=n-i;
    }
    cout << count;
    return 0;
}
