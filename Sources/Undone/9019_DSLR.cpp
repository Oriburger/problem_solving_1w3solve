#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>
using namespace std;

typedef pair<int, string> P;

vector<bool> visited;

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

		P next; int val = curr.first;
		for(int i=0; i<4; i++)
		{
			if(i==0) next = {val*2 > 9999 ? val*2%10000 : val*2, curr.second + 'D'};
			else if(i==1) next = {val-1<=0 ? 9999 : val-1, curr.second + 'S'};
			else if(i==2) next = {(val-(val/1000)*1000)*10 + val/1000, curr.second + 'L'};
			else next = {val/10+val%10*1000, curr.second + 'R'};
			
			if(!visited[next.first])
			{
				visited[next.first]=true;
				q.push(next);
			}			
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin>>t;

	while(t--)
	{
		int a, b;
		cin>>a>>b;

		BFS(a, b);

		visited.clear();
		visited.resize(10001, false);
	}

	return 0;
}
