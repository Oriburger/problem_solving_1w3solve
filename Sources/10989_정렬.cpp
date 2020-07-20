#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
	vector<int> arr(10001, 0);

	for(int i=0; i<n; i++)
	{
		int input; cin>>input;
		arr[input]++;
	}

	for(int i=1; i<10001; i++)
	{
		while(arr[i]!=0)
		{
			cout<<i<<'\n';
			arr[i]--;
		}	
	}

	return 0;
}
