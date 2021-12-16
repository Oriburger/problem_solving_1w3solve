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

	for(int i=0; i<n; i++)
	{
		int input;
		cin>>input;
		arr.push_back(input);
	}

	bool flag = next_permutation(arr.begin(), arr.end(), greater<int>());

	if(flag)
		for(int i=0; i<n; i++)
			cout<<arr[i]<<' ';

	else
		cout<<-1<<'\n';

	return 0;
}
