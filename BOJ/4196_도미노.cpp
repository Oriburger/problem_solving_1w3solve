#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX_N = 101000;

int n, m, visitCnt=0, sccCnt=0, answer=0;
vector<int> adj[MAX_N];
vector<bool> finished;
vector<int> sccID, discovered, indegree;
stack<int> stk;

int DFS(int curr)
{
	stk.push(curr);
	int lowLink = discovered[curr] = ++visitCnt;

	for(const int &next : adj[curr])
	{
		if(finished[next]) continue;
		if(discovered[next]==0)
			lowLink = min(lowLink, DFS(next));
		else 
			lowLink = min(lowLink, discovered[next]);
	}

	if(lowLink == discovered[curr])
	{
		while(1)
		{
			int v = stk.top();
			stk.pop();
			sccID[v]=sccCnt;
			finished[v]=true;
			
			if(v==curr) break;
		}
		sccCnt++;
	}
	return lowLink;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin>>t;

	while(t--)
	{
		cin>>n>>m;

		/* init container */
		answer=0, sccCnt=0, visitCnt=0;
		for(int i=0; i<MAX_N; i++)
			adj[i].clear();
		sccID.resize(MAX_N, -1);
		finished.resize(MAX_N, false);
		discovered.resize(MAX_N, 0);
		indegree.resize(MAX_N, 0);

		/* main code */
		for(int i=0; i<m; i++)
		{
			int u, v; 
			cin>>u>>v;
			adj[u].push_back(v);
		}
		for(int i=1; i<=n; i++)
			if(discovered[i]==0) DFS(i);
			
		for(int cur=1; cur<=n; cur++)
			for(const int &next : adj[cur])
				if(sccID[cur]!=sccID[next])
					indegree[sccID[next]]++;
	
		for(int i=0; i<sccCnt; i++)
			if(indegree[i]==0)
				answer++;
		
		cout<<answer<<'\n';	

		sccID.clear();
		finished.clear();
		discovered.clear();
		indegree.clear();
	}

	return 0;
}
