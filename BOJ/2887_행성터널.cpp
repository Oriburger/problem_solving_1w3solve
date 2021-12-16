#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos{ int x; int y; int z; int idx; };
struct Edge{ int cost; int u; int v; };

bool CompX(const Pos p1, const Pos p2) { return p1.x < p2.x; }
bool CompY(const Pos p1, const Pos p2) { return p1.y < p2.y; }
bool CompZ(const Pos p1, const Pos p2) { return p1.z < p2.z; }
bool CompEdge(const Edge e1, const Edge e2){ return e1.cost < e2.cost; }

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

int n, answer=0;
vector<Pos> pos;
vector<Edge> edges;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		int x, y, z;
		cin>>x>>y>>z;
		pos.push_back({x, y, z, i});
	}
	
	DisjointSet ds(n);

	sort(pos.begin(), pos.end(), CompX);
	for(int i=0; i<n-1; i++) 
		edges.push_back({abs(pos[i].x-pos[i+1].x), pos[i].idx, pos[i+1].idx});
	sort(pos.begin(), pos.end(), CompY);
	for(int i=0; i<n-1; i++) 
		edges.push_back({abs(pos[i].y-pos[i+1].y), pos[i].idx, pos[i+1].idx});
	sort(pos.begin(), pos.end(), CompZ);
	for(int i=0; i<n-1; i++) 
		edges.push_back({abs(pos[i].z-pos[i+1].z), pos[i].idx, pos[i+1].idx});
	
	sort(edges.begin(), edges.end(), CompEdge);
	int cnt=0;
	for(int i=0; i<edges.size(); i++)
	{
		int u = edges[i].u; int v = edges[i].v;
		if(ds.Find(u)==ds.Find(v)) continue;
		if(cnt==n-1) break;
		
		ds.Merge(u, v);
		answer += edges[i].cost;
		cnt++;
	}
	cout<<answer<<'\n';

	return 0;
}
