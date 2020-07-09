#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;

	cin>>t;

	while(t--)
	{
		int n, k, w; cin>>n>>k;
		vector<vector<int> > adj(n+1);
		vector<int> indegree(n+1);
		vector<int> result(n+1), timeArr(n+1);

		for(int i=1; i<=n; i++)
			cin>>timeArr[i];
		
		for(int i=1; i<=k; i++)
		{
			int x, y; cin>>x>>y;
			adj[x].push_back(y);
			indegree[y]++;
		}
		cin>>w;

		queue<int> q;

		for(int i=1; i<=n; i++)
			if(indegree[i]==0)
			{
				q.push(i);
				result[i]=timeArr[i];
			}

		for(int i=1; i<=n; i++)
		{
			int curr = q.front();
			q.pop();

			for(int next : adj[curr])
			{
				if(--indegree[next]==0) q.push(next);
				result[next] = max(result[next], result[curr]+timeArr[next]);
			}
		}
		cout<<result[w]<<'\n';
	}

	return 0;
}
