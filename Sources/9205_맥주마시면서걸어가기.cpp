#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Pos { int x; int y; };

int t, n;
Pos st, fin;
vector<Pos> p;
vector<bool> visited;

int GetDist(Pos p1, Pos p2)
{
	return abs(p1.x-p2.x) + abs(p1.y-p2.y);
}

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	
	visited[start]=true;
	
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		
		for(int next=1; next<=n+1; next++)
		{
			if(visited[next]) continue;
			if(GetDist(p[curr], p[next])<=1000)
			{
				q.push(next);
				visited[next]=true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		visited.assign(n+2, false);
		for(int i=0; i<n+2; i++)
		{
			int ix, iy; //input
			cin>>ix>>iy;
			p.push_back({ix, iy});
		}
		
		BFS(0);
		
		if(visited[n+1]==true)
			cout<<"happy\n";
		else
			cout<<"sad\n";
		visited.clear();
		p.clear();
	}
	
	return 0;
}
