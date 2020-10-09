#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <utility>
using namespace std;

typedef pair<int, string> P;

bool visited[10000];

void BFS(int start, int end)
{
	queue<P> q;
	q.push({start, ""});
	visited[start] = true;

	while(!q.empty())
	{
		P curr = q.front();
		q.pop();

		if(curr.first == end)
		{
			cout<<curr.second<<'\n';
			return;
		}

		int next; int val = curr.first;

		next = (val*2)%10000;
		if(!visited[next]) 
		{
			visited[next]=true;
			q.push({next, curr.second + 'D'});
		}

		next = (val-1)<0 ? 9999 : val-1;
		if(!visited[next]) 
		{
			visited[next]=true;
			q.push({next, curr.second + 'S'});
		}

		next = (val%1000)*10+val/1000;
		if(!visited[next]) 
		{
			visited[next]=true;
			q.push({next, curr.second + 'L'});
		}

		next = (val/10)+(val%10)*1000;
		if(!visited[next]) 
		{
			visited[next]=true;
			q.push({next, curr.second + 'R'});
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, a, b; cin>>t;

	while(t--)
	{
		memset(visited, false, sizeof(visited));

		cin>>a>>b;

		BFS(a, b);
	}

	return 0;
}
