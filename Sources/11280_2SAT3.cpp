#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX_N = 20001;

int n, m, visitCnt=0, sccCnt=0, answer=0;
vector<int> adj[MAX_N];
vector<bool> finished(MAX_N, false);
vector<int> sccID(MAX_N), discovered(MAX_N);
stack<int> stk;

int DFS(int curr)
{
	stk.push(curr);
	int lowLink = discovered[curr] = ++visitCnt;

	for(const int &next : adj[curr])
	{
		if(finished[next]) continue;
		if(discovered[next]==0)
			lowLink = min(lowLink, DFS(next));
		else 
			lowLink = min(lowLink, discovered[next]);
	}

	if(lowLink == discovered[curr])
	{
		while(1)
		{
			int v = stk.top();
			stk.pop();
			sccID[v]=sccCnt;
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

	cin>>n>>m;

	for(int i=0; i<m; i++)
	{
		int a, b;
		cin>>a>>b;
		
		a = (a<0 ? -(a+1)*2 : a*2-1);
		b = (b<0 ? -(b+1)*2 : b*2-1);

		adj[a%2 ? a-1 : a+1].push_back(b);
		adj[b%2 ? b-1 : b+1].push_back(a);
	}

	for(int i=0; i<n*2; i++)
		if(!discovered[i]) 
			DFS(i);
	
	for(int i=0; i<n; i++)
		if(sccID[i*2]==sccID[i*2+1])
		{
			cout<<"0\n";
			return 0;
		}
	
	cout<<"1\n";

	return 0;
}
