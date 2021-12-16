#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int f, s, g, ud[2], ans;
vector<int> visited;

int BFS()
{
	queue<int> q;
	
	q.push(s);
	visited[s]=1;
	
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		
		for(int i=0; i<2; i++)
		{
			int next = curr + ud[i];
			
			if(next < 1 || next > f) continue;
			if(visited[next]) continue;
			
			q.push(next);
			visited[next]=visited[curr]+1;
		}
	}
	return visited[g];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>f>>s>>g>>ud[0]>>ud[1]; ud[1]*=-1;
	visited.resize(f+1, false);
	
	BFS();
	
	if(visited[g])
		cout<<visited[g]-1<<'\n';
	else
		cout<<"use the stairs\n";	
	
	return 0;
} 
