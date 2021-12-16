#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX_N = 10001;

int n, m, s, t;
int visitCnt=1, sccCnt=0;
vector<bool> finished(MAX_N);
vector<int> adj[MAX_N], discovered(MAX_N);
vector<int> sccId(MAX_N), sccSize(MAX_N);
vector<vector<int> > scc;
stack<int> stk;

int TarjanDFS(int curr)
{
	stk.push(curr);
	discovered[curr] = visitCnt++;

	int lowLink = discovered[curr];
	for(auto &next : adj[curr])
	{
		if(finished[next]) continue;
		if(!discovered[next]) lowLink = min(lowLink, TarjanDFS(next));
		else lowLink = min(lowLink, discovered[next]);
	}

	if(lowLink == discovered[curr])
	{
		scc.push_back(vector<int>());
		while(1)
		{
			int v = stk.top();
			stk.pop();
			
			sccId[v]=sccCnt;
			scc[sccCnt].push_back(v);
			sccSize[sccCnt]++;
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

	cin>>n>>m>>s>>t;

	for(int i=0; i<m; i++)
	{
		int a, b; cin>>a>>b; 
		adj[a].push_back(b);
	}

	TarjanDFS(s);

	vector<int> dp(sccCnt, 0);
	
	dp[sccCnt-1] = sccSize[sccCnt-1];
	for(int curIdx = sccCnt-1; curIdx>=0; curIdx--)
	{
		for(auto &p : scc[curIdx])
		{
			for(auto &next : adj[p])
			{
				if(sccId[next]!=curIdx)
					dp[sccId[next]] = max(dp[sccId[next]], 
										  dp[curIdx]+sccSize[sccId[next]]);
			}
		}
	}
/*
	for(int i=0; i<sccCnt; i++)
	{
		cout<<"sccId["<<i<<"]\n";
		for(auto &p : scc[i])
			cout<<p<<' ';
		cout<<" / ";

		cout<<"sccSize is "<<sccSize[i]<<'\n';
	}*/

	if(discovered[t])
		cout<<dp[sccId[t]]<<'\n';
	else cout<<0<<'\n';

	return 0;
}
