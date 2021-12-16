#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX_N = 100001;

int n, m, sccCnt, visitCnt;
vector<int> adj[MAX_N], discovered;
vector<int> answer, sccID, indegree;
vector<bool> finished;
stack<int> stk;

int DFS(int curr)
{
	stk.push(curr);
	discovered[curr] = ++visitCnt;
	int lowLink = discovered[curr];

	for(const int &next : adj[curr])
	{
		if(finished[next]) continue;
		if(discovered[next]==0) lowLink = min(lowLink, DFS(next));
		else lowLink = min(lowLink, discovered[next]);
	}

	if(lowLink == discovered[curr])
	{
		while(1)
		{
			int v = stk.top();
			stk.pop();
			sccID[v] = sccCnt;
			finished[v]=true;

			if(v == curr) break;
		}
		sccCnt++;
	}

	return lowLink;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	discovered.resize(MAX_N);
	finished.resize(MAX_N);
	answer.resize(MAX_N);
	sccID.resize(MAX_N);
	indegree.resize(MAX_N);

	cin>>n>>m;

	for(int i=0; i<m; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
	}

	for(int i=0; i<n; i++)
		if(!discovered[i])
			DFS(i);
		
	for(int cur=0; cur<n; cur++)
		for(const int &next : adj[cur])
			if(sccID[cur] != sccID[next])
				indegree[sccID[next]]++;
	int cnt=0;
	for(int i=0; i<sccCnt; i++)
		if(!indegree[i]) cnt++;

	cout<<cnt<<"\n";

	return 0;
}
