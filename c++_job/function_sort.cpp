#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

//Quicksort
//template<class T>
void Quicksort(vector<int> &a , int left , int right)
{
    if(left >= right)
        return;

    int pivot = a[left];
    int leftindex = left;
    int rightindex = right;
    while( leftindex < rightindex)
    {
        while(leftindex < rightindex)
        {
            if(pivot <= a[rightindex])
                rightindex--;
            else
            {
                a[leftindex] = a[rightindex];
                leftindex++;
                break;
            }
        }

        while(leftindex<rightindex)
        {
            if(pivot >= a[leftindex])
                leftindex++;
            else
            {
                a[rightindex]=a[leftindex];
                rightindex--;
                break;
            }
        }
    }
    a[leftindex]=pivot;
    Quicksort(a,left,leftindex-1);
    Quicksort(a,rightindex+1,right);
}

void BubbleSort(vector<int> &a)
{
    int len = a.size();
    for(int i = 0 ; i < len ; i++)
    {
        for(int j = 0 ; j < len-i-1 ; j++)
        {
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
}

int main(int argc, const char *argv[])
{
    int n;
    scanf("%d",&n);
    vector<int> a;
    for(int i = 0 ; i < n ; i++)
    {
        int x;
        scanf("%d",&x);
        a.push_back(x);
    }
    BubbleSort(a);
    for (auto iter = a.begin(); iter != a.end(); ++iter) {
        cout << *iter << " ";
    } 
    return 0;
}
