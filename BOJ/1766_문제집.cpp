#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<vector<int> > adj;
vector<int> indegree, result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	adj.resize(n+1);
	indegree.resize(n+1);
	result.resize(n+1);

	for(int i=0; i<m; i++)
	{
		int a, b; cin>>a>>b;

		adj[a].push_back(b);
		indegree[b]++;
	}

	priority_queue<int, vector<int>, greater<int> > pq;

	for(int i=1; i<=n; i++)
		if(indegree[i]==0) pq.push(i);

	for(int i=1; i<=n; i++)
	{
		int curr = pq.top();
		pq.pop();

		cout<<curr<<' ';

		for(int next : adj[curr])
			if(--indegree[next]==0) pq.push(next);
	}

	return 0;
}
