#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> P;
typedef vector<ll>::iterator VITER;

int n, t, ans=0;
bool flag = false;
vector<ll> s;

vector<ll> wasteOfLIS()
{
	vector<ll> arr;
	vector<P> track;
	vector<bool> check(s.size(), false);

	arr.push_back(0);
	for(int i=0; i<s.size(); i++)
	{
		if(arr.back() < s[i])
		{
			arr.push_back(s[i]);
			track.push_back({arr.size()-1, i});
		}
		
		else if(arr.back() > s[i])
		{
			VITER iter = lower_bound(arr.begin(), arr.end(), s[i]);
			*iter = s[i];
			track.push_back({(int)(iter-arr.begin()), i});
		}
	}

	if(arr.size()-1 == 1)
	{
		flag = true;
		return s;
	}

	int temp = arr.size()-1;
	for(int i=track.size(); i>=0; i--)
	{
		if(temp == track[i].first)
		{
			check[i] = true;
			temp-=1;
		}
	}

	vector<ll> ret;
	for(int i=0; i<s.size(); i++)
		if(!check[i]) 
			ret.push_back(s[i]);

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>t;

	s = vector<ll>(n);
	for(int i=0; i<n; i++)
	{
		int a, b;
		cin>>a>>b;
		s[i] = a + b*t + 1;
	}
	
	while(!s.empty())
	{
		ans++;
		s = wasteOfLIS();
		if(flag)
		{
			ans += s.size()-1;
			break;
		}

		break;
	}

	cout<<ans<<'\n';

	return 0;
}
