#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef vector<int>::iterator VITER;

int n;
vector<int> arr, temp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	arr.resize(n);
	for(int i=0; i<n; i++) 
		cin>>arr[i];
	
	temp.push_back(-1);
	for(int i=0; i<n; i++)
	{
		if(temp.back() < arr[i])
			temp.push_back(arr[i]);
		else
		{
			VITER iterPos = lower_bound(temp.begin(), temp.end(), arr[i]);
			*iterPos = arr[i];
		}
	}

	cout<<n-(temp.size()-1)<<'\n';

	return 0;
}
