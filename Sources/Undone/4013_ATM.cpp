#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX_N = 1001;

int n, m; //정점의 개수와 간선의 개수
int s, p; //출발 idx와 레스토랑 개수
vector<bool> isRest(MAX_N, false);
vector<int> cache;

/* scc */
int visitCnt=1, sccCnt=0;
vector<int> sccId(MAX_N), sccVal(MAX_N);
vector<int> discovered(MAX_N);
vector<bool> finished(MAX_N);
stack<int> stk;

/* graph */
vector<int> adj[MAX_N];
vector<int> cost(MAX_N);

/* scc graph */
vector<int> indegree(MAX_N);
vector<vector<int> > sccAdj; //인접 행렬 형식
vector<bool> visited(MAX_N);

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
		while(1)
		{
			int v = stk.top();
			stk.pop();
			finished[v]=true;
			sccId[v]=sccCnt;
			sccVal[sccCnt]+=cost[v]; //scc의 총 cost 값

			if(v==curr) break;
		}
		sccCnt++;
	}
	return lowLink;
}

void SccCompress(int curr) //scc 압축
{
	visited[curr]=true;

	cout<<curr<<" visited\n";

	for(auto &next : adj[curr])
	{
		if(sccId[curr]!=sccId[next])
			sccAdj[sccId[curr]].push_back(sccId[next]);
		if(visited[next]) continue;
		SccCompress(next);
	}
}

int GetAnswer(int curr)
{
	int ret = sccVal[curr];

	for(auto &next : sccAdj[curr])
		ret=max(ret, ret+GetAnswer(next));
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	/* Input ------------*/
	for(int i=0; i<m; i++)
	{
		int u, v; cin>>u>>v;
		adj[u].push_back(v);
	}

	for(int i=1; i<=n; i++)
		cin>>cost[i];

	cin>>s>>p;
	for(int i=0; i<p; i++)
	{
		int a; cin>>a;
		isRest[a]=true;
	}
	//--------------------

	/* Solution ---------*/
	for(int i=1; i<=n; i++)
		if(discovered[i]==0)
			TarjanDFS(i);

	for(int i=1; i<n; i++)
		if(sccId[i]!=sccId[i+1])
			indegree[sccId[i]]++;

	sccAdj.resize(sccCnt);
	SccCompress(s);
	//----------------------

	/* Debug -------------*/
	cout<<'\n';
	
	cout<<"sccId\n";
	for(int i=1; i<=n; i++)
		cout<<i<<" : "<<sccId[i]<<"\n";
	cout<<'\n';

	cout<<"sccVal\n";	
	for(int i=0; i<sccCnt; i++)
		cout<<i<<" : "<<sccVal[i]<<'\n';
	cout<<'\n';	

	for(int i=0; i<sccCnt; i++)
	{
		cout<<"scc "<<i<<" : ";
		for(auto &next : sccAdj[i])
			cout<<next<<' ';
		cout<<'\n';
	}
	//--------------------

	cache.resize(sccCnt, -1);
	cout<<GetAnswer(s)<<'\n';

	return 0;
}
