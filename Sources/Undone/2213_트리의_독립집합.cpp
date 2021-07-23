#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX_N = 10001;
//typedef pair<int, int> P;

int n, cache[MAX_N][2];
//P trace[MAX_N][2];
vector<vector<int> > adj;
vector<int> ans, w;

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

		//trace[curr][isBest] = {next, (tmp1 < tmp2)}; 	
		ret += max(tmp1, tmp2);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	
	adj.resize(n+1);
	w.resize(n+1, 0);
	memset(cache, -1, sizeof(cache));
	//memset(trace, 0, sizeof(trace));

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
	
	//int pa = 1, pb = (tmp1 > tmp2);

	for(int i=1; i<=n; i++)
	{
		if(cache[i][true] > cache[i][false])
			cout<<i<<' ';
		//P next = trace[pa][pb];

		//if(next.seoc) cout<<next.second<<' ';

		//pa = next.first;
		//pb = next.second;
	}

	return 0;
}
