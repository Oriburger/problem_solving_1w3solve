#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<ll>::iterator VITER;

int n; ll t;
vector<ll> s, arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>t;

	s = vector<ll>(n);
	for(int i=0; i<n; i++)
	{
		ll a, b;
		cin>>a>>b;
		s[i] = a + b*t;
	}

	for(int i=s.size()-1; i>=0; i--)
	{
		if(arr.empty() || arr.back() <= s[i])
			arr.push_back(s[i]);
		
		else
		{
			VITER iter = upper_bound(arr.begin(), arr.end(), s[i]);
			*iter = s[i];
		}
	}

	cout<<arr.size()<<'\n';

	return 0;
}
