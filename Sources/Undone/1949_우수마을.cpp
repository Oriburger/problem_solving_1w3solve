#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 10001;

int n, cache[MAX_N][2];
vector<vector<int> > adj;
vector<bool> visited;
vector<int> ppl; //population

int DFS(int curr, int prev, bool isBest)
{
	int &ret = cache[curr][isBest];

	if(ret != -1) return ret;

	ret = (isBest ? ppl[curr] : 0);
	for(auto &next : adj[curr])
	{
		if(next == prev) continue;
		
		int tmp = 0;
		if(!isBest && cache[next][true] == -1)
			tmp = DFS(next, curr, true);
		
		if(cache[next][false] == -1)
			tmp = max(tmp, DFS(next, curr, false));
		
		ret += tmp;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	
	adj.resize(n+1);
	ppl.resize(n+1, 0);
	memset(cache, -1, sizeof(cache));

	for(int i=1; i<=n; i++)
		cin>>ppl[i];

	for(int i=0; i<n-1; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout<<max(DFS(1, 0, true), DFS(1, 0, false))<<'\n';

	return 0;
}
