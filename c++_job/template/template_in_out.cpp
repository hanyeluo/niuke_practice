#include <iostream>
#include <list>
#include <vector>
#include <utility>

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b)
{
	return a.first > b.first;
}

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<pair<int,int> > count_apple; 
	for (int i = 0 ; i < n ; i++)
	{
		int count;
		int number;
		cin >> count;
		cin >> number;
		pair<int,int> _pair(count,number);
		count_apple.push_back(pair<int,int>(count,number));
	}
	
	sort(count_apple.begin(),count_apple.end(),comp);
//	int question_time;
//	cin >> question_time;
//	list<int> question_count;
//	for (int i = 0 ; i < question_time ; i++)
//	{
//		int number;
//		cin >> number;
//		question_count.push_back(number);
//	}
	int i = 0;
	for(auto itor = count_apple.begin(); itor != count_apple.end();itor++)
	{
		i++;
		if (i != count_apple.size())
			cout << itor->first << " " << itor->second << endl;
		else
			cout << itor->first << " " << itor->second << endl;
	}
	cout << endl;
	return 0;
}
