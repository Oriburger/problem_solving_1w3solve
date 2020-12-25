#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX_N = 1001;

int n, k, visitCnt=1, sccCnt=0;
vector<vector<int> > scc;
vector<int> adj[MAX_N];
vector<int> sccId(MAX_N), discovered(MAX_N);
vector<int> indegree(MAX_N), sccSize(MAX_N);
vector<bool> finished(MAX_N);
stack<int> stk;

int TarjanDFS(int curr)
{
	stk.push(curr); //유효한 정점이므로, stack에 push
	discovered[curr]=visitCnt++; //방문 순서 기록

	int lowLink = discovered[curr]; //lowLink 초기값은 본인
	for(auto &next : adj[curr])
	{
		if(finished[next]) continue;
		if(discovered[next]==0) lowLink=min(lowLink, TarjanDFS(next));
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
			sccSize[sccCnt]++;
			scc[sccCnt].push_back(v);

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

	cin>>n>>k;

	for(int i=1; i<=n; i++)
	{
		int a; cin>>a;
		adj[i].push_back(a);
	}

	for(int i=1; i<=n; i++)
		if(discovered[i]==0)
			TarjanDFS(i);

	for(int i=1; i<n; i++)
		if(sccId[i]!=sccId[i+1])
			indegree[sccId[i]]++;

	vector<int> cache(sccCnt, 0);
	vector<vector<bool> > visited;
	vector<int> ans;

	visited.resize(sccCnt, vector<bool>(sccCnt, false));

	for(int i=0; i<sccCnt; i++)
	{
		if(indegree[i]==0) 
			ans.push_back(i);

		for(auto &p : scc[i])
		{
			for(auto &next : adj[p])
			{
				if(sccId[next]!=sccId[p] && !visited[sccId[next]][sccId[p]])
				{
					cache[sccId[next]] += sccSize[sccId[p]];
					visited[sccId[next]][sccId[p]]=true;
				}
			}
		}
	}

	for(auto &p : ans)
	{
		
	}

	return 0;
}
