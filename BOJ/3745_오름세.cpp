#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	vector<int> arr, cache;

	while(cin>>n)
	{
		arr.resize(n);
		cache.push_back(-1);
		for(int i=0; i<n; i++) 
			cin>>arr[i];

		for(int i=0; i<n; i++)
		{
			if(cache.back() < arr[i])
				cache.push_back(arr[i]);
			
			else
			{
				vector<int>::iterator ipos;
				ipos = lower_bound(cache.begin(), cache.end(), arr[i]);
				*ipos = arr[i];
			}
		}

		cout<<cache.size()-1<<'\n';

		arr.clear();
		cache.clear();
	}

	return 0;
}
