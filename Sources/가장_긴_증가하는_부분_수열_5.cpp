#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, ll> P;
typedef vector<ll>::iterator viter;
const ll M_INF = LONG_LONG_MIN;

int n;
vector<ll> s, arr, ans;
vector<P> track;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	s = vector<ll>(n);
	arr.push_back(M_INF);

	for(int i=0; i<n; i++)
		cin>>s[i];

	for(int i=0; i<n; i++)
	{
		viter iterPos;

		if(arr.back() < s[i])
		{
			arr.push_back(s[i]);
			track.push_back({arr.size()-1, s[i]});
		}
		
		else if(arr.back() > s[i])
		{
			iterPos = lower_bound(arr.begin(), arr.end(), s[i]);
			*iterPos = s[i];
			track.push_back({(int)(iterPos-arr.begin()), s[i]});
		}
	}

	int tmp = arr.size()-1;
	for(int i=track.size(); i>=0; i--)
	{
		if(track[i].first == tmp)
		{
			tmp = tmp - 1;
			ans.push_back(track[i].second);
		}
	}

	cout<<arr.size()-1<<'\n';
	for(int i=ans.size()-1; i>=0; i--)
		cout<<ans[i]<<' ';

	return 0;
}
