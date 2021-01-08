#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;

int t, n, sccCnt, visitCnt, ans;
vector<int> adj[301];
vector<int> discovered, sccId, sccSize;
vector<pair<int, int> > ansList;
vector<bool> finished;
stack<int> stk;

void Clear();

int TarjanDFS(int curr)
{
	stk.push(curr);
	int lowLink = discovered[curr] = visitCnt++;

	for(auto &next : adj[curr])
	{
		if(finished[next]) continue;
		if(!discovered[next])
		{
			lowLink = min(lowLink, TarjanDFS(next));
			ansList.push_back({curr, next});
		}
		else lowLink = min(lowLink, discovered[next]);
	}

	if(lowLink == discovered[curr])
	{
		while(1)
		{
			int v = stk.top();
			stk.pop();
			sccId[v]=sccCnt;
			sccSize[sccCnt]++;
			finished[v]=true;

			if(v == curr) break;
		}
		sccCnt++;
	}

	return lowLink;
}

int main()
{
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &n);

		sccCnt=1, visitCnt=1, ans=0;
		sccId.resize(n, 0);
		sccSize.resize(n, 0);
		discovered.resize(n, 0);
		finished.resize(n, false);

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				int input;
				scanf("%1d", &input);
				if(input==true && i!=j)	
					adj[i].push_back(j);
			}
		}

		for(int i=0; i<n; i++)
			if(!discovered[i])
				TarjanDFS(i);

				
				
		Clear();
	}

	return 0;
}

void Clear()
{
	for(int i=0; i<301; i++)
		adj[i].clear();
	discovered.clear();
	finished.clear();
	sccId.clear();
	sccSize.clear();
	ansList.clear();
}
