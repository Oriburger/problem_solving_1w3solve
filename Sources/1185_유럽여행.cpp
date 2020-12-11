#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

const int MAX_N = 10001;
typedef pair<int, int> P;

struct Edge{ int cost; int u; int v; };
bool CompEdge(const Edge e1, const Edge e2){ return e1.cost < e2.cost; }

int n, m, cnt=0, ans=2141000000;
vector<Edge> edges;
vector<int> cost(MAX_N+1);

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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	for(int i=0; i<n; i++)
	{
		cin>>cost[i];
		ans=min(cost[i], ans);
	}

	for(int i=0; i<m; i++)
	{
		int u, v, c;
		cin>>u>>v>>c;
		edges.push_back({c*2+cost[u-1]+cost[v-1], u-1, v-1});
	}
	sort(edges.begin(), edges.end(), CompEdge);

	DisjointSet djs(n);
	for(int i=0; i<m; i++)
	{
		if(djs.Find(edges[i].u) == djs.Find(edges[i].v)) continue;
		if(cnt==n-1) break;

		djs.Merge(edges[i].u, edges[i].v);
		cnt++; ans+=edges[i].cost;
	}
	
	cout<<ans<<'\n';

	return 0;
}
