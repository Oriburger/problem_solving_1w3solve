#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, r, q;
vector<vector<int> > adj;
vector<int> cache;

int DFS(int curr)
{
	int &ret = cache[curr];
	if(ret!=0) return ret;

	ret = 1;
	for(auto &next : adj[curr])
	{
		if(cache[next]) continue;
		ret += DFS(next);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>r>>q;

	adj.resize(n+1);
	cache.resize(n+1, 0);
	for(int i=0; i<n-1; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	DFS(r);
	for(int i=0; i<q; i++)
	{
		int u; cin>>u;
		cout<<DFS(u)<<'\n';
	}

	return 0;
}
