#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
const int MAX_N = 10001;
vector<int> indegree, cost;
vector<int> answer, adj[MAX_N];
queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	indegree.resize(n+1, 0);
	cost.resize(n+1, 0);
	answer.resize(n+1, 0);

	for(int i=1; i<=n; i++)
	{	
		int a; //선행 작업 개수
		cin>>cost[i]>>indegree[i];

		//indegree가 0인 정점push
		if(indegree[i]==0) 
		{
			answer[i]=cost[i];
			q.push(i);
		}

		for(int j=0; j<indegree[i]; j++)
		{
			int v; cin>>v;
			adj[v].push_back(i);
		}
	}

	for(int i=1; i<=n; i++)
	{
		int curr = q.front();
		q.pop();
		for(int next : adj[curr])
		{
			answer[next] = max(answer[next], answer[curr]+cost[next]);
			if(--indegree[next]==0) q.push(next);
		}
	}

	int ans=0;
	for(int i=1; i<=n; i++)
		ans=max(ans, answer[i]);

	cout<<ans<<'\n';

	return 0;
}
