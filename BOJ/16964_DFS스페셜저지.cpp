#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans = 1, cnt = 1;
vector<vector<int> > adj;
vector<bool> visited;
vector<int> route, order, tmp;

bool comp(int &u, int &v){ return order[u] < order[v]; }

void DFS(int curr)
{
	visited[curr] = true;
	tmp.push_back(curr);
	
	for(auto &next : adj[curr])
	{
		if(visited[next]) continue;
		DFS(next);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	
	adj = vector<vector<int> >(n+1);
	order = route = vector<int>(n, 0);
	visited = vector<bool>(n+1, false);
	
	for(int i=0; i<n-1; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	
	for(int i=0; i<n; i++)
	{
		cin>>route[i];
		route[i]-=1;
		order[route[i]]=i;
	}
	
	for(int i=0; i<n; i++)
		sort(adj[i].begin(), adj[i].end(), comp);
	
	if(route[0]==0)
		DFS(0);
	
	ans = (tmp == route);
	cout<<ans<<'\n';
	
	return 0;
}
