#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int n, ans = 0;
vector<P> conf;

bool comp(const P& a, const P& b)
{
	if(a.second != b.second) return a.second < b.second; 
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	for(int i=0; i<n; i++)
	{
		int a, b; cin>>a>>b;
		conf.push_back({a, b});
	}
	sort(conf.begin(), conf.end(), comp);

	int temp = 0;
	for(int i=0; i<n; i++)
		if(temp <= conf[i].first)
		{
			temp = conf[i].second;
			ans+=1;
		}

	cout<<ans<<'\n';

	return 0;
}
