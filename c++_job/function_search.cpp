#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

//二分查找
template<class Type>
int BinarySearch(Type a[],const Type& x,int n)
{
    int left=0;
    int right=n-1;
    while(left<=right)
    {
        int middle=(left+right)/2;
        if(a[middle]==x)
            return middle;
        if(x>=a[middle])
            left=middle+1;
        else
            right=middle-1;
    }
    return -1;
}

int main(int argc, const char *argv[])
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int search_a;
    scanf("%d",&search_a);
    cout << BinarySearch(a,search_a,10) << endl;
    return 0;
}
