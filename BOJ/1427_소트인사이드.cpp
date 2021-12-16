#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	while(n!=0)
	{
		arr.push_back(n%10);
		n/=10;
	}
	sort(arr.begin(), arr.end(), greater<int>());
	
	for(int i=0; i<arr.size(); i++)
		cout<<arr[i];
	
	return 0;
}
