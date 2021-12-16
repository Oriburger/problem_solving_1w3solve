#include <iostream>
using namespace std;

int n, m, arr[10000], maxBudget;

int GetAnswer()
{
	int lo = 0, hi = maxBudget, mid, ret;

	while(lo<=hi)
	{
		mid = (lo+hi)/2;

		long long sum=0;
		for(int i=0; i<n; i++)
			sum += min(mid, arr[i]);
		
		if(sum<=m)
		{
			ret = mid;
			lo = mid+1;
		}
		else hi = mid-1;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		maxBudget = max(maxBudget, arr[i]);
	}

	cin>>m;

	cout<<GetAnswer()<<'\n';

	return 0;
}
