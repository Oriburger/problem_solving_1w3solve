#include <bits/stdc++.h>
using namespace std;
const int INF = 2147000000;

int n, ans = INF;
vector<int> p, adj[11];
vector<int> combi, group[2], sum;

int BFS(int start, const bool type) //group[type]의 원소로 BFS
{
	int ret = p[start];
	queue<int> q;
	vector<bool> visited(n+1, false);

	q.push(start);
	visited[start] = true;
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();

		for(auto &next : adj[curr])
		{
			if(visited[next]) continue;
			if(combi[next-1] != type) continue; //다른 그룹이라면 큐에 넣지 않음

			q.push(next);
			ret += p[next];
			visited[next] = true;
		}
	}
	
	for(auto &p : group[type]) //아직 방문하지 않은 그룹 내 정점이 있다면?
		if(!visited[p]) ret = -1; //연결되어있지 않다는 의미이므로 -1반환

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	p = vector<int>(n+1, 0);
	
	for(int i=1; i<=n; i++)
		cin>>p[i];

	for(int u=1; u<=n; u++)
	{
		int cnt, v; cin>>cnt;
		for(int i=0; i<cnt; i++)
		{
			cin>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}		
	}

	for(int len=1; len<=n/2; len++) // n/2번 반복
	{	
		combi.assign(len, 0); //조합 만들기 (1) 
		for(int j=0; j<n-len; j++) combi.push_back(1); //조합 만들기 (2)
		do
		{
			group[0].clear(); group[1].clear(); //컨테이너 
			sum = vector<int>(2, 0);            //초기화

			for(int i=0; i<n; i++) //그룹에 맞게 컨테이너에 넣어줌
				group[combi[i]].push_back(i+1);
			for(int i=0; i<2; i++) //각 그룹에서 BFS 
				sum[i] = BFS(group[i][0], i);

			if(sum[0]==-1 || sum[1]==-1) continue; //만약 그룹의 요소 중 하나가 떨어져있다면 continue
			ans = min(ans, abs(sum[0]-sum[1])); //정답 갱신
		}while(next_permutation(combi.begin(), combi.end())); //조합 만들기 (3)
	}
	cout<<(ans == INF ? -1 : ans)<<'\n'; //정답 출력

	return 0;
}
