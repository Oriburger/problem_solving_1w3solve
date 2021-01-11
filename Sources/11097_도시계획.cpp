#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

int t, n, sccCnt, visitCnt;
int board[301][301];
vector<int> adj[301];
vector<int> discovered, sccId;
vector<pair<int, int> > ans;
vector<bool> finished;
stack<int> stk;

//컨테이너 초기화...
void Init()
{
	sccCnt=0, visitCnt=1;
	for(int i=0; i<301; i++)
		adj[i].clear();
	discovered.clear();
	finished.clear();
	sccId.clear();
	ans.clear();
	sccId.resize(n, 0);
	discovered.resize(n, 0);
	finished.resize(n, false);
	memset(board, false, sizeof(board));
}

//일반적인 타잔의 알고리즘 
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
		bool flag = false;
		int u = curr;
		while(1)
		{
			int v = stk.top();
			stk.pop();

			//scc간의 간선들을 묶어준다.
			if(!flag && curr!=u) ans.push_back({curr, u});
			else if(u!=v) ans.push_back({u, v});
			u=v; flag = true;

			sccId[v]=sccCnt;
			finished[v]=true;

			if(v == curr) break;
		}
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

		Init(); //컨테이너 초기화 & 할당

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				int input;
				scanf("%1d", &input);
				if(input && i!=j)
					board[i][j]=true; //인접행렬에 우선 check
			}
		}

		//플로이드-워셜 변형 알고리즘, 필요없는 간선들을 없애준다.
		//i->k->j 경로가 있다면, i->j는 제거
		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					if(board[i][k] && board[k][j] && board[i][j])
						board[i][j]=false;

		//타잔 알고리즘 수행 위한 인접리스트 생성
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(board[i][j])
					adj[i].push_back(j);

		//SCC를 구성해준다.
		for(int i=0; i<n; i++)
			if(!discovered[i])
				TarjanDFS(i);

		//이제 SCC 사이를 연결하는 간선도 추가한다.
		for(int i=0; i<n; i++)
			for(auto &j : adj[i])
				if(sccId[i]!=sccId[j])
					ans.push_back({i, j});

		printf("%d\n", (int)ans.size());
		for(auto &ans : ans)
			printf("%d %d\n", ans.first+1, ans.second+1);
	}

	return 0;
}
