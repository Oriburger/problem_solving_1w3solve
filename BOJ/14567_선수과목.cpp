#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, cnt=1, total;
vector<vector<int> > adj;
vector<int> indegree, result;
queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>m;
	
	adj.resize(n+1);
	result = indegree = vector<int>(n+1, 0);
	for(int i=0; i<m; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		indegree[v]++;
	}
	
	for(int i=1; i<=n; i++)
		if(!indegree[i])
			q.push(i);
	
	while(total < n)
	{
		queue<int> tmp;
		while(!q.empty())
		{
			int curr = q.front();
			result[curr] = cnt;
			q.pop();
			
			total += 1;			
			for(auto &next : adj[curr])
				if(--indegree[next]==0) 
					tmp.push(next);
		}
		cnt += 1;
		q = tmp;		
	}
	
	for(int i=1; i<=n; i++)
		cout<<result[i]<<' ';
	
	return 0;
}
