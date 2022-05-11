#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
const int MAX_N = 20001;

int n, m, k, visitCnt=1, sccCnt=0;
vector<int> adj[MAX_N];
vector<int> discovered(MAX_N), sccId(MAX_N);
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

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin>>n>>m;

	for(int i=0; i<n; i++)
	{
		int a, b;
		cin>>a>>b;

		//음수? !a, !b이고, 인덱스는 짝수
		//양수? a, b이고, 인덱스는 홀수
		a = (a<0 ? (a+1)*-2 : a*2-1);
		b = (b<0 ? (b+1)*-2 : b*2-1);

		adj[a%2 ? a-1 : a+1].push_back(b);
		adj[b%2 ? b-1 : b+1].push_back(a);
	}

	for(int i=0; i<m; i++)
		if(discovered[i]==0) DFS(i);

	//SCC 구성이 가능한가?
	for(int i=0; i<m; i+=2)
		if(m > n || sccId[i] == sccId[i+1])
		{
			cout<<"OTL\n"; //불가능
			return 0;
		}
	cout<<"^_^\n"; //가능

	return 0;
}
