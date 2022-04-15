#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, l;
vector<string> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>l;
	arr = vector<string>(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];
		
	sort(arr.begin(), arr.end());
	
	cout<<arr[l-1]<<'\n';
	
	return 0;
}
