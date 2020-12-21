#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 500001;

int n, m; //정점의 개수와 간선의 개수
int s, p; //출발 idx와 레스토랑 개수
vector<bool> hasRest(MAX_N, false);
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
vector<vector<int> > sccAdjMatrix; //인접 행렬 형식
vector<vector<int> > sccAdjList; //인접 리스트 형식
vector<bool> visited;

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

	for(auto &next : adj[curr])
	{
		if(visited[next]) continue;
		if(sccAdjMatrix[sccId[curr]][sccId[next]]) continue;
		if(sccId[curr]!=sccId[next])
		{
			sccAdjMatrix[sccId[curr]][sccId[next]]=true;
			sccAdjList[sccId[curr]].push_back(sccId[next]);
		}
		SccCompress(next);
	}
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
		hasRest[a]=true;
	}
	//--------------------

	/* Solution ---------*/
	for(int i=1; i<=n; i++)
		if(discovered[i]==0)
			TarjanDFS(i);

	visited.resize(n, false);
	sccAdjMatrix.resize(sccCnt, vector<int>(sccCnt));
	sccAdjList.resize(sccCnt);
	SccCompress(s);

	//----------------------

	{
		/* Debug -------------
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
			for(auto &next : sccAdjList[i])
				cout<<next<<' ';
			cout<<'\n';
		}
		cout<<'\n';
		for(int i=0; i<sccCnt; i++)
		{
			for(int j=0; j<sccCnt; j++)
			{
				cout<<sccAdjMatrix[i][j];
			}
			cout<<'\n';
		}
		cout<<'\n';
	//--------------------*/
	}

	vector<int> sccMax(sccCnt, 0);

	sccMax[sccId[s]]=sccVal[sccId[s]];
	for(int i=sccId[s]; i>=0; i--)
		for(auto &next : sccAdjList[i])
			sccMax[next] = sccMax[i]+sccVal[next];

	int ans=0;	
	for(int i=1; i<=n; i++)
		if(hasRest[i])
			ans = max(ans, sccMax[sccId[i]]);

	cout<<ans<<'\n';

	return 0;
}
