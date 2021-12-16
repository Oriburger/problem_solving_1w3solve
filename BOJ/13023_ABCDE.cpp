#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m; bool flag=false;
vector<vector<int> > adj;
vector<bool> visited;

void DFS(int curr, int cnt)
{
	if(cnt==5)
	{	
		flag = true;
		return;
	}
	if(flag) return;

	visited[curr]=true;

	for(int next : adj[curr])
		if(!visited[next]) DFS(next, cnt+1);

	visited[curr]=false;

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	adj.resize(n);

	for(int i=0; i<m; i++)
	{
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i=0; i<n; i++)
	{
		visited.resize(n, false);
		DFS(i, 1);
		if(flag)
		{
			cout<<1<<'\n';
			return 0;
		}
		visited.clear();
	}
	cout<<0<<'\n';

	return 0;
}
