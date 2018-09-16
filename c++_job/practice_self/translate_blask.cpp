#include <iostream>
using namespace std;

class Replacement 
{
public:
	static string replaceSpace(string iniString, int length) 
	{
		// write code here
		int blacknumber=0;
		for(int i = 0 ; i < length ; i++)
		{
			if(iniString[i]==" ")
				blacknumber++;
			else
				continue;
		}
		char* result = new char[length+2*blacknumber];
		int length_result = length+2*blacknumber;
		for (int j = length-1 ; j >= 0 ; j--)
		{
			if(iniString[j]==" ")
			{
				result[length_result--]="0";
				result[length_result--]="2";
				result[length_result--]="%";
			}
			else 
			{
				result[length_result--]=iniString[j];
			}
		}
		string result_str=result;
		return result_str;
	}
};

int main(int argc, char *argv[]) 
{
	string iniString;
	int length;
	string input;
	cin >> iniString  
}