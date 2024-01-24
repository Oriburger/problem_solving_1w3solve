#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
ll ans = 0;
vector<ll> dist, price;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	dist = vector<ll>(n-1);
	price = vector<ll>(n);
	
	for(int i=0; i<n-1; i++)
		cin>>dist[i];
	for(int i=0; i<n; i++)
		cin>>price[i];
		
	for(int i=0; i<n; i++)
	{
		int sum = 0;
		for(int j=i+1; j<n; j++)
		{
			sum += dist[j-1];
			if(price[i] > price[j] || j==n-1)
			{
				ans += sum * price[i];
				i = j-1;
				break;
			}
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}
