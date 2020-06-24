#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, answer;
vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	for(int i=1; i<=n; i++)
	{
		int input;
		cin>>input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end());

	do
	{
		int val=0;

		for(int i=0; i<n-1; i++)
			val += abs((arr[i]-arr[i+1]));
		
		answer=max(answer, val);
	}while(next_permutation(arr.begin(), arr.end()));

	cout<<answer<<'\n';

	return 0;
}
