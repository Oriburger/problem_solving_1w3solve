#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


int n, rm, root;
vector<vector<int> > adj;
vector<bool> visited;

int BFS(int start)
{
	if(visited[start]) return 0;

	int ret=0;
	queue<int> q;
	q.push(start);
	visited[start]=true;

	while(!q.empty())
	{
		int curr = q.front();
		q.pop();

		int cnt=0;
		for(int next : adj[curr])
		{
			if(!visited[next])
			{
				visited[next]=true;
				q.push(next);
				cnt++;
			}
		}
		if(cnt==0) ret++;
	}

	return ret;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	
	adj.resize(n);
	visited.resize(n, false);

	for(int i=0; i<n; i++)
	{
		int p; cin>>p;
		if(p==-1)
		{
			root=i;
			continue;
		}
		adj[p].push_back(i);
	}
	cin>>rm;
	
	BFS(rm);
	cout<<BFS(root)<<'\n';
	
	return 0;
}
