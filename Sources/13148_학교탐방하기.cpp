#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Edge { int cost, u, v; };
bool CompEdge(const Edge &u1, const Edge &u2)
{
	return u1.cost < u2.cost; 
}

bool CompEdgeGreater(const Edge &u1, const Edge &u2)
{
	return u1.cost > u2.cost;  
}

struct DisjointSet
{
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n, 1)
	{		
		for(int i=0; i<n; i++)
			parent[i]=i;
	}

	int find(int u)
	{
		if(u==parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v)
	{
		u = find(u);
		v = find(v);
		if(u==v) return;

		if(rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if(rank[u] == rank[v]) rank[v]+=1;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, worst=0, best=0;
	vector<Edge> edges;

	cin>>n>>m;

	for(int i=0; i<m+1; i++)
	{
		int u, v, c;
		cin>>u>>v>>c;
		edges.push_back({1-c, u, v});
	}

	sort(edges.begin(), edges.end(), CompEdge);

	for(int j=0; j<2; j++)
	{
		int cnt=0;
		DisjointSet djs(n+1);

		for(int i=0; i<m; i++)
		{
			int u = edges[i].u;
			int v = edges[i].v;
			int cost = edges[i].cost;
			
			if(djs.find(u)==djs.find(v)) continue;
			if(cnt == n) break;

			djs.merge(u, v); cnt++;
			if(j==0) best += cost;
			else worst += cost;
		}
		sort(edges.begin(), edges.end(), CompEdgeGreater);
	}

	cout<<abs(pow(best,2)-pow(worst,2))<<'\n';

	return 0;
}
