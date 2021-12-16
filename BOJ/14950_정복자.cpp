#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{ int cost; int u; int v; };
bool CompEdge(const Edge &e1, const Edge &e2){ return e1.cost < e2.cost; }

struct DisjointSet
{
	vector<int> rank, parent;
	DisjointSet(int n) : parent(n), rank(n, 1)
	{
		for(int i=0; i<n; i++)
			parent[i]=i;
	}

	int find(int u)
	{
		if(parent[u]==u) return u;
		return parent[u]=find(parent[u]);
	}

	void merge(int u, int v)
	{
		u = find(u); v = find(v);
		if(u==v) return;

		if(rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if(rank[u] == rank[v]) rank[v]+=1;
	}
};

int n, m, t;
vector<Edge> edges;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m>>t;

	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		edges.push_back({c, a, b});
	}
	sort(edges.begin(), edges.end(), CompEdge);

	int cnt=0, sum=0, temp=0;
	DisjointSet djs(n+1);
	for(int i=0; i<m; i++)
	{
		int u = edges[i].u;
		int v = edges[i].v;
		int cost = edges[i].cost;

		if(djs.find(u) == djs.find(v)) continue;
		if(cnt == n-1) break;

		cnt++; sum = sum + cost + temp;
		temp += t;
		djs.merge(u, v);
	}
	cout<<sum<<'\n';

	return 0;
}
