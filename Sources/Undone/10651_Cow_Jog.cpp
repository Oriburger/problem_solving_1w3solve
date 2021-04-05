#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
typedef vector<int>::iterator VITER;

int n, t, ans=0;
vector<int> s;

vector<int> wasteOfLIS()
{
	vector<int> arr;
	vector<P> track;
	vector<bool> check(s.size(), false);

	arr.push_back(-1);
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

	int temp = arr.size()-1;
	for(int i=track.size(); i>=0; i--)
	{
		if(temp == track[i].first)
		{
			check[i] = true;
			temp-=1;
		}
	}

	vector<int> ret;
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

	s = vector<int>(n);
	for(int i=0; i<n; i++)
	{
		int a, b;
		cin>>a>>b;
		s[i] = a + b*t;
	}
	
	while(!s.empty())
	{
		ans++;
		s = wasteOfLIS();
	}

	cout<<ans<<'\n';

	return 0;
}
