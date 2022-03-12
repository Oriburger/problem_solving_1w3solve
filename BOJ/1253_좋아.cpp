#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll n, ans;
vector<ll> arr; 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	
	arr = vector<ll>(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];
		
	sort(arr.begin(), arr.end());
	
	for(int i=0; i<n; i++)
	{
		int p = 0, q = n-1;
		while(p < q)
		{
			if(p==i || q==i)
			{
				p += (p==i);
				q -= (q==i);
				continue;
			}
			
			ll sum = arr[p] + arr[q];
			if(sum == arr[i])
			{
				ans += 1;
				break;
			}
			else if(sum < arr[i]) p++;
			else q--;
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}
