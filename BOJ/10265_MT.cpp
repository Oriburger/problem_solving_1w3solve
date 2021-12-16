#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 1001;

int n, k, visitCnt=1, sccCnt=0;
int cache[1001][MAX_N];
vector<int> maxSize(MAX_N);
vector<int> dx(MAX_N), dy(MAX_N);
vector<int> adj[MAX_N];
queue<int> q;

vector<vector<int> > scc;
vector<int> sccId(MAX_N), discovered(MAX_N);
vector<int> indegree(MAX_N), outdegree(MAX_N), sccSize(MAX_N);
vector<bool> finished(MAX_N);
stack<int> stk;

/* 일반적인 Knapsack */
int GetAnswer(int k, int idx)
{
	if(idx == sccCnt) return 0;

	int &ret = cache[k][idx];
	if(ret!=-1) return ret;

	ret = GetAnswer(k, idx+1);
	
	//outdegree[idx]==0인 scc에 한해서
	//sccSize[idx] ~ maxSize[idx]까지의 최대 인원을 구해준다\
	//outdegree[idx]>0인 scc까지 고려를 해주면, 중복 pick이 생긴다. 
	for(int i=dx[idx]; i<=dy[idx]; i++)
		if(k >= i)
			ret = max(ret, GetAnswer(k-i, idx+1)+i);

	return ret;
}

/* Tarjan의 scc 알고리즘 : 설명 생략 */
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
		scc.push_back(vector<int>());
		while(1)
		{
			int v = stk.top();
			stk.pop();

			sccId[v]=sccCnt;
			sccSize[sccCnt]++;
			scc[sccCnt].push_back(v);

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

	cin>>n>>k;

	for(int i=1; i<=n; i++)
	{
		int x; cin>>x;
		adj[i].push_back(x); //i는 x가 타면 탈 수 있다. (x가 탄다해서 꼭 타는건 아님)
	}

	/* scc 구성 : Tarjan의 알고리즘 */
	for(int i=1; i<=n; i++)
		if(discovered[i]==0)
			TarjanDFS(i); 

	/* scc들의 indegree와 outdegree를 구해준다. */
	for(int i=1; i<=n; i++)
		for(auto &j : adj[i])
			if(sccId[i]!=sccId[j])
			{
				indegree[sccId[j]]++;
				outdegree[sccId[i]]++;
			}

	for(int i=0; i<sccCnt; i++)
	{
		if(indegree[i]==0)	q.push(i); //위상정렬을 위해 q에 넣어준다. 
		maxSize[i]=sccSize[i]; //각 scc의 초기 maxSize는 scc의 구성 정점 수
	}
	
	/* 위상정렬 시작 */
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();

		//실제 압축 구현할 필요없이 scc를 구성하는 정점들을 순회하며
		//각 정점들의 인접 정점이 다른 scc에 속하는지 판단하며 구현 
		for(auto &p : scc[curr]) 
		{
			for(auto &next : adj[p])
			{
				if(curr != sccId[next]) //다른 scc!
				{
					if(--indegree[sccId[next]]==0) //들어오는 간선이 더이상 없다면,
						q.push(sccId[next]); //큐에 push
					maxSize[sccId[next]]+=maxSize[curr]; 
					//sccId[next] SCC에 포함되는 정점들은 버스에 타려면
					//curr SCC의 정점들이 반드시 타야한다. 
					//따라서 sccId[next]의 최대 Size는 curr SCC의 크기를 포함한 값.
				}
			}
		}
	}

	//outdegree가 0인 SCC는 다른 SCC가 버스에 타지 않아도 버스에 탈 수 있다.
	//즉, outdegree가 0인 SCC의 최소값인 본인의 사이즈 (sccSize[i])에서 
	//들어오는 SCC들의 사이즈를 모두 합한 maxSize[i]까지 고려하면 된다.
	for(int i=0; i<sccCnt; i++)
		if(outdegree[i]==0)
		{
			dx[i]=sccSize[i];
			dy[i]=maxSize[i];
		}

	for(int i=0; i<1001; i++)
		memset(cache[i], -1, sizeof(int)*sccCnt);

	//knapsack 
	cout<<GetAnswer(k, 0)<<'\n';

	return 0;
}

