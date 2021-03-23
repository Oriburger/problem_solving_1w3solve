#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int INF = 2147000000;

struct DisjointSet
{
	int n;

	vector<int> parent, weight;
	DisjointSet(int n) : n(n), parent(n), weight(n, INF)
	{
		for(int i=0; i<n; i++)
			parent[i]=i;
	}

	int find(int u)
	{
		if(u==parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	bool merge(int u, int v)
	{
		u = find(u); v = find(v);
		if(u==v) return false;

		if(weight[u] > weight[v])

		parent[u] = v;
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

			cin>>sel>>a>>b;

			if(sel=='!')
			{
				cin>>w;

		

				djs.merge(a, b);
			}
			else
			{

			}
		}
	}

	return 0;
}
