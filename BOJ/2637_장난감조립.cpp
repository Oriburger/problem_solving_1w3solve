#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int n, m;
queue<int> q; //위상 정렬 때 사용할 큐
vector<P> adj[101]; //인접 리스트
vector<int> indegree, outdegree, ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	ans = indegree = outdegree = vector<int>(n+1, 0); //컨테이너 초기화

	for(int i=0; i<m; i++)
	{
		int u, v, w;
		cin>>u>>v>>w;

		adj[u].push_back({v, w}); 
		indegree[v]++; //들어오는 간선의 개수 증가
		outdegree[u]++; //나가는 간선의 개수 증가
	}

	for(int i=1; i<=n; i++)
		if(indegree[i]==0) //들어오는 간선이 없다면?
			q.push(i); //위상정렬의 시작 정점

	ans[n] = 1; //완제품 1개를 만들어보자!
	for(int i=1; i<=n; i++) //n번 반복
	{
		int curr = q.front(); //위상정렬 순서대로 큐에서 끄집어낸다
		q.pop();
		
		for(auto &next : adj[curr]) //해당 정점과 인접한 정점들 순회
		{
			if(--indegree[next.first]==0)
                q.push(next.first); //간선을 끊고, indegree가 0이면 큐에 push
			ans[next.first] += (ans[curr] * next.second); //curr을 만드는데에 필요한 부품의 개수를 증가
		}
	}

	for(int i=1; i<=n; i++)
		if(outdegree[i]==0) //나가는 간선이 없다면? : 기본 부품
			cout<<i<<' '<<ans[i]<<'\n'; 

	return 0;
}
