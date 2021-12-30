#include <bits/stdc++.h>
using namespace std;
const int INF = 2147000000;

int n, m, ans = INF;
vector<int> p, adj[11];
vector<int> combi, group[2], sum;

int BFS(int start, const bool type)
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
			if(combi[next-1] != type) continue;

			q.push(next);
			ret += p[next];
			visited[next] = true;
		}
	}
	
	for(auto &p : group[type])
		if(!visited[p]) ret = -1;

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

	int cnt = 0;
	for(int len=1; len<=n/2; len++)
	{	
		combi.assign(len, 0);
		for(int j=0; j<n-len; j++)
			combi.push_back(1);
		do
		{
			group[0].clear(); group[1].clear();
			sum = vector<int>(2, 0);

			for(int i=0; i<n; i++)
				group[combi[i]].push_back(i+1);
			for(int i=0; i<2; i++)
				sum[i] = BFS(group[i][0], i);

			if(sum[0]==-1 || sum[1]==-1) continue;

			ans = min(ans, abs(sum[0]-sum[1]));

		}while(next_permutation(combi.begin(), combi.end()));

	}
	
	cout<<(ans == INF ? -1 : ans)<<'\n';

	return 0;
}
