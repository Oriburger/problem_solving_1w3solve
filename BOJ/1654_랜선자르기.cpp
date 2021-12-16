#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int k, n;
	long long longest, arr[10000];
	
	cin>>k>>n;

	for(int i=0; i<k; i++) 
	{
		cin>>arr[i];
		longest = max(longest, arr[i]);
	}

	long long lo=0, hi=longest, mid, answer=0;
	while(lo<=hi)
	{
		mid = (lo+hi)/2;

		long long sum=0;
		for(int i=0; i<k; i++)
			sum+=arr[i]/mid;
		
		if(sum>=n) 
		{
			answer = max(answer, mid);
			lo = mid + 1;
		}

		else 
			hi = mid - 1;
	}

	cout<<answer<<'\n';

	return 0;
}
