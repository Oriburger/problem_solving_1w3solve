#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

vector<P> adj[10001]; //인접 리스트!
int n, m, lo=1, hi=1;
int st, fin, ans;

bool BFS(const int weight) //한 번에 weight만큼 옮길 경우, 도착 지점까지의 이동이 가능한가?
{
	queue<int> q; //BFS 위한 que
	vector<bool> visited(n+1, false); //중복 탐색 방지

	q.push(st);
	visited[st]=true;
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();

		if(curr==fin) return true; //도착 지점까지 안전하게 갈 수 있다면 true

		for(const auto &next : adj[curr]) //curr에서 나가는 간선 탐색
		{
			if(visited[next.first]==true) continue; //이미 방문한 정점은 pass
			if(next.second < weight) continue; //중량제한으로 인해 가지 못하면 pass

			q.push(next.first); 
			visited[next.first] = true;
		}
	}
	return false; //도착 지점까지 갈 수 없으니 false 반환
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m; 
	for(int i=0; i<m; i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		hi = max(hi, w);
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	cin>>st>>fin;

	while(lo<=hi)
	{
		int mid = (lo+hi)/2;

		if(BFS(mid)) //mid 무게는 이동이 가능하다
		{
			ans = mid; //그러면 정답을 갱신하고
			lo = mid + 1; //mid 보다 더 큰 구간을 탐색
		}
		else hi = mid - 1; //불가능하면, mid모다 더 낮은 구간을 탐색
	}

	cout<<ans<<'\n';

	return 0;
}
