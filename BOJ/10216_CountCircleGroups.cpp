#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Pos { int y; int x; int r;};

int t, n, answer;
vector<vector<int> > adj;
vector<bool> visited;
vector<Pos> pos_arr;

inline bool IsSameArea(const Pos& p, const Pos& q)
{
	if(pow(abs(p.y-q.y), 2) + pow(abs(p.x-q.x), 2) <= pow(p.r+q.r, 2)) 
		return true;
	return false;
}

void DFS(int curr)
{
	visited[curr] = true;
	
	for(auto &next : adj[curr])
	{
		if(visited[next]) continue;
		DFS(next);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		answer = 0;
		adj = vector<vector<int> >(n);
		pos_arr = vector<Pos>(n);
		visited = vector<bool>(n, false);
		
		for(int i=0; i<n; i++)
		{
			int x, y, r;
			cin>>x>>y>>r;
			pos_arr[i] = {x, y, r};
		}
			
		for(int i=0; i<n-1; i++)
			for(int j=i+1; j<n; j++)
			{
				if(!IsSameArea(pos_arr[i], pos_arr[j])) continue;
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
			
		for(int i=0; i<n; i++)
		{
			if(visited[i]) continue;
			answer++;
			DFS(i);
		}
		
		cout<<answer<<'\n';
	}
	
	return 0;
}
