#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

int t, n, sccCnt, visitCnt, ans;
bool check[301][301];
vector<int> adj[301];
vector<int> discovered, sccId, sccSize;
vector<vector<int> > scc;
vector<pair<int, int> > ansList;
vector<bool> finished;
stack<int> stk;

void Clear();

int TarjanDFS(int curr)
{
	stk.push(curr);
	int lowLink = discovered[curr] = visitCnt++;

	for(auto &next : adj[curr])
	{
		if(finished[next]) continue;
		if(!discovered[next])
			lowLink = min(lowLink, TarjanDFS(next));
		else 
			lowLink = min(lowLink, discovered[next]);
	}

	if(lowLink == discovered[curr])
	{
		vector<int> temp(0);
		while(1)
		{
			int v = stk.top();
			stk.pop();

			sccId[v]=sccCnt;
			sccSize[sccCnt]++;
			temp.push_back(v);
			finished[v]=true;

			if(v == curr) break;
		}
		scc.push_back(temp);
		sccCnt++;
	}

	return lowLink;
}

int main()
{
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &n);

		sccCnt=0, visitCnt=1, ans=0;
		sccId.resize(n, 0);
		sccSize.resize(n, 0);
		discovered.resize(n, 0);
		finished.resize(n, false);

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				int input;
				scanf("%1d", &input);
				if(input==true && i!=j)	
					adj[i].push_back(j);
			}
		}

		for(int i=0; i<n; i++)
			if(!discovered[i])
				TarjanDFS(i);

		int cnt=0;
		for(int cur=0; cur<n; cur++)
		{
			for(int &next : adj[cur])
			{
				if(cnt==sccCnt-1) break;
				if(sccId[cur]!=sccId[next] &&
					!check[sccId[cur]][sccId[next]])
				{
					ansList.push_back({cur, next});
					check[sccId[cur]][sccId[next]]=true;
					cnt++;
				}
			}
		}

		for(int i=0; i<sccCnt; i++)
		{
			if(sccSize[i]==1) continue;
			//printf("sccId[%d] : ", i);
			for(int j=1; j<scc[i].size(); j++)
				ansList.push_back({scc[i][j-1], scc[i][j]});
				//printf("%d ", scc[i][j]);
			//printf("\n");
				
			ansList.push_back({scc[i][scc[i].size()-1], scc[i][0]});
		}

		ans = sccCnt-1;
		for(int i=0; i<sccCnt; i++)
			ans+=(sccSize[i]-1)*2;

		printf("%d\n", ans);
		sort(ansList.begin(), ansList.end());
		for(auto &p : ansList)
			printf("%d %d\n", p.first+1, p.second+1);
				
		Clear();
	}

	return 0;
}

void Clear()
{
	for(int i=0; i<301; i++)
	{
		adj[i].clear();
		memset(check[i], false, sizeof(bool)*300);
	}
	discovered.clear();
	finished.clear();
	sccId.clear();
	sccSize.clear();
	ansList.clear();
	scc.clear();
}
