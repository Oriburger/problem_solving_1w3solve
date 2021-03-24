#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int INF = 2147000000;

struct DisjointSet
{
	int n;

	vector<int> parent, dist;
	DisjointSet(int n) : n(n), parent(n), dist(n, 0)
	{
		for(int i=0; i<n; i++)
			parent[i]=i;
	}

	int find(int u)
	{
		if(u==parent[u]) return u;

		int p = find(parent[u]);
		dist[u] += dist[parent[u]];
		return parent[u] = p;
	}

	bool merge(int u, int v, int w)
	{
		int rootu = find(u);
		int rootv = find(v);

		if(rootu == rootv) return false;

		dist[rootv] = dist[u] - dist[v] + w;
		parent[rootv] = rootu;
		return true;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1)
	{
		int n, m;
		cin>>n>>m;

		if(!n && !m) break;

		DisjointSet djs(n);
		for(int i=0; i<m; i++)
		{
			char sel;
			int a, b, w;

			cin>>sel;

			if(sel=='!')
			{
				cin>>a>>b>>w;
				djs.merge(a-1, b-1, w);
			}
			else
			{
				cin>>a>>b;
				if(djs.find(a-1)!=djs.find(b-1)) cout<<"UNKNOWN\n";
				else cout<<djs.dist[b-1]-djs.dist[a-1]<<'\n'; 
			}
		}
	}

	return 0;
}
