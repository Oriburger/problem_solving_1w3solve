#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, visitCnt=0, sccCnt=0;
vector<int> discovered, sccId;
vector<bool> finished;
vector<vector<int> > adj;
stack<int> stk;

int TarjanDFS(int curr)
{
	stk.push(curr);
	discovered[curr]=++visitCnt;
	int lowLink = discovered[curr];

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
		while(1)
		{
			int v = stk.top();
			stk.pop();

			sccId[v]=sccCnt;
			finished[v]=true;

			if(v==curr) break;
		}
		sccCnt++;
	}

	return lowLink;
}

void Init(int m)
{
	sccCnt=visitCnt=0;
	discovered.clear();
	discovered.resize(m*2+1, 0);
	finished.clear();
	finished.resize(m*2+1, false);
	sccId.clear();
	sccId.resize(m*2+1, 0);
	adj.clear();
	adj.resize(m*2+1, vector<int>());
}

inline int Oppo(int k){ return k%2 ? k-1 : k+1; }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1)
	{
		cin>>n>>m;

		if(!n && !m) break;

		Init(m);

		for(int i=0; i<n; i++)
		{
			int a, b;
			cin>>a>>b;

			a = (a<0 ? -(a+1)*2 : a*2-1);
			b = (b<0 ? -(b+1)*2 : b*2-1);
			
			adj[Oppo(a)].push_back(b);
			adj[Oppo(b)].push_back(a);
		}

		for(int i=0; i<m*2; i++)
			if(!discovered[i]) TarjanDFS(i);

		bool ans = true;
		for(int i=0; i<m; i++)
			if(sccId[i*2]==sccId[i*2+1])
				ans = false;

		cout<<ans<<'\n';
	}

	return 0;
}
