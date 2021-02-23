#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 214700000;
const int MAX_V = 26;

int n, visitCnt=1, sccCnt=0;
stack<int> stk;
vector<int> adj[MAX_V], discovered;
vector<vector<int> > sccArr;
vector<bool> finished, check;

int TarjanDFS(int curr)
{
	stk.push(curr);
	discovered[curr]=visitCnt++;

	int lowLink = discovered[curr];	
	for(const int &next : adj[curr])	
	{
		if(finished[next]) continue;
		if(!discovered[next])	lowLink = min(lowLink, TarjanDFS(next));
		else lowLink = min(lowLink, discovered[next]);
	}

	if(lowLink == discovered[curr])
	{
		vector<int> scc;
		while(1)
		{
			int t = stk.top();
			scc.push_back(t);
			stk.pop();
			finished[t]=true;

			if(t==curr) break;
		}
		sort(scc.begin(), scc.end());
		sccArr.push_back(scc);
		sccCnt++;
	}
	return lowLink;
}

void Init()
{
	visitCnt=1, sccCnt=0;
	for(int i=0; i<MAX_V; i++)
		adj[i].clear();
	sccArr.clear();
	discovered.clear();
	discovered.resize(MAX_V);
	finished.clear();
	finished.resize(MAX_V, false);
	check.clear();
	check.resize(MAX_V, false);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1)
	{
		cin>>n;

		if(n==0) break;

		Init();

		for(int i=0; i<n; i++)
		{
			vector<char> s;
			char c;
			for(int j=0; j<6; j++)
			{
				cin>>c;
				s.push_back(c);
				check[c-'A']=true;
			}

			for(int j=0; j<5; j++)
				adj[s[5]-'A'].push_back(s[j]-'A');
		}

		for(int i=0; i<MAX_V; i++)
			if(!discovered[i] && check[i])
				TarjanDFS(i);

		sort(sccArr.begin(), sccArr.end());

		for(int i=0; i<sccCnt; i++)
		{
			for(const int &p : sccArr[i])
				cout<<(char)(p+'A')<<' ';
			cout<<'\n';
		}
		cout<<'\n';
	}

	return 0;
}
