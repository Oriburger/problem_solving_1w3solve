#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX_N = 100001;

int n, m, sccCnt=0, visitCnt=0;
vector<int> adj[MAX_N], discovered(MAX_N);
vector<int> sccID(MAX_N), indegree(MAX_N);
vector<bool> finished(MAX_N);
stack<int> stk;

int TarjanDFS(int curr)
{
	stk.push(curr);
	discovered[curr] = ++visitCnt;
	int lowLink = discovered[curr];

	for(const int &next : adj[curr])
	{
		if(finished[next]) continue;
		if(discovered[next]==0) lowLink = min(lowLink, TarjanDFS(next));
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
		
	cin>>n>>m;

	for(int i=0; i<m; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u-1].push_back(v-1);
	}

	for(int i=0; i<n; i++)
		if(!discovered[i])
			TarjanDFS(i);
		
	for(int cur=0; cur<n; cur++)
		for(const int &next : adj[cur])
			if(sccID[cur] != sccID[next])
				indegree[sccID[next]]++;

	int cnt=0;
	for(int i=0; i<sccCnt; i++)
		if(!indegree[i])
			cnt++;

	cout<<cnt<<'\n';

	return 0;
}
