#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge { int cost; int u; int v; };

bool CompEdge(const Edge e1, const Edge e2)
{
	return e1.cost < e2.cost;
}

struct DisjointSet
{
	vector<int> parents, rank;

	DisjointSet(int n) : parents(n+1), rank(n+1, 1)
	{
		for(int i=0; i<=n; i++)
			parents[i]=i;
	}

	int Find(int u)
	{
		if(u==parents[u]) return u;
		//path compression optimazation
		return parents[u] = Find(parents[u]); 
	}

	void Merge(int u, int v)
	{
		u = Find(u); v = Find(v);
		if(u==v) return; 
		//union by rank optimazation
		if(rank[u]>rank[v]) swap(u, v); 
		if(rank[u]==rank[v]) rank[v]++;
		parents[u]=v;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1)
	{
		int m, n;
		int total=0; //total cost
		vector<Edge> edges;
		cin>>m>>n;
		
		if(m==0 && n==0) break;

		for(int i=0; i<n; i++)
		{
			int x, y, z;
			cin>>x>>y>>z;
			total+=z;
			edges.push_back({z, x, y});
		}
		sort(edges.begin(), edges.end(), CompEdge);

		int cnt=0, ans=0;
		DisjointSet djs(m);
		for(int i=0; i<n; i++)
		{
			int u = edges[i].u, v = edges[i].v;
			if(djs.Find(u) == djs.Find(v)) continue;

			djs.Merge(u, v);
			cnt++; ans+=edges[i].cost;
			if(cnt==m-1) break;
		}

		cout<<total-ans<<'\n';
	}

	return 0;
}
