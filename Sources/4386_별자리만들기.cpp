#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Pos{ double x; double y; };
double GetDist(const Pos p1, const Pos p2)
{
	return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
}

struct Edge{ double cost; int u; int v; };
bool CompEdge(const Edge e1, const Edge e2){ return e1.cost < e2.cost; };

struct DisjointSet
{
	vector<int> parents, rank;

	DisjointSet(int n):parents(n+1), rank(n+1, 1)
	{
		for(int i=0; i<=n; i++)
			parents[i]=i;
	}

	int Find(int u)
	{
		if(u==parents[u]) return u;
		return parents[u]=Find(parents[u]); //path compression optimization
	}

	void Merge(int u, int v)
	{
		u = Find(u); v = Find(v);
		if(u==v) return;
		if(rank[u]>rank[v]) swap(u, v); //union by rank optimization
		if(rank[u]==rank[v]) rank[v]++;
		parents[u]=v;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, cnt=0;
	double ans=0;
	vector<Pos> pos;

	cin>>n;

	for(int i=0; i<n; i++)
	{
		double x, y;
		cin>>x>>y;
		pos.push_back({x, y});
	}

	DisjointSet djs(n);
	vector<Edge> edges;
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
			edges.push_back({GetDist(pos[i], pos[j]), i, j});
	}

	sort(edges.begin(), edges.end(), CompEdge);
	for(int i=0; i<edges.size(); i++)
	{
		int u = edges[i].u;
		int v = edges[i].v;

		if(djs.Find(u)==djs.Find(v)) continue;
		
		djs.Merge(u, v);
		cnt++; ans+=edges[i].cost;
		if(cnt==n-1) break;
	}
	cout<<ans<<'\n';

	return 0;
}
