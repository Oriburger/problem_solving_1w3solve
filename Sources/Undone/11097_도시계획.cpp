#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

int t, n, sccCnt, visitCnt, ans;
int board[301][301];
vector<int> adj[301];
vector<int> discovered, sccId, sccSize;
vector<vector<int> > scc;
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
			lowLink = min(lowLink, TarjanDFS(next));
		else 
			lowLink = min(lowLink, discovered[next]);
	}

	if(lowLink == discovered[curr])
	{
		vector<int> temp(0);
		while(1)
		{
			int v = stk.top();
			stk.pop();

			sccId[v]=sccCnt;
			sccSize[sccCnt]++;
			temp.push_back(v);
			finished[v]=true;

			if(v == curr) break;
		}
		scc.push_back(temp);
		sccCnt++;
	}

	return lowLink;
}

void Debug()
{
	printf("\n-Debug-\n");
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			printf("%d ", (int)board[i][j]);
		printf("\n");
	}
	printf("-----\n\n");

	return;
}

int main()
{
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &n);

		sccCnt=0, visitCnt=1, ans=0;
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


		Debug();

		for(int i=0; i<n; i++)
		{
			for(auto &j : adj[i])
			{
				if
			}
		}

		printf("%d\n", (int)ansList.size());
		for(auto &ans : ansList)
			printf("%d %d\n", ans.first+1, ans.second+1);

		Clear();
	}

	return 0;
}

void Clear()
{
	for(int i=0; i<301; i++)
	{
		adj[i].clear();
		memset(board[i], false, sizeof(bool)*300);
	}
	discovered.clear();
	finished.clear();
	sccId.clear();
	sccSize.clear();
	ansList.clear();
	scc.clear();
}
