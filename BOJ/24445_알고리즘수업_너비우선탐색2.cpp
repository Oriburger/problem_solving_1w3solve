/*

BFS의 visited를 integer로 해서 순서를 기록.
그리고 입력을 내림차순으로 소트

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_N 100001
using namespace std;

int n, m, r, cnt = 0;
vector<int> adj[MAX_N];
vector<int> visited(MAX_N, false);
queue<int> q;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m>>r; 
	
	for(int i=0; i<m; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1; i<=n; i++)
		sort(adj[i].begin(), adj[i].end(), greater<int>());
		
	q.push(r);
	visited[r] = ++cnt;
	
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		
		for(auto &next : adj[curr])
		{
			if(visited[next]) continue;
			visited[next] = ++cnt;
			q.push(next);
		}
	}
	
	for(int i=1; i<=n; i++)
		cout<<visited[i]<<'\n';
	
	return 0;
}
