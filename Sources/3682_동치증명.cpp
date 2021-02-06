#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int t, n, m, sccCnt, visitCnt;
const int MAX_N = 20001;
vector<int> adj[MAX_N];
vector<int> sccId, discovered;
vector<int> outdegree, indegree;
vector<bool> finished;
stack<int> stk;

int TarjanDFS(int curr)
{
	stk.push(curr);
	int lowLink = discovered[curr] = ++visitCnt;

	for(auto &next : adj[curr])
	{
		if(finished[next]) continue;
		if(!discovered[next]) 
			lowLink = min(lowLink, TarjanDFS(next));
		else
			lowLink = min(lowLink, discovered[next]);
	}

	if(lowLink == discovered[curr])
	{
		while(1)
		{
			int v = stk.top();
			stk.pop();
			finished[v]=true;
			sccId[v]=sccCnt;

			if(v==curr) break;
		}
		sccCnt+=1;
	}

	return lowLink;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>t;

	while(t--)
	{
		cin>>n>>m;

		sccCnt=0, visitCnt=0;
		sccId.clear();
		sccId.resize(n+1);
		finished.clear();
		finished.resize(n+1, false);
		discovered.clear();
		discovered.resize(n+1);
		indegree.clear();
		indegree.resize(n+1);
		outdegree.clear();
		outdegree.resize(n+1);

		for(int i=1; i<=n; i++)
			adj[i].clear();
		
		for(int i=0; i<m; i++)
		{
			int u, v; cin>>u>>v;
			adj[u].push_back(v);
		}

		for(int i=1; i<=n; i++)
			if(!discovered[i])
				TarjanDFS(i);
	
		
		for(int i=1; i<=n; i++)
		{
			for(int j : adj[i])
			{
				if(sccId[i]!=sccId[j])
				{
					outdegree[sccId[i]]++;
					indegree[sccId[j]]++;
				}
			}
		}

		int incnt=0, outcnt=0;
		for(int i=0; i<sccCnt; i++)
		{
			if(indegree[i]==0) incnt++;
			if(outdegree[i]==0) outcnt++;
		}

		if(sccCnt == 1) cout<<0<<'\n';
		else cout<<max(incnt, outcnt)<<'\n';
	}

	return 0;
}
