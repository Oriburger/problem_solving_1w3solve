#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 214700000;
const int MAX_V = 10001;
const int MAX_E = 100001;

int v, e, k, visitCnt=1, sccCnt=0;
stack<int> stk;
vector<int> adj[MAX_V], discovered(MAX_V);
vector<vector<int> > sccArr;
vector<bool> finished(MAX_V);

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

	cin>>v>>e;

	for(int i=0; i<e; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
	}

	for(int i=1; i<=v; i++)
		if(discovered[i]==0)
			DFS(i);

	sort(sccArr.begin(), sccArr.end());

	cout<<sccCnt<<'\n';
	for(int i=0; i<sccCnt; i++)
	{
		for(const int &p : sccArr[i])
			cout<<p<<' ';
		cout<<-1<<"\n";
	}

	return 0;
}
