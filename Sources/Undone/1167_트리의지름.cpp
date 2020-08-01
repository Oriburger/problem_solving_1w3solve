#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int v, answer=0;
vector<vector<P> > adj;
vector<int> indegree, st;

int BFS(int start)
{
	queue<P> q;
	int	ret=0;
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

			//cout<<next<<" visited, dist : "<<nextDist<<'\n';

			ret = max(ret, nextDist);
			q.push({next, nextDist});
			visited[next]=true;
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>v;

	adj.resize(v+1);
	indegree.resize(v+1, 0);
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

			indegree[u]++;
			indegree[v]++;
		}
	}
	int minVal = 1000000;
	for(int i=1; i<=v; i++)
	{
		if(minVal > indegree[i])
		{
			minVal = indegree[i];
			st.clear();
			st.push_back(i);
		}
		else if(minVal == indegree[i])
			st.push_back(i);
	}
	
	for(auto p : st)
		answer = max(answer, BFS(p));

	cout<<answer<<'\n';

	return 0;
}
