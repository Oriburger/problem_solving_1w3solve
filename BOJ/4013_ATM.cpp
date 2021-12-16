#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 500001;

int n, m; //정점의 개수와 간선의 개수
int s, p; //출발 idx와 레스토랑 개수
vector<bool> hasRest(MAX_N); //레스토랑을 포함하고 있는가? 

/* Tarjan's 알고리즘에 필요한 컨테이너와 변수들 */
int visitCnt=1, sccCnt=0;
vector<vector<int> > scc;
vector<int> adj[MAX_N];
vector<int> sccId(MAX_N);
vector<int> discovered(MAX_N);
vector<bool> finished(MAX_N);
stack<int> stk;

/* 추가 컨테이너 */
vector<int> sccVal(MAX_N); //scc가 가지고 있는 총액
vector<int> sccMax(MAX_N); //sccId[s]에서 sccId[t]까지의 최대 액수를 저장하는 sccMax[t]
vector<int> cost(MAX_N); //각 교차로가 가지고 있는 돈의 액수



int TarjanDFS(int curr) //타잔의 알고리즘
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
		scc.push_back(vector<int>());
		while(1) //scc를 구성하자.
		{
			int v = stk.top();
			stk.pop();

			sccId[v]=sccCnt;
			scc[sccCnt].push_back(v);
			sccVal[sccCnt] += cost[v]; //해당 정점의 cost를 scc 총액에 더해준다.
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

	/* 데이터 입력 -------*/
	cin>>n>>m;

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
		int k; cin>>k;
		hasRest[k]=true;
	}
	//-----------------------

	
	TarjanDFS(s); //시작점에서 시작하는게 이득,
	 			  //s에서 도달 가능한 scc만 추려낼 수 있다.

	sccMax[sccCnt-1]=sccVal[sccCnt-1];
	for(int curId=sccCnt-1; curId>=0; curId--)
	{
		for(auto &p : scc[curId]) //scc[curId]를 구성하는 정점을 순차로 끄집어낸다
		{
			for(auto &next : adj[p]) //해당 정점의 인접 정점 next가
			{
				if(sccId[next]!=curId) //다른 scc라면? 값을 갱신해준다.
				{
					sccMax[sccId[next]] = max(sccMax[sccId[next]], 
									   sccMax[curId]+sccVal[sccId[next]]);
				}
			}
		}
	}

	int ans=0;	
	for(int i=1; i<=n; i++)
	{
		//레스토랑을 가지고 있고, s에서 도달가능한 scc이라면?
		// +) discovered[i]가 0이라는건, 타잔 함수에서 호출되지 않았다는 의미
		//    즉, s에서 도달이 불가능하다는 의미.
		if(hasRest[i] && discovered[i]!=0) 
			ans = max(ans, sccMax[sccId[i]]);
	}
	cout<<ans<<'\n';

	return 0;
}
