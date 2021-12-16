#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define A first
#define B second
using namespace std;

typedef pair<int, int> P;

int n;
vector<int> degree;
vector<vector<P> > adj;

int GetAnswer(int start)
{
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1)
	{
		cin>>n;
		if(!n) break;

		adj.resize(n);
		degree.resize(n, 0);
		for(int i=0; i<n-1; i++)
		{
			int u, v, w;
			cin>>u>>v>>w;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
			degree[u]++; degree[v]++;
		}

		vector<int> start;
		int st_degree=0;
		for(int i=0; i<n; i++)
		{
			if(degree[i] < st_degree) continue;
			else if(degree[i] == st_degree) start.push_back(i);
			else
			{
				st_degree = degree[i];
				start.clear();
				start.push_back(i);
			}
		}

		int ans = 0;
		for(auto &s : start)
			ans = min(ans, GetAnswer(s));
		
		cout<<ans<<'\n';

		adj.clear();
		degree.clear();
	}




	return 0;
}
