#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int n;
vector<vector<int> > adj;
vector<bool> visited;

int GetAnswer(int start)
{
	int ret=0;
	queue<pair<int,int> > q;
	q.push({start, 0});
	visited[start]=true;

	while(!q.empty())
	{
		pair<int,int> curr = q.front();
		q.pop();

		for(int next : adj[curr.first])
		{
			if(!visited[next] && curr.second + 1 <= 2)
			{
				q.push({next, curr.second+1});
				visited[next]=true;
				ret++;
			}
		}
	}
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	adj.resize(n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			char input; cin>>input;
			if(input=='Y')
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
			else continue;
		}
	}
	
	int answer=0;

	for(int i=0; i<n; i++)
	{
		visited.resize(n, 0);
		answer = max(answer, GetAnswer(i));
		visited.clear();
	}
	cout<<answer<<'\n';

	return 0;
}
