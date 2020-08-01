#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> P;

int v;
vector<vector<P> > adj;

void BFS(int start)
{
	queue<int> q;
	vector<bool> visited(v+1, false);

	q.push(start);
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>v;

	adj.resize(v+1);
	for(int i=0; i<v; i++)
	{
		int u, v, cost;
		cin>>u;
		
		while(1)
		{
			cin>>v;
			if(v==-1) break;

			cin>>cost;

			adj[u].push_back({v, cost});
			adj[v].push_back({u, cost});
		}
	}



	return 0;
}
