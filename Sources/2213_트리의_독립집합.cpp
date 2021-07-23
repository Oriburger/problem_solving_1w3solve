#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX_N = 10001;
typedef pair<int, int> P;

int n, trace[MAX_N];
int cache[MAX_N][2];
vector<vector<int> > adj;
vector<int> w;

int DFS(int curr, int prev, bool isBest)
{
	int &ret = cache[curr][isBest];

	if(ret != -1) return ret;

	ret = (isBest ? w[curr] : 0);
	for(auto &next : adj[curr])
	{
		if(next == prev) continue;
		
		int tmp1 = -1, tmp2 = -1;
		if(!isBest) tmp1 = DFS(next, curr, true);
		tmp2 = DFS(next, curr, false);

		ret += max(tmp1, tmp2);
	}

	return ret;
}

void GetAnswer(int curr, int prev)
{
	if(cache[curr][true] > cache[curr][false] && !trace[prev])
		trace[curr] = true;

	for(auto &next : adj[curr])
	{
		if(next == prev) continue;
		GetAnswer(next, curr);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	
	adj.resize(n+1);
	w.resize(n+1, 0);
	memset(cache, -1, sizeof(cache));

	for(int i=1; i<=n; i++)
		cin>>w[i];

	for(int i=0; i<n-1; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int tmp1, tmp2;
	tmp1 = DFS(1, 0, true);
	tmp2 = DFS(1, 0, false);
	cout<<max(tmp1, tmp2)<<'\n';
	
	GetAnswer(1, 0);
	for(int i=1; i<=n; i++)
		if(trace[i]) cout<<i<<' ';

	return 0;
}
