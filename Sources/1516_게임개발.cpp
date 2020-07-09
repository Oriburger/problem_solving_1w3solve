#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
vector<vector<int> > adj;
vector<int> indegree, result, t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	adj.resize(n+1);
	indegree.resize(n+1);
	result.resize(n+1);
	t.resize(n+1);

	for(int i=1; i<=n; i++)
	{
		cin>>t[i];
		while(1)
		{
			int a; cin>>a;
			if(a==-1) break;
			adj[a].push_back(i);
			indegree[i]++;
		}
	}

	queue<int> q;

	for(int i=1; i<=n; i++)
		if(indegree[i]==0)
		{
			result[i]=t[i];
			q.push(i);
		}

	for(int i=1; i<=n; i++)
	{
		int curr = q.front();
		q.pop();

		for(int next : adj[curr])
		{
			if(--indegree[next]==0) q.push(next);
			result[next]=max(result[next], result[curr]+t[next]);
		}
	}

	for(int i=1; i<=n; i++)
		cout<<result[i]<<'\n';

	return 0;
}
