#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 214700000;
const int MAX_N = 1001;

int n, k, visitCnt=1, sccCnt=0;
stack<int> stk;
vector<int> adj[MAX_N], discovered(MAX_N);
vector<int> sccID(MAX_N);
vector<vector<int> > sccArr;
vector<bool> finished(MAX_N);
vector<int> indegree;

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
		vector<int> scc;
		while(1)
		{
			int t = stk.top();
			scc.push_back(t);
			stk.pop();
			sccID[t]=sccCnt;
			finished[t]=true;
			if(t==curr) break;
		}
		sort(scc.begin(), scc.end());
		sccArr.push_back(scc);
		sccCnt++;
	}
	return lowLink;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>k;

	for(int i=1; i<=n; i++)
	{
		int x; cin>>x;
		adj[i].push_back(x);
	}

	for(int i=1; i<=n; i++)
		if(!discovered[i]) DFS(i);
	
	indegree.resize(sccCnt, 0);

	for(int curr=1; curr<=n; curr++)
		for(auto &next : adj[curr])
			if(sccID[curr] != sccID[next])
				indegree[sccID[next]]++;
	
	for(int i=0; i<sccCnt; i++)
		if(indegree[i]==0)
		{
			
		}	

	return 0;
}
