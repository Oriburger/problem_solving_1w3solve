#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

vector<P> adj[10001];
int n, m, lo=1, hi=1;
int st, fin, ans;

bool BFS(const int limit)
{
	queue<int> q;
	vector<bool> visited(n+1, false);

	q.push(st);
	visited[st]=true;
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();

		if(curr==fin) return true;

		for(const auto &next : adj[curr])
		{
			if(visited[next.first]==true) continue;
			if(next.second < limit) continue;

			q.push(next.first);
			visited[next.first] = true;
		}
	}
	return false;
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

		if(BFS(mid)) //가능하다면
		{
			ans = mid; //정답을 갱신하고
			lo = mid + 1; //더 높은 구간을 탐색
		}
		else hi = mid - 1; //불가능하면, 더 낮은 구간을 탐색
	}

	cout<<ans<<'\n';

	return 0;
}
