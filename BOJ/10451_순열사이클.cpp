#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adj;
vector<bool> visited;

void DFS(int curr)
{
	visited[curr] = true;
	
	for(auto &next : adj[curr])
	{
		if(visited[next]) continue;
		DFS(next);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; 
	cin>>t;
	
	while(t--)
	{
		int n, ans = 0;
		cin>>n;
		
		adj = vector<vector<int> >(n+1);
		visited = vector<bool>(n+1, false);
		for(int u=1; u<=n; u++)
		{
			int v; cin>>v;
			adj[u].push_back(v);
		}
		
		for(int u=1; u<=n; u++)
		{
			if(visited[u]) continue;
			DFS(u); ans++;
		}
		
		cout<<ans<<'\n';
	}
	
	return 0;
}
