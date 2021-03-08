#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 18;
vector<vector<int> > parent;
vector<int> depth, adj[100000];

void MakeTree(int curr)
{
	for(int next : adj[curr])
	{
		if(depth[next]==-1)
		{
			parent[next][0] = curr;
			depth[next] = depth[curr] + 1;
			MakeTree(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;

	cin>>n;

	for(int i=0; i<n-1; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	parent.resize(100000, vector<int>(MAX, -1));
	depth.resize(100000, -1);
	depth[0] = 0;

	MakeTree(0);

	for(int j=0; j<18-1; j++)
		for(int i=1; i<n; i++)
			if(parent[i][j] != -1)
				parent[i][j+1] = parent[parent[i][j]][j];
		
	cin>>m;
	for(int i=0; i<m; i++)
	{
		int u, v;
		cin>>u>>v;

		u--; v--;

		if(depth[u] < depth[v]) swap(u, v);
		int diff = depth[u] - depth[v];

		for(int j=0; diff; j++)
		{
			if(diff%2) u = parent[u][j];
			diff/=2;
		}

		if(u!=v)
		{
			for(int j=MAX-1; j>=0; j--)
				if(parent[u][j]!=-1 && parent[u][j]!= parent[v][j])
				{
					u = parent[u][j];
					v = parent[v][j];
				}
			u = parent[u][0];
		}

		cout<<u+1<<'\n';
	}
	return 0;
}
