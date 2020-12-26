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
vector<int> maxSize(MAX_N), minSize(MAX_N);
vector<int> adj[MAX_N];
vector<vector<int> > scc;
vector<int> sccId(MAX_N), discovered(MAX_N);
vector<int> indegree(MAX_N), sccSize(MAX_N);
vector<bool> finished(MAX_N);
stack<int> stk;

int GetAnswer(int k, int idx)
{
	if(idx == n) return 0;

	int &ret = cache[k][idx];
	if(ret!=-1) return ret;

	ret = GetAnswer(k, idx+1);
	
	for(int i=minSize[idx]; i<=maxSize[idx]; i++)
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

void Debug()
{
	for(int i=sccCnt-1; i>=0; i--)
	{
		cout<<"SccID "<<i;//<<"("<<sccSize[i]<<") :";
		//for(auto &p : scc[i])
		//	cout<<p<<", ";
		
		//cout<<" / indegree : "<<indegree[i]; 
		//cout<<"\n";
		cout<<" minSize : "<<minSize[i]<<", maxSize : "<<maxSize[i]<<'\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>k;

	for(int i=1; i<=n; i++)
	{
		int a; cin>>a;
		adj[i].push_back(a);
	}

	for(int i=1; i<=n; i++)
		if(discovered[i]==0)
			TarjanDFS(i);

	for(int i=sccCnt-1; i>=0; i--)
	  for(auto &p : scc[i])
	   	for(auto &next : adj[p])
	   		if(sccId[p]!=sccId[next])
	   			indegree[sccId[next]]++;
	
	for(int i=0; i<sccCnt; i++)
		if(indegree[i]==0)
			minSize[i]=maxSize[i]=sccSize[i];
	
	vector<bool> checked(sccCnt, false);
	for(int i=sccCnt-1; i>=0; i--)
	{
		for(auto &p : scc[i])
		{
		   	for(auto &next : adj[p])
			{
		   		if(sccId[p]!=sccId[next] && !checked[sccId[next]])
				{
					maxSize[sccId[next]] = sccSize[sccId[next]] + maxSize[sccId[p]];
				//	minSize[]

					checked[sccId[next]]=true;
				}
			}
		}
	}
	
	Debug();

	for(int i=0; i<1001; i++)
		memset(cache[i], -1, sizeof(int)*MAX_N);

	cout<<GetAnswer(k, 0)<<'\n';

	return 0;
}

