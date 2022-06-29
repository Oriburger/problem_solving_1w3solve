#include <bits/stdc++.h>
using namespace std;

int t;
vector<bool> visited;
vector<vector<int> > adj;

int BFS(int start)
{
	int cnt = 1;
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		
		for(auto &next : adj[curr])
		{
			if(visited[next]) continue;
			visited[next] = true;
			q.push(next); cnt+=1;
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>t;
	while(t--)
	{
		int n, m;
		cin>>n>>m;

		adj = vector<vector<int> >(n);
		visited = vector<bool>(n, false);
		for(int i=0; i<m; i++)
		{
			int u, v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int cnt = BFS(0);
		if(cnt==n) cout<<"Connected.\n";
		else cout<<"Not connected.\n";
	}
	return 0;
}
