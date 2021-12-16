#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge { long long cost; int u; int v; };

struct DisjointSet
{
	vector<int> parent, rank;

	DisjointSet(int n) : parent(n), rank(n, 1)
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
		if(rank[u] == rank[v]) rank[v]+=1;
	}
};

bool CompEdge(const Edge &e1, const Edge &e2)
{
	return e1.cost < e2.cost;
}

int n;
long long c;
vector<Edge> edges;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>c;
			if(i>=j) continue;
			edges.push_back({c, i, j});
		}
	}
	sort(edges.begin(), edges.end(), CompEdge);

	int cnt=0;
	long long ans=0;
	DisjointSet djs(n);
	for(int i=0; i<edges.size(); i++)
	{
		if(djs.Find(edges[i].u)==djs.Find(edges[i].v)) continue;
		if(cnt==n-1) break;

		djs.Merge(edges[i].u, edges[i].v);
		cnt++; ans+=edges[i].cost;
	}
	cout<<ans<<'\n';

	return 0;
}
