#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge { int64_t cost; int u; int v; };

struct DisjointSet
{
	vector<int> parent, rank;
	vector<bool> elec;

	DisjointSet(int n) : parent(n), rank(n, 1), elec(n, false)
	{
		for(int i=0; i<n; i++)
			parent[i]=i;
	}

	int Find(int u)
	{
		if(u==parent[u]) return u;
		return parent[u] = Find(parent[u]);
	}
	
	void Merge(int u, int v)
	{
		u = Find(u); v = Find(v);
		if(u==v) return;

		if(rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if(elec[u] || elec[v])
			elec[parent[u]]=true;
		if(rank[u] == rank[v]) rank[v]+=1;
	}

	bool HasElec(int u)
	{
		u = Find(u);
		return elec[u];
	}
};

bool CompEdge(const Edge &e1, const Edge &e2)
{
	return e1.cost < e2.cost;
}

int n, m, k, ans=0;
vector<Edge> edges;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m>>k;
	
	DisjointSet djs(n+1);
	for(int i=0; i<k; i++)
	{
		int u; cin>>u;
		djs.elec[u]=true;
	}

	for(int i=0; i<m; i++)
	{
		int u, v, cost;
		cin>>u>>v>>cost;
		edges.push_back({cost, u, v});
	}
	sort(edges.begin(), edges.end(), CompEdge);

	for(int i=0; i<edges.size(); i++)
	{
		if(djs.HasElec(edges[i].u) 
			&& djs.HasElec(edges[i].v)) continue;
		if(djs.Find(edges[i].u)==djs.Find(edges[i].v)) continue;

		djs.Merge(edges[i].u, edges[i].v);
		ans+=edges[i].cost;
	}
	cout<<ans<<'\n';

	return 0;
}
