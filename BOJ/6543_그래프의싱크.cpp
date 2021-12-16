#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX_N = 5001;

int n, m, visitCnt, sccCnt;
vector<int> adj[MAX_N];
vector<vector<int> > sccArr;
vector<int> discovered, sccID, outdegree, answer;
vector<bool> finished;
stack<int> stk;

void Init()
{
	visitCnt=sccCnt=0;

	for(int i=1; i<=n; i++)
		adj[i].clear();
	sccArr.clear();
	sccID.clear();
	discovered.clear();
	finished.clear();
	outdegree.clear();
	answer.clear();

	sccArr.resize(n+1, { });
	sccID.resize(n+1, 0);
	discovered.resize(n+1, 0);
	finished.resize(n+1, false);
}

int DFS(int curr)
{
	stk.push(curr);
	discovered[curr]=++visitCnt;
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
			int t = stk.top();
			stk.pop();
			sccID[t]=sccCnt;
			finished[t]=true;
			sccArr[sccCnt].push_back(t);
			if(t==curr) break;
		}
		sort(sccArr[sccCnt].begin(), sccArr[sccCnt].end());
		sccCnt++;
	}

	return lowLink;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1)
	{
		cin>>n; if(n==0) break;
		cin>>m;

		Init();

		for(int i=0; i<m; i++)
		{
			int u, v;
			cin>>u>>v;
			adj[u].push_back(v);
		}

		for(int i=1; i<=n; i++)
			if(!discovered[i])
				DFS(i);

		outdegree.resize(sccCnt, 0);
		
		for(int cur=1; cur<=n; cur++)
			for(const int next : adj[cur])
				if(sccID[cur]!=sccID[next])
					outdegree[sccID[cur]]++;
		
		for(int i=0; i<sccCnt; i++)
			if(outdegree[i]==0)  //Bottom(G)에 속하려면?  -> outdegree가 0이어야함!
				for(const auto &p : sccArr[i])
					answer.push_back(p);
		
		sort(answer.begin(), answer.end());

		for(const auto &p : answer)
			cout<<p<<' ';

		cout<<'\n';
	}


	return 0;
}
