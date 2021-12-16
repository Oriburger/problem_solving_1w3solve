#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph
{
private : 
	int v, e, color;
	vector<vector<int> > adj;
	vector<int> visited;
	
public:
	Graph(int _v, int _e) 
		: v(_v), e(_e), color(1)
	{
		adj.resize(0);
		visited.resize(0);
	}

	void Init(int _v, int _e)
	{
		v=_v; e=_e;
		adj.resize(v+1);
		visited.resize(v+1, false);
		color = 1;
	}
	
	void AddEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	bool IsBipartiteGraph()
	{
		for(int i=1; i<=v; i++)
		for(int j=0; j<adj[i].size(); j++)
			if(visited[i] == visited[ adj[i][j] ])
				return false;
				
		return true;
	}
	
	void DFS(int curr)
	{
		if(visited[curr]) return;
		
		visited[curr]=color;
		color=color*-1;
		
		for(int i=0; i<adj[curr].size(); i++)
		{
			int next = adj[curr][i];
			DFS(next);
		}
		
		color=color*-1;
		return;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k, v, e;
	
	cin>>k;
	
	while(k--)
	{
		Graph g(0, 0);	
		
		cin>>v>>e;
		
		g.Init(v, e);
		
		for(int i=0; i<e; i++)
		{
			int a, b;
			cin>>a>>b;
			g.AddEdge(a, b);
		}
		
		for(int i=1; i<=v; i++)
			g.DFS(i);
			
		if(g.IsBipartiteGraph())
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
		
	return 0;
}
