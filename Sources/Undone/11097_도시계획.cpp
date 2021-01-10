#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

int t, n, sccCnt, visitCnt;
int board[301][301];
vector<int> adj[301];
vector<int> discovered, sccId;
vector<pair<int, int> > ans;
vector<bool> finished;
stack<int> stk;

void Init()
{
	sccCnt=0, visitCnt=1;
	for(int i=0; i<301; i++)
		adj[i].clear();
	discovered.clear();
	finished.clear();
	sccId.clear();
	ans.clear();
	sccId.resize(n, 0);
	discovered.resize(n, 0);
	finished.resize(n, false);
	memset(board, false, sizeof(board));
}

int TarjanDFS(int curr)
{
	stk.push(curr);
	int lowLink = discovered[curr] = visitCnt++;

	for(auto &next : adj[curr])
	{
		if(finished[next]) continue;
		if(!discovered[next])
			lowLink = min(lowLink, TarjanDFS(next));
		else 
			lowLink = min(lowLink, discovered[next]);
	}

	if(lowLink == discovered[curr])
	{
		bool flag = false;
		int u = curr;
		while(1)
		{
			int v = stk.top();
			stk.pop();

			if(!flag && curr!=u) ans.push_back({curr, u});
			else if(u!=v) ans.push_back({u, v});
			u=v; flag = true;

			sccId[v]=sccCnt;
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

		Init();

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				int input;
				scanf("%1d", &input);
				if(input && i!=j)	
					board[i][j]=true;
			}
		}

		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					if(board[i][k] && board[k][j] && board[i][j])
						board[i][j]=false;

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(board[i][j])
					adj[i].push_back(j);

		for(int i=0; i<n; i++)
			if(!discovered[i])
				TarjanDFS(i);

		for(int i=0; i<n; i++)
			for(auto &j : adj[i])
				if(sccId[i]!=sccId[j])
					ans.push_back({i, j});

		printf("%d\n", (int)ans.size());
		for(auto &ans : ans)
			printf("%d %d\n", ans.first+1, ans.second+1);
	}

	return 0;
}
