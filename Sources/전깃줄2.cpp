#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<ll>::iterator viter;
const ll M_INF = LONG_LONG_MIN;
const int MAX = 500001;

int n;
vector<ll> arr, ans;
vector<pair<ll, ll> > s;
vector<pair<int, ll> > track;
vector<bool> check(MAX, false);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	s = vector<pair<ll, ll> >(n);
	arr.push_back(M_INF);

	for(int i=0; i<n; i++)
		cin>>s[i].second>>s[i].first;
	sort(s.begin(), s.end());


	for(int i=0; i<n; i++)
	{
		viter iterPos;

		if(arr.back() < s[i].second)
		{
			arr.push_back(s[i].second);
			track.push_back({arr.size()-1, s[i].second});
		}
		
		else if(arr.back() > s[i].second)
		{
			iterPos = lower_bound(arr.begin(), arr.end(), s[i].second);
			*iterPos = s[i].second;
			track.push_back({(int)(iterPos-arr.begin()), s[i].second});
		}
	}

	int tmp = arr.size()-1;
	for(int i=track.size(); i>=0; i--)
	{
		if(track[i].first == tmp)
		{
			tmp = tmp - 1;
			check[track[i].second]=true;
		}
	}

	cout<<n-(arr.size()-1)<<'\n';
	for(int i=0; i<s.size(); i++)
		if(!check[s[i].second])
			ans.push_back(s[i].second);
	sort(ans.begin(), ans.end());

	for(auto &p : ans)
		cout<<p<<'\n';

	return 0;
}
