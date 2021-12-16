#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
const int MAX_N = 2100;

int n, m, visitCnt=1, sccCnt=0;
vector<int> adj[MAX_N];
vector<int> discovered(MAX_N), sccId(MAX_N), indegree(MAX_N);
vector<bool> finished(MAX_N);
stack<int> stk;

int DFS(int curr)
{
	stk.push(curr);
	discovered[curr]=visitCnt++;

	int lowLink = discovered[curr];
	for(const auto &next : adj[curr])
	{
		if(finished[next]) continue;
		if(discovered[next]==0) lowLink = min(lowLink, DFS(next));
		else lowLink = min(lowLink, discovered[next]);
	}

	if(lowLink == discovered[curr])
	{
		vector<int> scc;
		while(1)
		{
			int v = stk.top();
			stk.pop();
			finished[v] = true;
			sccId[v] = sccCnt;
			
			if(v==curr) break;
		}
		sccCnt++;
	}
	return lowLink;
}

inline int oppo(int n)
{
	return n%2 ? n-1 : n+1;
}

void Clear()
{
	for(int i=0; i<MAX_N; i++)
		adj[i].clear();
	while(!stk.empty())
		stk.pop();
	discovered.clear();
	discovered.resize(MAX_N, 0);
	finished.clear();
	finished.resize(MAX_N, false);
	sccId.clear();
	sccId.resize(MAX_N, 0);
	indegree.clear();
	indegree.resize(MAX_N, 0);
	visitCnt=1, sccCnt=0;
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	while(1)
	{
		cin>>n>>m;

		if(cin.eof()) break;

		for(int i=0; i<m; i++)
		{
			int a, b;
			cin>>a>>b;

			//음수? !a, !b이고, 인덱스는 짝수
			//양수? a, b이고, 인덱스는 홀수 
			a = (a<0 ? (a+1)*-2 : a*2-1);
			b = (b<0 ? (b+1)*-2 : b*2-1);

			adj[oppo(a)].push_back(b);
			adj[oppo(b)].push_back(a);
		}

		for(int i=0; i<n*2; i++)
			if(discovered[i]==0) DFS(i);

		//SCC 구성이 가능한가?

		bool flag = true;
		for(int i=0; i<n; i++)
			if(sccId[i*2] == sccId[i*2+1])
			{
				flag = false;
				break;
			}

		cout<<flag<<'\n';

		Clear();
	}

	return 0;
}
