#include <iostream>
#include <queue>
using namespace std;

int n, m, indegree[1001]={0}, result[1001];
vector<vector<int> > adj;
queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	adj.resize(n+1);
	for(int i=0; i<m; i++)
	{
		int k, curr, prev;
		cin>>k;
		if(k==0) continue;

		cin>>prev;
		for(int i=1; i<k; i++) //간선 연결
		{
			cin>>curr;
			indegree[curr]++;
			adj[prev].push_back(curr);
			prev = curr;
		}
	}

	for(int i=1; i<=n; i++)
		if(indegree[i]==0) q.push(i);
	
	for(int i=0; i<n; i++)
	{
		if(q.empty())
		{
			cout<<0<<'\n';
			return 0;
		}

		int curr = q.front();
		q.pop();
		result[i] = curr;

		for(int next : adj[curr])
			if(--indegree[next]==0) q.push(next);
	}

	for(int i=0; i<n; i++)
		cout<<result[i]<<'\n';

	return 0;
}
