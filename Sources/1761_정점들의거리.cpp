#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

const int MAX_N = 100000;
const int MAX_DEPTH = 18;

vector<vector<int> > parent;
vector<int> depth, dist;
vector<P> adj[MAX_N];

void MakeTree(int curr)
{
	for(const auto &next : adj[curr])
	{
		if(depth[next.first]==-1)
		{
			parent[next.first][0] = curr;
			depth[next.first] = depth[curr] + 1;
			dist[next.first] = dist[curr] + next.second;
			MakeTree(next.first);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin>>n;

	parent.resize(MAX_N, vector<int>(MAX_DEPTH, -1));
	depth.resize(MAX_N, -1);
	dist.resize(MAX_N, 0);
	depth[0]=0;

	for(int i=0; i<n-1; i++)
	{
		int u, v, w;
		cin>>u>>v>>w;

		u-=1; v-=1;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	MakeTree(0);

	for(int j=0; j<MAX_DEPTH-1; j++)
		for(int i=1; i<n; i++)
			if(parent[i][j] != -1)
				parent[i][j+1] = parent[parent[i][j]][j];

	cin>>m;
	for(int i=0; i<m; i++)
	{
		int u, v, u2, v2;
		cin>>u>>v;
		u-=1; v-=1;

		u2 = u, v2 = v;

		if(depth[u] < depth[v]) swap(u, v);
		int diff = depth[u] - depth[v];

		for(int j=0; diff; j++)
		{
			if(diff%2) u = parent[u][j];
			diff/=2;
		}

		if(u != v)
		{
			for(int j=MAX_DEPTH-1; j>=0; j--)
			{
				if(parent[u][j]!=-1 && parent[u][j]!=parent[v][j])
				{
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			u = parent[u][0];
		}
		cout<<dist[u2] + dist[v2] - 2*dist[u]<<'\n';
	}

	return 0;
}
