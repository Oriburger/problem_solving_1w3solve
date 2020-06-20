#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;

class Graph
{
private:
	int n, diameter; //Áö¸§ 
	vector<vector<P> > adj;
	vector<int> visited;
public:
	void Init(int _n)
	{
		n=_n;
		diameter = 0;
		adj.resize(n+1);
		visited.resize(n+1, false);
	}

	void ResetVal()
	{
		visited.clear();
		visited.resize(n+1, false);	
	}
	
	void AddEdge(int u, int v, int cost)
	{
		adj[u].push_back({v, cost});
		adj[v].push_back({u, cost});
	}
	
	void BFS(int start)
	{
		queue<P> q;
		
		q.push({start, 0});
		visited[start] = true;
		
		while(!q.empty())
		{
			P curr = q.front();
			q.pop();
			
			for(auto &p : adj[curr.first])
			{
				if(visited[p.first]) continue;
				
				q.push({p.first, p.second + curr.second});
				visited[p.first] = p.second + curr.second;
				diameter = max(visited[p.first], diameter);
			}
		}
	}
	
	int GetDiameter()
	{
		return diameter;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	Graph g; 
	
	cin>>n;
	
	g.Init(n);
	
	for(int i=0; i<n-1; i++)
	{
		int u, v, val;
		cin>>u>>v>>val;
		g.AddEdge(u, v, val);
	}
	
	for(int i=1; i<=n; i++)
	{
		g.BFS(i);
		g.ResetVal();
	}
	
	cout<<g.GetDiameter()<<'\n';
	
	return 0;
} 
