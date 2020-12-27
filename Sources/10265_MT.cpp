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

int GetAnswer(int k, int idx)
{
	if(idx == sccCnt) return 0;

	int &ret = cache[k][idx];
	if(ret!=-1) return ret;

	ret = GetAnswer(k, idx+1);
	
	for(int i=dx[idx]; i<=dy[idx]; i++)
		if(k >= i)
			ret = max(ret, GetAnswer(k-i, idx+1)+i);

	return ret;
}

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
		adj[i].push_back(x);
	}

	for(int i=1; i<=n; i++)
		if(discovered[i]==0)
			TarjanDFS(i);

	for(int i=1; i<=n; i++)
		for(auto &j : adj[i])
			if(sccId[i]!=sccId[j])
			{
				indegree[sccId[j]]++;
				outdegree[sccId[i]]++;
			}

	for(int i=0; i<sccCnt; i++)
	{
		if(indegree[i]==0)	q.push(i);

		maxSize[i]=sccSize[i];
	}
	
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();

		for(auto &p : scc[curr])
		{
			for(auto &next : adj[p])
			{
				if(curr != sccId[next])
				{
					if(--indegree[sccId[next]]==0)
						q.push(sccId[next]);
					maxSize[sccId[next]]+=maxSize[curr];
				}
			}
		}
	}

	for(int i=0; i<sccCnt; i++)
		if(outdegree[i]==0)
		{
			dx[i]=sccSize[i];
			dy[i]=maxSize[i];
		}

	for(int i=0; i<1001; i++)
		memset(cache[i], -1, sizeof(int)*sccCnt);

	cout<<GetAnswer(k, 0)<<'\n';

	return 0;
}

