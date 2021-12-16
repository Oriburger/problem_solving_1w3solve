#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Bt
{
	string name;
	int year;
	int month;
	int day;
};

bool CompAge(const Bt b1, const Bt b2)
{
	if(b1.year > b2.year) return true;
	else if(b1.year < b2.year) return false;
	else
	{
		if(b1.month > b2.month) return true;
		else if(b1.month < b2.month) return false;
		else
		{
			if(b1.day > b2.day) return true;
			else if(b1.day < b2.day) return false;
		}
	}
	return false;
}

int n;
vector<Bt> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;

	for(int i=0; i<n; i++)
	{
		string name;
		int d, m, y;

		cin>>name;
		cin>>d>>m>>y;

		arr.push_back({name, y, m, d});
	}
	sort(arr.begin(), arr.end(), CompAge);

	cout<<arr[0].name<<'\n'<<arr[n-1].name<<'\n';

	return 0;
}
