#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{ int cost, u, v; };

struct DisjointSet
{
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n, 0)
	{
		for(int i=0; i<n; i++)
			parent[i]=i;
	}

	int find(int u)
	{
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v)
	{
		u=find(u); v=find(v);
		if(u==v) return;

		if(rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if(rank[u] == rank[v]) rank[v]+=1;
	}
};

int n, m, k, cnt, sum;
vector<Edge> edges;
vector<int> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m>>k;

	ans.resize(k, 0);
	for(int i=0; i<m; i++)
	{
		int u, v;
		cin>>u>>v;
		edges.push_back({i+1, u, v});
	}

	for(int i=1; i<=k; i++)
	{
		cnt = sum = 0;

		DisjointSet djs(n+1);
		for(Edge &p : edges)
		{
			if(djs.find(p.u)==djs.find(p.v)) continue;

			djs.merge(p.u, p.v);
			cnt++; sum += p.cost;
			
			if(cnt == n-1) break;
		}
		if(cnt != n-1) break;

		edges.erase(edges.begin());
		ans[i-1]=sum;
	}

	for(auto &p : ans)
		cout<<p<<' ';

	return 0;
}
