#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_V = 10001;

int v, e, k, visitCnt=1, sccCnt=0;
stack<int> stk;
vector<int> adj[MAX_V], discovered;
vector<bool> finished;

int DFS(int curr)
{
	stk.push(curr);
	discovered[curr]=visitCnt++;

	int lowLink = discovered[curr];	
	for(const int &next : adj[curr])	
	{
		if(finished[next]) continue;
		if(discovered[next]==0)	lowLink = min(lowLink, DFS(next));
		else lowLink = min(lowLink, discovered[next]);
	}

	if(lowLink == discovered[curr])
	{
		while(1)
		{
			int t = stk.top();
			stk.pop();
			finished[t]=true;
			if(t==curr) break;
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
		cin>>v>>e;

		discovered.resize(v+1);
		finished.resize(v+1);

		for(int i=0; i<e; i++)
		{
			int u, v;
			cin>>u>>v;
			adj[u].push_back(v);
		}

		for(int i=1; i<=v; i++)
			if(discovered[i]==0)
				DFS(i);

		cout<<sccCnt<<'\n';

		discovered.clear();
		finished.clear();
		for(int i=0; i<MAX_V; i++)
			adj[i].clear();
		sccCnt=0; visitCnt=1;
	}

	return 0;
}
