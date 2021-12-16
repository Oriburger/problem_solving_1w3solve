#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int v;
vector<vector<P> > adj;

P BFS(int start) 
{
	queue<P> q;
	int	retDist=0, retIdx=0;
	vector<bool> visited(v+1, false);

	q.push({start, 0});
	visited[start]=true;

	while(!q.empty())
	{
		int curr = q.front().first; //{curr, cost};
		int curDist = q.front().second;
		q.pop();
		
		for(int i=0; i<adj[curr].size(); i++)
		{
			int next = adj[curr][i].first;
			int nextDist = adj[curr][i].second + curDist;

			if(visited[next]) continue;

			if(retDist < nextDist)
			{
				retDist = nextDist;
				retIdx = next;
			}
			
			q.push({next, nextDist});
			visited[next]=true;
		}
	}

	//가장 먼 노드의 idx와 거리가 반환된다. 
	return {retIdx, retDist};
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
	
	//임의의 노드 1에서 가장 먼 노드에서
	//BFS를 돌려 트리의 지름을 알아낸다. 
	cout<<BFS(BFS(1).first).second<<'\n'; 

	return 0;
}
