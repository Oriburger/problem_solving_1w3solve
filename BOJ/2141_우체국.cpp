#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

int n;
ll total, tmp;
vector<P> town;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		ll x, a; cin>>x>>a;
		town.push_back({x, a});
		total += a;
	}
	sort(town.begin(), town.end());

	for(int i=0; i<n; i++)
	{
		tmp += town[i].second;
		if(tmp >= (total+1)/2)
		{
			cout<<town[i].first<<'\n';
			break;
		}
	}

	return 0;
}
