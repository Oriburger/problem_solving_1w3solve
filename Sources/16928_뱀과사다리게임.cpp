#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int n, m, ans;
vector<vector<int> > adj;
bool visited[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	adj.resize(101);
	for(int i=0; i<n+m; i++)
	{
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
	}

	queue<P> q;
	q.push({1, 0});
	visited[1]=true;

	while(!q.empty())
	{
		int cur_idx = q.front().first;
		int cur_mv = q.front().second;
		q.pop();

		if(cur_idx == 100)
		{
			ans = cur_mv;
			break;
		}

		for(int i=1; i<=6; i++)
		{
			int next = cur_idx+i;
			if(next > 100) continue;

			if(adj[next].size())
				next = adj[next][0];
			
			if(visited[next]) continue;
			
			visited[next] = true;
			q.push({next, cur_mv + 1});
		}
	}

	cout<<ans<<'\n';
	
	return 0;
}
