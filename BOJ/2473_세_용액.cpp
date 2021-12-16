#include <bits/stdc++.h>
using namespace std;

long long n, min_diff = 3000000001;
vector<long long> arr, ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	
	arr = vector<long long>(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];

	sort(arr.begin(), arr.end());

	for(int lo = 0; lo < arr.size()-2; lo++)
	{
		int mid = lo+1;
		int hi = arr.size()-1;

		while(mid < hi)
		{
			long long temp = arr[lo]+arr[mid]+arr[hi];

			if(abs(temp) < min_diff)
			{
				min_diff = abs(temp);
				ans = {arr[lo], arr[mid], arr[hi]};
			}
			if(temp < 0) mid++;
			else if(temp > 0) hi--;
			else break;
		}
	}
	
	cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<'\n';

	return 0;
}
