#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 2147000000;

struct DisjointSet
{
	vector<int> rank, parent, min_cost;
	
	DisjointSet(int n, vector<int> c)
		 : parent(n+1), rank(n+1, 1), min_cost(n)
	{
		min_cost = c;
		for(int i=1; i<=n; i++)
			parent[i]=i;
	}
	
	int find(int u)
	{
		if(u==parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	
	void merge(int u, int v, int u_cost, int v_cost)
	{
		u = find(u);
		v = find(v);
		if(u == v) return; 
		if(rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		min_cost[v] = min(min_cost[u], min_cost[v]);
		min_cost[v] = min(min_cost[v], min(u_cost, v_cost));
		if(rank[u]==rank[v]) rank[v]++;
	}
	
	int GetMinCost(int u)
	{
		u = find(u);
		return min_cost[u];
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m, k, total=0;
	vector<int> cost;
	
	cin>>n>>m>>k;
	
	cost = vector<int>(n+1);
	for(int i=1; i<=n; i++)
		cin>>cost[i];
	
	DisjointSet djs(n, cost);
	
	for(int i=0; i<m; i++)
	{
		int u, v; 
		cin>>u>>v;
		djs.merge(u, v, cost[u], cost[v]);
	}
	
	vector<bool> visited(n+1, false);
	for(int u=1; u<=n; u++)
	{
		if(visited[djs.find(u)]) continue;
		total += djs.GetMinCost(u);
		visited[djs.find(u)] = true;
	}
	
	if(total > k) cout<<"Oh no\n";
	else cout<<total<<'\n';

	return 0;
}
