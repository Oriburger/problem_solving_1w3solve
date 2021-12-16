#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_V = 101;

int v, e, k, visitCnt=1, sccCnt=0;
stack<int> stk;
vector<int> sccArr[MAX_V], indegree(MAX_V);
vector<int> adj[MAX_V], cost(MAX_V);
vector<int> discovered(MAX_V), sccID(MAX_V);
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
		while(1)
		{
			int t = stk.top();
			stk.pop();
			finished[t]=true;
			sccArr[sccCnt].push_back(t);
			sccID[t]=sccCnt;
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

	cin>>v;

	for(int i=1; i<=v; i++)
		cin>>cost[i];

	for(int i=1; i<=v; i++)
		for(int j=1; j<=v; j++)
		{
			char input;
			cin>>input;
			if(input=='1')
				adj[i].push_back(j);
		}
	

	for(int i=1; i<=v; i++)
		if(discovered[i]==0)
			DFS(i);


	int answer=0;
	for(int i=0; i<sccCnt; i++)
	{
		int minVal=2147000000;
		for(const auto& val : sccArr[i])
			minVal = min(minVal, cost[val]);
		answer+=minVal;
	}

	cout<<answer<<'\n';

	return 0;
}
