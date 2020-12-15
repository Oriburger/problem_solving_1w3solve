#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

struct Edge{ ull cost; int u; int v; }; 

bool CompEdge(Edge a, Edge b){ return a.cost < b.cost; }

struct DisjointSet
{
	vector<int> parents, ranks;

	DisjointSet(int n) : parents(n), ranks(n, 1)
	{
		for(int i=0; i<n; i++)
			parents[i]=i;
	}

	int find(int u)
	{
		if(parents[u]==u) return u;
		return parents[u]=find(parents[u]);
	}

	void merge(int u, int v)
	{
		u = find(u); v = find(v);
		if(u==v) return;

		if(ranks[u] > ranks[v]) swap(u, v);
		parents[u] = v;
		if(ranks[u]==ranks[v]) ranks[v]++;
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	int totalCost=0, cnt=0;
	ull k;

	cin>>n>>m; cin>>k;

	//vector<int> s(n+1);
	vector<Edge> edges;
	DisjointSet djs(n+1);
	vector<bool> isConnect(n+1, true); 
	//isConnect[1] : 1-2 연결여부, isConnect[n] : n-1 연결여부

	for(int i=0; i<n; i++)
	{
		int s; cin>>s;
		edges.push_back({(ull)s, 0, i+1}); //0은 와우도이다.
	}

	for(int i=0; i<m; i++)
	{
		int a, b;
		cin>>a>>b;
		if(a>b && a!=n) swap(a,b);
		isConnect[a]=false;
	}

	for(int i=1; i<=n; i++)
	{
		if(isConnect[i])
		{
			int next = (i==n ? 1 : i+1);
			djs.merge(i, next);
			cnt++;
		}
	}
	if(cnt>=n-1)
	{
		cout<<"YES\n";
		return 0;
	}

	sort(edges.begin(), edges.end(), CompEdge);

	for(int i=0; i<edges.size(); i++)
	{
		int u = edges[i].u;
		int v = edges[i].v;
		int cost = edges[i].cost;

		if(djs.find(u)==djs.find(v)) continue;
		if(cnt==n || totalCost>k) break;
		
		totalCost+=cost; cnt++;
		djs.merge(u, v);
	//	cout<<'('<<u<<','<<v<<')'<<" merge ,"<<totalCost<<'\n';
	}

	//cout<<totalCost<<','<<cnt<<'\n';
	if(totalCost<=k && cnt==n) cout<<"YES\n";
	else cout<<"NO\n"; 

	return 0;
}
