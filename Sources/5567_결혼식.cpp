#include <iostream>
#include <vector>
using namespace std;

int n, m, answer;
bool visited[501]; 
vector<vector<int> > adj;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	
	adj.resize(n+1);
	
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin>>a>>b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	visited[1]=true;
	
	for(int i=0; i<adj[1].size(); i++)
	{
		int curr = adj[1][i];
		
		if(!visited[curr])
		{
			visited[curr] = true;
			answer++;
		}
			
		for(int j=0; j<adj[curr].size(); j++)
		{
			if(!visited[ adj[curr][j] ])
			{
				visited[ adj[curr][j] ] = true;
				answer++;
			}
		}
	}
	
	cout<<answer<<'\n';
	
	return 0;
}
