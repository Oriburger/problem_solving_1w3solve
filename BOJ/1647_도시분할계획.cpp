#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge { int cost; int u; int v; };

bool EdgeComp(const Edge e1, const Edge e2){ return e1.cost < e2.cost; }

struct DisjointSet
{
	vector<int> parent, rank;
	
	DisjointSet(int n) : parent(n+1), rank(n+1, 1)
	{
		for(int i=0; i<=n; i++)
			parent[i]=i;
	}

	int Find(int u)
	{
		if(parent[u]==u) return u;

		return parent[u]=Find(parent[u]);
	}

	void Merge(int u, int v)
	{
		u = Find(u); v = Find(v);

		if(u==v) return;

		if(rank[u]>rank[v]) swap(u, v);
		if(rank[u]==rank[v]) rank[v]++;
		
		parent[u]=v;
	}
};

int n, m, answer=0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;

	DisjointSet ds(n);
	vector<Edge> edges;

	for(int i=0; i<m; i++)
	{
		int c, a, b;
		cin>>a>>b>>c;

		edges.push_back({c, a, b});
	}
	sort(edges.begin(), edges.end(), EdgeComp);
	
	int cnt=0;
	for(int i=0; i<m; i++)
	{
		int a = edges[i].u;
		int b = edges[i].v;

		if(ds.Find(a)==ds.Find(b)) continue;
		if(cnt==n-2) break;

		ds.Merge(a, b); cnt++;
		answer+=edges[i].cost;
	}

	cout<<answer<<'\n';

	return 0;
}
