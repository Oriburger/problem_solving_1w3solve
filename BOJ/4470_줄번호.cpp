#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n; string st;	
vector<string> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	getline(cin, st);
	for(int i=0; i<n; i++)
	{
		getline(cin, st);
		arr.push_back(st);
	}

	for(int i=0; i<n; i++)
		cout<<i+1<<". "<<arr[i]<<'\n';

	return 0;
}
