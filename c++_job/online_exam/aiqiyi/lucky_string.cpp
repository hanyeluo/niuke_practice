#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

void trans(string &str , int &num)
{
    stringstream stream(str);
    stream >> num;
}

void trans(char &str , int &num)
{
    num = (int)(str-48);
}

void trans(int &num , string &str)
{
    stringstream stream;
    stream << num;
    str = stream.str();
}

int getsum(int num)
{
    int sum = 0;
    while(num>0)
    {
        int x = num%10;
        sum +=x;
        num = num/10;
    }
    return sum;
}

int getmin(string &num_str , int &index)
{
    int _min =10;
    int k =0;
    while(k < num_str.size()-1)
    {
        int num =0;
        trans(num_str[k],num);
        if (_min > num)
        {
            _min = num;
            index = k;
        }
        k++;
    }
    return _min;
}

int main(int argc, const char *argv[])
{
    string s;
    cin >> s;
    string num_str1 = s.substr(0,3);
    string num_str2 = s.substr(3,3);
    int num1= 0;
    int num2= 0;
    trans(num_str1,num1);
    trans(num_str2,num2);
    int sum1 = getsum(num1);
    int sum2 = getsum(num2);
    
    if(sum1 < sum2)
    {
        swap(num_str1,num_str2);
        swap(sum1,sum2);
        swap(num1,num2);
    }
    
    int count_tran = 0;
    int dis = sum1 - sum2;
    while(dis != 0)
    {
        int min_index;
        int _min = getmin(num_str2,min_index);
        if(dis > 9-_min)
        {
            num_str2.replace(min_index,1,"9");
        }
        else
        {
            string need_replace="";
            int count = dis;
            trans(count,need_replace);
            num_str2.replace(min_index,1,need_replace);
        }
        trans(num_str2,num2);
        sum2 = getsum(num2);
        dis = sum1-sum2;
        count_tran++;
    }

    printf("%d",count_tran);
    return 0;
}
