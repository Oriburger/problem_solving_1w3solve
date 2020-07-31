#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> arr(5, 0);
	int mean=0;

	for(int i=0; i<5; i++)
	{
		cin>>arr[i];
		mean+=arr[i];
	}
		
	
	sort(arr.begin(), arr.end());

	cout<<mean/5<<'\n'<<arr[2]<<'\n';

	return 0;
}
