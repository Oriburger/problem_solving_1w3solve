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

void Init()
{
		sccCnt=0, visitCnt=0;
		for(int i=0; i<MAX_N; i++)adj[i].clear();
		discovered.clear();
		discovered.resize(MAX_N);
		finished.clear();
		finished.resize(MAX_N);
		answer.clear();
		answer.resize(MAX_N);
		sccID.clear();
		sccID.resize(MAX_N);
		indegree.clear();
		indegree.resize(MAX_N);
}

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

	int t; cin>>t;

	while(t--)
	{
		Init();
		
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

		bool flag = false;	
		int cnt=0;
		for(int i=0; i<sccCnt; i++)
		{
			if(!indegree[i]) cnt++;
		}

		for(int i=0; i<n; i++)
		{
			if(!indegree[sccID[i]])
			{
				cout<<i<<'\n';
				flag=true;
			}
		}
		if(!flag) cout<<"Confused\n";
		cout<<'\n';
	}

	return 0;
}
