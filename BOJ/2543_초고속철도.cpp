#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int INF = 20070713;

int n;
vector<P> pos;
vector<int> cache;

int GetAnswer(int curr)
{
	if(curr==n) return 1;
	int &ret = cache[curr];
	if(ret != -1) return ret;

	ret = GetAnswer(curr+1)%INF;
	int next = upper_bound(pos.begin()+curr, pos.end(), P(pos[curr].second, -1))-pos.begin();
	ret = (ret + GetAnswer(next))%INF;

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	
	cache = vector<int>(n, -1);
	for(int i=0; i<n; i++)
	{
		int l, r; cin>>l>>r;
		pos.push_back({l, r});
	}
	sort(pos.begin(), pos.end());

	cout<<GetAnswer(0)<<'\n';

	return 0;
}
